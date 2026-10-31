#include "../include/product.h"
// Functions quick_sort_value & quick_sort_ptrs, are warpers so the function pointers array could be used insted of an switch case
static double median3(double a, double b, double c)
{
    if (a < b) {
        if (b < c)
            return b;
        return (a < c) ? c : a;
    }
    if (a < c)
        return a;
    return (b < c) ? c : b;
}
void quick_sort_value_rec(Product arr[], int low, int high)
{
    while (low < high) {
        double pivot = median3(arr[low].price, arr[low + (high - low) / 2].price, arr[high].price);
        int lt = low, i = low, gt = high;
        while (i <= gt) {
            if (arr[i].price < pivot) {
                Product tmp = arr[lt];
                arr[lt] = arr[i];
                arr[i] = tmp;
                lt++;
                i++;
            } else if (arr[i].price > pivot) {
                Product tmp = arr[i];
                arr[i] = arr[gt];
                arr[gt] = tmp;
                gt--;
            } else {
                i++;
            }
        }
        if (lt - low < high - gt) {
            quick_sort_value_rec(arr, low, lt - 1);
            low = gt + 1;
        } else {
            quick_sort_value_rec(arr, gt + 1, high);
            high = lt - 1;
        }
    }
}
void quick_sort_value(Product arr[], int n)
{
    quick_sort_value_rec(arr, 0, n - 1);
}
void quick_sort_ptrs_rec(Product* arr[], int low, int high)
{
    while (low < high) {
        double pivot = median3(arr[low]->price, arr[low + (high - low) / 2]->price, arr[high]->price);
        int lt = low, i = low, gt = high;
        while (i <= gt) {
            if (arr[i]->price < pivot) {
                Product* tmp = arr[lt];
                arr[lt] = arr[i];
                arr[i] = tmp;
                lt++;
                i++;
            } else if (arr[i]->price > pivot) {
                Product* tmp = arr[i];
                arr[i] = arr[gt];
                arr[gt] = tmp;
                gt--;
            } else {
                i++;
            }
        }
        if (lt - low < high - gt) {
            quick_sort_ptrs_rec(arr, low, lt - 1);
            low = gt + 1;
        } else {
            quick_sort_ptrs_rec(arr, gt + 1, high);
            high = lt - 1;
        }
    }
}
void quick_sort_ptrs(Product* arr[], int n)
{
    quick_sort_ptrs_rec(arr, 0, n - 1);
}
