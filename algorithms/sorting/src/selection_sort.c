#include "../include/sort.h"

void selection_sort_value(Product arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (arr[j].price < arr[min].price) {
                min = j;
            }
        }
        if (min != i) {
            Product temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void selection_sort_ptrs(Product* arr[], int n)
{
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (arr[j]->price < arr[min]->price) {
                min = j;
            }
        }
        Product* temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
