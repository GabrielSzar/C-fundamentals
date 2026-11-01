#include "../include/terminal.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

static struct termios t_attr = { 0 };

void restore_terminal(void)
{
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &t_attr) == -1) {
        write(STDERR_FILENO, "Error disabling cbreak mode, type reset and Ctrl + J to return to default", 73);
    }
    write(STDOUT_FILENO, "\033[?25h", 6); // show cursor
}
int copy_attributes(void)
{
    return tcgetattr(STDIN_FILENO, &t_attr);
}
int enable_cbreak_mode(void)
{
    write(STDOUT_FILENO, "\033[?25l", 6); // hide cursor
    struct termios work = t_attr;
    work.c_cc[VTIME] = 0;
    work.c_cc[VMIN] = 1;
    work.c_lflag &= ~(ECHO | ICANON);
    return tcsetattr(STDIN_FILENO, TCSAFLUSH, &work);
}
void disable_cbreak_mode(void)
{
    restore_terminal();
}
void handler_dis_cbreak(int sig)
{
    restore_terminal();
    _exit(128 + sig);
}
void handler_SIGSEGV(int sig)
{
    (void)sig;
    restore_terminal();
    signal(SIGSEGV, SIG_DFL);
    raise(SIGSEGV);
}
void enable_sig_handler(void)
{
    struct sigaction action_SIGSEGV = { 0 };
    struct sigaction action = { 0 };
    action.sa_handler = handler_dis_cbreak;
    action_SIGSEGV.sa_handler = handler_SIGSEGV;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask, SIGINT);
    sigaddset(&action.sa_mask, SIGTERM);
    sigaddset(&action.sa_mask, SIGQUIT);
    sigaddset(&action.sa_mask, SIGALRM);
    action_SIGSEGV.sa_flags = SA_NODEFER;

    if (sigaction(SIGINT, &action, NULL) == -1
        || sigaction(SIGTERM, &action, NULL) == -1
        || sigaction(SIGQUIT, &action, NULL) == -1
        || sigaction(SIGSEGV, &action_SIGSEGV, NULL)) {
        perror("Error enabling signal handler");
        exit(EXIT_FAILURE);
    }
}
Keys read_input(void)
{
    char buffer[4] = { 0 };
    tcflush(STDIN_FILENO, TCIFLUSH);
    ssize_t n_bytes = read(STDIN_FILENO, buffer, sizeof(buffer));

    if (n_bytes <= 0) {
        return KEY_ERROR;
    }
    if ((buffer[0] == 'q' || buffer[0] == 'Q') && n_bytes == 1) {
        return KEY_QUIT;
    }
    if ((buffer[0] == '\n' || buffer[0] == '\r') && n_bytes == 1) {
        return KEY_ENTER;
    }
    if (buffer[0] != '\033' || buffer[1] != '[') {
        return KEY_OTHER;
    }
    if (buffer[2] == 'A') {
        return KEY_UP;
    }
    if (buffer[2] == 'B') {
        return KEY_DOWN;
    }
    return KEY_OTHER;
}
