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
int main(void)
{
    if (tcgetattr(STDIN_FILENO, &t_attr) == -1) {
        perror("Error getting terminal attributes");
        exit(EXIT_FAILURE);
    }
    if (enable_cbreak_mode() == -1) {
        perror("Error enabling cbreak mode");
        exit(EXIT_FAILURE);
    }
    atexit(disable_cbreak_mode);
    enable_sig_handler();
    printf("PID: %i\n", getpid());

    char buffer[16];
    char* linha = "\n---------------------------------\n";
    ssize_t n_bytes = 0;

    while (1) {
        n_bytes = read(STDIN_FILENO, buffer, sizeof(buffer));
        if (n_bytes == -1) {
            perror("erro ao ler");
            exit(EXIT_FAILURE);
        }
        printf("Retorno n_bytes: %zd\n", n_bytes);
        for (int i = 0; i < n_bytes; i++) {
            printf("%i byte: %i ", i, buffer[i]);
        }
        // fwrite(buffer, 1, n_bytes, stdout);
        printf("%s", linha);
        if (buffer[0] == 'q') {
            return 0;
        }
    }
}
