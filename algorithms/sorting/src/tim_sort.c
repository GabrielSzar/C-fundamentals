#include "../include/sort.h"
#include <stdlib.h>
static const int RUN = 32;
static void tim_sort_insertion_sort_value(Product arr[], int left, int right)
{
    for (int i = left; i <= right; i++) {
        Product key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j].price > key.price) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
void merge_timsort_value(Product arr[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    Product* L = malloc(len1 * sizeof(Product));
    Product* R = malloc(len2 * sizeof(Product));

    for (int i = 0; i < len1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < len2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < len1 && j < len2) {
        if (L[i].price <= R[j].price) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void tim_sort_value(Product* arr, int n)
{
    for (int i = 0; i < n; i += RUN) {
        int left = i;
        int right = (i + 31 < n - 1) ? (i + 31) : (n - 1);
        tim_sort_insertion_sort_value(arr, left, right);
    }
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                merge_timsort_value(arr, left, mid, right);
            }
        }
    }
}
static void tim_sort_insertion_sort_ptrs(Product* arr[], int left, int right)
{
    for (int i = left; i <= right; i++) {
        Product* key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j]->price > key->price) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
void merge_timsort_ptrs(Product* arr[], int left, int mid, int right)
{
    int len1 = mid - left + 1;
    int len2 = right - mid;
    Product** L = malloc(len1 * sizeof(Product*));
    Product** R = malloc(len2 * sizeof(Product*));

    for (int i = 0; i < len1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < len2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < len1 && j < len2) {
        if (L[i]->price <= R[j]->price) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < len2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void tim_sort_ptrs(Product* arr[], int n)
{
    for (int i = 0; i < n; i += RUN) {
        int left = i;
        int right = (i + 31 < n - 1) ? (i + 31) : (n - 1);
        tim_sort_insertion_sort_ptrs(arr, left, right);
    }
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);

            if (mid < right) {
                merge_timsort_ptrs(arr, left, mid, right);
            }
        }
    }
}
