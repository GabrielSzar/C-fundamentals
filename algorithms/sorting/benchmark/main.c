#include "../include/benchmark.h"
#include "../include/sort.h"
#include "../include/terminal.h"
#include <bits/types/sigset_t.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>
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
static char* OPTIONS_LIST[] = {
    "Change State",
    "bubble_sort",
    "heap_sort",
    "insertion_sort",
    "merge_sort",
    "quick_sort",
    "selection_sort",
    "tim_sort",
};
int OPTIONS_LIST_LENGTH = sizeof(OPTIONS_LIST) / sizeof(OPTIONS_LIST[0]);
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
static void chage_state(State* s)
{
    *s = *s == INVERTED ? 0 : *s + 1;
}
int main(void)
{
    if (copy_atributes() == -1) {
        perror("Error getting terminal attributes");
        exit(EXIT_FAILURE);
    }
    if (enable_cbreak_mode() == -1) {
        perror("Error enabling cbreak mode");
        exit(EXIT_FAILURE);
    }
    atexit(disable_cbreak_mode);
    enable_sig_handler();
    Product* base = malloc(sizeof(Product) * SIZE);
    Product* work = malloc(sizeof(Product) * SIZE);
    Product** work_ptrs = malloc(sizeof(Product*) * SIZE);
    State state = SHUFFLED;

    populate_products(base, SIZE);
    return_to_state(state, base, work, work_ptrs, SIZE);

    while (1) {
        print_header(state);
        print_menu(OPTIONS_LIST, OPTIONS_LIST_LENGTH);
        int choice = read_int();
        if (choice == 0) {
            chage_state(&state);
            continue;
        }
        if (choice == -2) {
            break;
        }
        if (choice < 0 || choice >= OPTIONS_LIST_LENGTH) {
            continue;
        }
        BenchResult result = benchmark(ALGORITHMS[choice - 1], base, work, work_ptrs, SIZE, state);
        print_result(result, OPTIONS_LIST[choice], state);
    }
    free(base);
    free(work);
    free(work_ptrs);
}
