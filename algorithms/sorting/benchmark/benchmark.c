#include "../include/benchmark.h"
#include "../include/sort.h"

void benchmark(Algorithm Selected_Algorithm, Product base[], Product work[], Product* work_ptrs[], int n, State state)
{
    // fazer o calulo da media, como retornar 2 valores ao mesmo tempo?
    // cronometrar
    Selected_Algorithm.value(work, n);
    Selected_Algorithm.ptrs(work_ptrs, n);
    return_to_state(state, base, work, work_ptrs, n);
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
