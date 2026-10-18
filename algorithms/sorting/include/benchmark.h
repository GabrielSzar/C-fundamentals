#ifndef DATASET_H
#define DATASET_H
#include "../include/sort.h"
#include <stdint.h>
typedef void (*sort_value_fn)(Product arr[], int n);
typedef void (*sort_ptrs_fn)(Product* arr[], int n);
typedef struct {
    sort_value_fn value;
    sort_ptrs_fn ptrs;
} Algorithm;
typedef enum {
    SORTED,
    SHUFFLED,
    INVERTED
} State;
void populate_products(Product arr[], int n);
int resultfile(Product arr[]);
void print_menu(char* options[], int n, State state);
void benchmark(Algorithm Selected_Algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state);
void return_to_state(State state, Product base[], Product work[], Product* work_ptrs[], int n);
#endif
