#include "product.h"
#include "types.h"
#ifndef BENCHMARK_H
#define BENCHMARK_H
BenchResult benchmark(Algorithm Selected_Algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state);
void return_to_state(State state, Product base[], Product work[], Product* work_ptrs[], int n);
void populate_products(Product arr[], int n);
int resultfile(Product arr[], int n);
#endif
