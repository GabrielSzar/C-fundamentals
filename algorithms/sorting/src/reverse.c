#include "../include/sort.h"

void reverse_value(Product arr[], int n)
{
    for (int i = 0; i < n / 2; i++) {
        Product temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
void reverse_ptrs(Product* arr[], int n)
{
    for (int i = 0; i < n / 2; i++) {
        Product* temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
