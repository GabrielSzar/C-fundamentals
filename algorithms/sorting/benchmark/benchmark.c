#include "../include/benchmark.h"
#include "../include/sort.h"
#include <stdlib.h>
#include <time.h>
#define NUM_OF_TESTS 5
#define SLOW_RUN_SECONDS 1
static double now_seconds(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (double)t.tv_sec + (double)t.tv_nsec / 1e9;
}
static int comparator(const void* a, const void* b)
{
    double double_a = *(const double*)a;
    double double_b = *(const double*)b;

    if (double_a < double_b)
        return -1;
    if (double_a > double_b)
        return 1;
    return 0;
}
static double median(double nums[], int n)
{
    qsort(nums, n, sizeof(double), comparator);
    int half = n / 2;
    return n % 2 == 0 ? (double)(nums[half] + nums[half - 1]) / 2 : nums[half];
}

BenchResult benchmark(Algorithm algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state)
{
    BenchResult result = { 0 };
    double times[NUM_OF_TESTS];
    double t = 0.0;
    int runs = 0;
    while (runs < NUM_OF_TESTS) {
        return_to_state(state, base, work, work_ptrs, n);
        t = now_seconds();
        algorithm.value(work, n);
        times[runs++] = now_seconds() - t;
        if (times[runs - 1] > SLOW_RUN_SECONDS) {
            break;
        }
    }
    result.value_s = median(times, runs);
    result.value_runs = runs;
    runs = 0;
    while (runs < NUM_OF_TESTS) {
        return_to_state(state, base, work, work_ptrs, n);
        t = now_seconds();
        algorithm.ptrs(work_ptrs, n);
        times[runs++] = now_seconds() - t;
        if (times[runs - 1] > SLOW_RUN_SECONDS) {
            break;
        }
    }
    result.ptrs_s = median(times, runs);
    result.ptrs_runs = runs;
    return_to_state(state, base, work, work_ptrs, n);
    return result;
}
void return_to_state(State state, Product base[], Product work[], Product* work_ptrs[], int n)
{
    for (int i = 0; i < n; i++) {
        work[i] = base[i];
        work_ptrs[i] = &base[i];
    }
    switch (state) {
    case SORTED:
        merge_sort_value(work, n);
        merge_sort_ptrs(work_ptrs, n);
        break;
    case INVERTED:
        merge_sort_value(work, n);
        merge_sort_ptrs(work_ptrs, n);
        reverse_value(work, n);
        reverse_ptrs(work_ptrs, n);
        break;
    case SHUFFLED:
        // base is already shuffled, it allways copies so no need to shuffle again
        break;
    }
}
