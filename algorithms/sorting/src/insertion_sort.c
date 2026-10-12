#include "../include/sort.h"

void insertion_sort_value(Product arr[], int n)
{
    for (int i = 1; i < n; i++) {
        Product key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].price > key.price) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
void insertion_sort_ptrs(Product* arr[], int n)
{
    for (int i = 1; i < n; i++) {
        Product* key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j]->price > key->price) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
