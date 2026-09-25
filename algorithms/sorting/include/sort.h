#ifndef SORT_H
#define SORT_H

typedef struct {
    char nome[64];
    double preco;
} Product;

void bubble_sort_value(Product arr[], int n); // Best Cases
void selection_sort_value(Product arr[], int n);
void merge_sort_value(Product arr[], int n);
void quick_sort_value(Product arr[], int n);
void heap_sort_value(Product arr[], int n);

void bubble_sort_prt(Product arr[], int n);
void selection_sort_prt(Product arr[], int n);
void merge_sort_prt(Product arr[], int n);
void quick_sort_prt(Product arr[], int n);
void heap_sort_prt(Product arr[], int n);

void shuffle(Product arr[], int n); // Avg Case
void reverse(Product arr[], int n); // Worst Case

#endif
