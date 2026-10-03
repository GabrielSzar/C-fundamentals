#ifndef SORT_H
#define SORT_H

typedef struct {
    char nome[64];
    double preco;
} Product;
// int n = size of array
void bubble_sort_value(Product arr[], int n); // Best Cases
void selection_sort_value(Product arr[], int n);
void merge_sort_value(Product arr[], int n);
void quick_sort_value(Product arr[], int n);
void heap_sort_value(Product arr[], int n);

// Pointer bc there is diff between
// sorting small values like pointers(8 bytes)
// For a struct that in this case,
// 1 byte char times 64 + 8 bytes double
// that equals to 72 bytes per item in array
void bubble_sort_prt(Product* arr[], int n);
void selection_sort_prt(Product* arr[], int n);
void merge_sort_prt(Product* arr[], int n);
void quick_sort_prt(Product* arr[], int n);
void heap_sort_prt(Product* arr[], int n);

void shuffle(Product* arr[], int n); // Avg Case
void reverse(Product* arr[], int n); // Worst Case

#endif
