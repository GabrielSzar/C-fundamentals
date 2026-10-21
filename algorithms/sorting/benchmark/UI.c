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
    printf("\n========== Sorting Algorithms Benchmark ==========\n");
    printf("Array State:%s\n", get_state_name(state));
    printf("Select a sorting algorithm to benchmark:\n");
    for (int i = 0; i < n; i++) {
        printf("%i. %s\n", i, options[i]);
    }
    printf("Chose: ");
}
void print_result(BenchResult result, char* algo, State state)
{
    printf("In the State: %s the algorithm %s took:\n", get_state_name(state), algo);
    printf("Value: %f seconds\n", result.value_s);
    printf("Pointers: %f seconds\n", result.ptrs_s);
}
