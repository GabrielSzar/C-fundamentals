#include "../include/product.h"
static void heapify(Product arr[], int n, int i)
{
    int dad = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].price > arr[dad].price) {
        dad = left;
    }
    if (right < n && arr[right].price > arr[dad].price) {
        dad = right;
    }
    if (dad != i) {
        Product tmp = arr[i];
        arr[i] = arr[dad];
        arr[dad] = tmp;
        heapify(arr, n, dad);
    }
}
void heap_sort_value(Product arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Product tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}
static void heapify_ptrs(Product* arr[], int n, int i)
{
    int dad = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left]->price > arr[dad]->price) {
        dad = left;
    }
    if (right < n && arr[right]->price > arr[dad]->price) {
        dad = right;
    }
    if (dad != i) {
        Product* tmp = arr[i];
        arr[i] = arr[dad];
        arr[dad] = tmp;
        heapify_ptrs(arr, n, dad);
    }
}
void heap_sort_ptrs(Product* arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_ptrs(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        Product* tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify_ptrs(arr, i, 0);
    }
}
