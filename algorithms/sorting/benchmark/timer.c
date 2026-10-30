#include "../include/benchmark.h"
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static char* warning;
static size_t warning_size = 0;
static volatile sig_atomic_t first = 0;
static volatile sig_atomic_t active = 0;
static volatile sig_atomic_t times = 0;
static struct itimerval timer = { 0 };

static void print_wait_screen(int sig)
{
    if (!active) {
        return;
    }
    if (first == 0) {
        clear();
        write(STDOUT_FILENO, warning, warning_size);
        first = 1;
    }
    if (times < 3) {
        write(STDOUT_FILENO, ".", 1);
        times += 1;
    } else {
        write(STDOUT_FILENO, "\b \b\b \b\b \b", 9);
        times = 0;
    }
}
void activate_timer(char* algo)
{
    asprintf(&warning, "Benchmarking %s, this may take a while", algo);
    warning_size = strlen(warning);
    struct sigaction action = { 0 };
    action.sa_handler = print_wait_screen;
    action.sa_flags = SA_RESTART;
    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);
    timer.it_interval.tv_usec = 500000;
    timer.it_value.tv_usec = 500000;
    setitimer(ITIMER_REAL, &timer, NULL);
    active = 1;
}
void desactivate_timer(void)
{
    first = 0;
    active = 0;
    times = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_value.tv_sec = 0;
    setitimer(ITIMER_REAL, &timer, NULL);
    free(warning);
}
