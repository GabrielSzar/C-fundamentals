#include "product.h"
#ifndef TYPES_H
#define TYPES_H
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
#endif
