#include "../include/product.h"
// Doesnt work because segfault of stack,
//  it is limited at 8MB the Product Struct
//  takes 78 bytes, the array has 100k of those
//  78 * 100k = 7.8MB, + other variables,
//  it passes the 8MB limit of the stack
//  chose to use the 3-way particioning
//  beacause it is the fastest, and the
//  more optmized version of quicksort
void quick_sort_value_lomuto(Product arr[], int low, int high)
{
    if (low >= high) {
        return;
    }
    Product pivot = arr[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (arr[i].price <= pivot.price) {
            Product temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            left += 1;
        }
    }
    Product temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;

    quick_sort_value_lomuto(arr, low, left - 1);
    quick_sort_value_lomuto(arr, left + 1, high);
}

void quick_sort_ptrs_lomuto(Product* arr[], int low, int high)
{
    if (low >= high) {
        return;
    }
    Product* pivot = arr[high];
    int left = low;
    for (int i = low; i < high; i++) {
        if (arr[i]->price <= pivot->price) {
            Product* temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            left += 1;
        }
    }
    Product* temp = arr[high];
    arr[high] = arr[left];
    arr[left] = temp;

    quick_sort_ptrs_lomuto(arr, low, left - 1);
    quick_sort_ptrs_lomuto(arr, left + 1, high);
}
