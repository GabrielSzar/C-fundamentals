#include "../include/benchmark.h"
#include "../include/terminal.h"
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

static volatile sig_atomic_t active = 0;
static volatile sig_atomic_t times = 0;
static struct itimerval timer = { 0 };
static void activate_timer(void)
{
    timer.it_interval.tv_usec = 300000;
    timer.it_value.tv_usec = 500000;
    setitimer(ITIMER_REAL, &timer, NULL);
    active = 1;
}
void desactivate_timer(void)
{
    active = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_usec = 0;
    timer.it_value.tv_sec = 0;
}

const char* get_state_name(State s)
{
    switch (s) {
    case SORTED:
        return "SORTED";
    case SHUFFLED:
        return "SHUFFLED";
    case INVERTED:
        return "INVERTED";
    default:
        return "UNKNOW";
    }
}
void clear(void)
{
    char* clear = "\033[H\033[J";
    write(STDOUT_FILENO, clear, strlen(clear));
}

void print_header(State state)
{
    clear();
    printf("========== Sorting Algorithms Benchmark ==========\n");
    printf("Array State:%s\n", get_state_name(state));
    printf("Select a sorting algorithm to benchmark:\n");
}
void print_menu(char* options[], int n, int selected)
{
    for (int i = 0; i < n; i++) {
        if (i == selected) {
            printf("\033[1;32m > %s\033[0m\n", options[i]);
        } else {
            printf("   %s\n", options[i]);
        }
    }
    fflush(stdout);
    printf("[Up Arrow | Down Arrow] Navigation [Enter] Select [Q] Quit\n");
}
void print_result(BenchResult result, char* algo, State state)
{
    clear();
    printf("In the State: %s the algorithm %s took:\n", get_state_name(state), algo);
    printf("Struct with median in %i tests of: %f seconds\n", result.value_runs, result.value_s);
    printf("Pointers with median in %i tests of: %f seconds\n", result.ptrs_runs, result.ptrs_s);
    printf("Difference between Struct and Pointers:%f seconds\n", fabs(result.value_s - result.ptrs_s));
    printf("Press Any key to continue ...\n");
    read_input();
}
void print_dots(int sig)
{
    if (active && times < 3) {
        write(STDOUT_FILENO, ".", 1);
        times += 1;
    } else {
        write(STDOUT_FILENO, "\b \b\b \b\b \b", 10);
        times = 0;
    }
}
void wait_screen(char* algo)
{
    clear();
    write(STDOUT_FILENO, "Benchmarking ", strlen("Benchmarking "));
    write(STDOUT_FILENO, algo, strlen(algo));
    write(STDOUT_FILENO, ", this may take a while", strlen(", this may take a while"));
    struct sigaction action = { 0 };
    action.sa_handler = print_dots;
    action.sa_flags = SA_RESTART;
    sigemptyset(&action.sa_mask);
    sigaction(SIGALRM, &action, NULL);
    activate_timer();
}
