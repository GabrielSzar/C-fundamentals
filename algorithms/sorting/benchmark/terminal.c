#include <bits/types/sigset_t.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

static struct termios t_attr = { 0 };

int enable_cbreak_mode(void)
{
    struct termios work = t_attr;
    work.c_cc[VTIME] = 0;
    work.c_cc[VMIN] = 1;
    work.c_lflag &= ~(ECHO | ICANON);
    return tcsetattr(STDIN_FILENO, TCSAFLUSH, &work);
}
int restore_terminal(void)
{
    return tcsetattr(STDIN_FILENO, TCSAFLUSH, &t_attr);
}
void disable_cbreak_mode(void)
{
    if (restore_terminal() == -1) {
        perror("Error disabling cbreak mode, type reset and Ctrl + J to return to default");
    }
}
void handler_dis_cbreak(int sig)
{
    restore_terminal();
    _exit(128 + sig);
}
void enable_sig_handler(void)
{
    struct sigaction action = { 0 };
    action.sa_handler = handler_dis_cbreak;
    sigemptyset(&action.sa_mask);
    sigaddset(&action.sa_mask, SIGINT);
    sigaddset(&action.sa_mask, SIGTERM);
    sigaddset(&action.sa_mask, SIGQUIT);

    if (sigaction(SIGINT, &action, NULL) == -1 || sigaction(SIGTERM, &action, NULL) == -1 || sigaction(SIGQUIT, &action, NULL) == -1) {
        perror("Error enabling signal handler");
        exit(EXIT_FAILURE);
    }
}
