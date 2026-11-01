#include "../include/terminal.h"
#include "../include/types.h"
#include "../include/wait_screen.h"
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

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
        return "UNKNOWN";
    }
}
void clear(void)
{
    write(STDOUT_FILENO, "\033[H\033[J", 6);
}

void print_header(State state)
{
    clear();
    printf("========== Sorting Algorithms Benchmark ==========\n");
    printf("Array State: %s\n", get_state_name(state));
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
    deactivate_timer();
    clear();
    printf("In the State: %s the algorithm %s took:\n", get_state_name(state), algo);
    printf("Struct with median in %d tests of: %f seconds\n", result.value_runs, result.value_s);
    printf("Pointers with median in %d tests of: %f seconds\n", result.ptrs_runs, result.ptrs_s);
    printf("Difference between Struct and Pointers: %f seconds\n", fabs(result.value_s - result.ptrs_s));
    printf("Press any key to continue ...\n");
    read_input();
}
void wait_screen(char* algo)
{
    activate_timer(algo);
}
