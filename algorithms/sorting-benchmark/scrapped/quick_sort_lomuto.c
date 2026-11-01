#include "../include/product.h"
// using quicksort with lomuto implementation doesn't work
// if the array is sorted, it calls itself  around n times,
// n being the size of the array, in this case is 100k.
// Each call creates a new pivot and temp variables
// the Product struct takes up 72 bytes(char[64], double),
// so at each call it allocates more 144 bytes, the stack
// has a limit of 8MiB, at around 55k calls it passes the
// 8MiB limit of the stack, causing Segmentation fault
// (144 * 55k = 7_999_920)
// these numbers are only from the Product struct itself
// with -O0 it passes with around 37k calls
// with -O2 with around 40k calls
// so it is actually around 210 to 225 bytes per call
// these extra 66 bytes comes from return values,
// saved registers and other variables
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
