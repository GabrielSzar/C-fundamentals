#include "../include/benchmark.h"
#include "../include/sort.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100000
static const Algorithm ALGORITHMS[] = {
    { bubble_sort_value, bubble_sort_ptrs },
    { heap_sort_value, heap_sort_ptrs },
    { insertion_sort_value, insertion_sort_ptrs },
    { merge_sort_value, merge_sort_ptrs },
    { quick_sort_value, quick_sort_ptrs },
    { selection_sort_value, selection_sort_ptrs },
    { tim_sort_value, tim_sort_ptrs }
};
static char* ALGORITHMS_NAME[] = {
    "bubble_sort",
    "heap_sort",
    "insertion_sort",
    "merge_sort",
    "quick_sort",
    "selection_sort",
    "tim_sort",
};
int ALGORITHMS_COUNT = sizeof(ALGORITHMS) / sizeof(Algorithm);

static int read_int(void)
{
    char line[32];
    if (fgets(line, sizeof line, stdin) == NULL)
        return -2;
    char* end;
    long v = strtol(line, &end, 10);
    if (end == line || (*end != '\n' && *end != '\0'))
        return -1;
    return (int)v;
}
int main(void)
{
    Product* base = malloc(sizeof(Product) * SIZE);
    Product* work = malloc(sizeof(Product) * SIZE);
    Product** work_ptrs = malloc(sizeof(Product*) * SIZE);
    State state = SHUFFLED;

    populate_products(base, SIZE);
    return_to_state(state, base, work, work_ptrs, SIZE);
    while (1) {
        print_menu(ALGORITHMS_NAME, ALGORITHMS_COUNT, state);
        int choice = read_int();

        benchmark(ALGORITHMS[choice], base, work, work_ptrs, SIZE, state);
        // benchmark retorna o valor do tempo, e aqui chama uma função de mostrar resultado
        // ele mostra e pergunta se quer escrever o resuldato em um arquivo, ai repete o loop todo
    }
    free(base);
    free(work);
    free(work_ptrs);
}
