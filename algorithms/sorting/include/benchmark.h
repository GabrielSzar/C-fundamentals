#include "../include/sort.h"

#ifndef BENCHMARK_H
#define BENCHMARK_H
typedef void (*sort_value_fn)(Product arr[], int n);
typedef void (*sort_ptrs_fn)(Product* arr[], int n);
typedef struct {
    sort_value_fn value;
    sort_ptrs_fn ptrs;
} Algorithm;
typedef struct {
    double value_s;
    double ptrs_s;
    int value_runs;
    int ptrs_runs;
} BenchResult;
typedef enum {
    SORTED,
    SHUFFLED,
    INVERTED
} State;
BenchResult benchmark(Algorithm Selected_Algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state);
void return_to_state(State state, Product base[], Product work[], Product* work_ptrs[], int n);
void populate_products(Product arr[], int n);

void print_result(BenchResult result, char* algo, State state);
void print_menu(char* options[], int n, int selected);
void print_header(State state);
void wait_screen(char* algo);
void desactivate_timer(void);

int resultfile(Product arr[], int n);
#endif
