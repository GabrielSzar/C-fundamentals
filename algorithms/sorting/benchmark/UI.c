#include "../include/benchmark.h"
#include <math.h>
#include <stdio.h>
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
void print_header(State state)
{
    printf("\033[H\033[J");
    printf("\n========== Sorting Algorithms Benchmark ==========\n");
    printf("Array State:%s\n", get_state_name(state));
    printf("Select a sorting algorithm to benchmark:\n");
}
void print_menu(char* options[], int n)
{

    for (int i = 0; i < n; i++) {
        printf("%i. %s\n", i, options[i]);
    }
    printf("Chose: ");
}
void print_result(BenchResult result, char* algo, State state)
{
    printf("\033[H\033[J");
    printf("In the State: %s the algorithm %s took:\n", get_state_name(state), algo);
    printf("Struct with median in %i tests of: %f seconds\n", result.value_runs, result.value_s);
    printf("Pointers with median in %i tests of: %f seconds\n", result.ptrs_runs, result.ptrs_s);
    printf("Difference between Struct and Pointers:%f seconds\n", fabs(result.value_s - result.ptrs_s));
    printf("Press Any key to continue ...");
    getchar();
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}
