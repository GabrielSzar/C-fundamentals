#include "../include/product.h"
#include <stdlib.h>
#include <string.h>
static void merge_sort_value_merge(Product arr[], int mid, int n, Product tmp[])
{
    int i = 0;
    int j = mid;
    int k = 0;

    while (i < mid && j < n) {
        if (arr[i].price <= arr[j].price)
            tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
        }
    }
    while (i < mid) {
        tmp[k++] = arr[i++];
    }
    while (j < n) {
        tmp[k++] = arr[j++];
    }
    memcpy(arr, tmp, n * sizeof(Product));
}
static void merge_sort_value_rec(Product arr[], int n, Product tmp[])
{
    if (n <= 1)
        return;

    int mid = n / 2;
    merge_sort_value_rec(arr, mid, tmp);
    merge_sort_value_rec(arr + mid, n - mid, tmp);
    merge_sort_value_merge(arr, mid, n, tmp);
}
void merge_sort_value(Product arr[], int n)
{
    Product* tmp = malloc(n * sizeof(Product));
    if (!tmp)
        return;
    merge_sort_value_rec(arr, n, tmp);
    free(tmp);
}
// Mergesort pointers
static void merge_sort_ptrs_merge(Product* arr[], int mid, int n, Product* tmp[])
{
    int i = 0;
    int j = mid;
    int k = 0;

    while (i < mid && j < n) {
        if (arr[i]->price <= arr[j]->price)
            tmp[k++] = arr[i++];
        else {
            tmp[k++] = arr[j++];
        }
    }
    while (i < mid) {
        tmp[k++] = arr[i++];
    }
    while (j < n) {
        tmp[k++] = arr[j++];
    }
    memcpy(arr, tmp, n * sizeof(Product*));
}
static void merge_sort_ptrs_rec(Product* arr[], int n, Product* tmp[])
{
    if (n <= 1)
        return;

    int mid = n / 2;
    merge_sort_ptrs_rec(arr, mid, tmp);
    merge_sort_ptrs_rec(arr + mid, n - mid, tmp);
    merge_sort_ptrs_merge(arr, mid, n, tmp);
}

void merge_sort_ptrs(Product* arr[], int n)
{
    Product** tmp = malloc(n * sizeof(Product*));
    if (!tmp)
        return;
    merge_sort_ptrs_rec(arr, n, tmp);
    free(tmp);
}
