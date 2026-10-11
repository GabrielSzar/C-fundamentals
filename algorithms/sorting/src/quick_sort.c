#include "../include/sort.h"

void quick_sort_value(Product arr[], int low, int high)
{
    if (low >= high) {
        return;
    }
    Product pivot = arr[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (arr[i].preco <= pivot.preco) {
            Product temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            left += 1;
        }
    }
    Product temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;

    quick_sort_value(arr, low, left - 1);
    quick_sort_value(arr, left + 1, high);
}

void quick_sort_ptrs(Product* arr[], int low, int high)
{
    if (low >= high) {
        return;
    }
    Product* pivot = arr[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (arr[i]->preco <= pivot->preco) {
            Product* temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            left += 1;
        }
    }
    Product* temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;

    quick_sort_ptrs(arr, low, left - 1);
    quick_sort_ptrs(arr, left + 1, high);
}
