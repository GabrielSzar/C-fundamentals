#include "../include/benchmark.h"
#include "../include/sort.h"
#include <time.h>

static double now_seconds(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + (double)t.tv_nsec / 1e9;
}
BenchResult benchmark(Algorithm algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state)
{
    return_to_state(state, base, work, work_ptrs, n);
    BenchResult result = { 0 };
    double t0 = now_seconds();
    algorithm.value(work, n);
    double t1 = now_seconds();
    result.value_s = t1 - t0;
    t0 = now_seconds();
    algorithm.ptrs(work_ptrs, n);
    t1 = now_seconds();
    result.ptrs_s = t1 - t0;
    return result;
}
void return_to_state(State state, Product base[], Product work[], Product* work_ptrs[], int n)
{
    switch (state) {
    case SORTED:
        merge_sort_value(work, n);
        merge_sort_ptrs(work_ptrs, n);
        break;
    case SHUFFLED:
        for (int i = 0; i < n; i++) {
            work[i] = base[i];
        }
        for (int i = 0; i < n; i++) {
            work_ptrs[i] = &base[i];
        }
        break;
    case INVERTED:
        merge_sort_value(work, n);
        merge_sort_ptrs(work_ptrs, n);
        reverse_value(work, n);
        reverse_ptrs(work_ptrs, n);
        break;
    }
}
