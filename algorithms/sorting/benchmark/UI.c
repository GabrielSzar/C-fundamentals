#include "../include/benchmark.h"
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
void print_menu(char* options[], int n, State state)
{
    printf("========== Sorting Algorithms Benchmark ==========\n");
    printf("Array State:%s\n", get_state_name(state));
    printf("Select a sorting algorithm to benchmark:\n");
    for (int i = 0; i < n; i++) {
        printf("%i. %s\n", i, options[i]);
    }
}
