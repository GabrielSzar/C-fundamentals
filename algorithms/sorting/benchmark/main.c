#include "../include/dataset.h"
#include "../include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000
typedef void (*sort_value_fn)(Product arr[], int n);
typedef void (*sort_ptrs_fn)(Product* arr[], int n);
typedef struct {
    const char* name;
    sort_value_fn value;
    sort_ptrs_fn ptrs;
} Algorithm;
static const Algorithm ALGORITHMS[] = {
    { "bubble_sort", bubble_sort_value, bubble_sort_ptrs },
    { "heap_sort", heap_sort_value, heap_sort_ptrs },
    { "insertion_sort", insertion_sort_value, insertion_sort_ptrs },
    { "merge_sort", merge_sort_value, merge_sort_ptrs },
    { "quick_sort", quick_sort_value, quick_sort_ptrs },
    { "selection_sort", selection_sort_value, selection_sort_ptrs },
    { "tim_sort", tim_sort_value, tim_sort_ptrs }
};
int main(void)
{
    Product* base = malloc(sizeof(Product) * SIZE);
    Product* work = malloc(sizeof(Product) * SIZE);
    Product** work_ptrs = malloc(sizeof(Product*) * SIZE);
    populate_products(base, SIZE);
    for (int i = 0; i < SIZE; i++) {
        work[i] = base[i];
    }
    for (int i = 0; i < SIZE; i++) {
        work_ptrs[i] = &base[i];
    }
    
    FILE* resultado = fopen("resultado.txt", "w");
    if (resultado == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        fprintf(resultado, "Index[%d] Name: %s | Price: %.00f\n", i, work_ptrs[i]->name, work_ptrs[i]->price);
    }
    free(base);
    free(work);
    fclose(resultado);
}
