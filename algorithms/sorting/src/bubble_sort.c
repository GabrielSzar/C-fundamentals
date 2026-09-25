#include "../include/sort.h"

void bubble_sort_value(Product arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int switched = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[i].preco < arr[j].preco) {
                Product temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                switched = 1;
            }
        }
        if (switched == 0) {
            break;
        }
    }
}
void bubble_sort_ptr(Product* arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int switched = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[i]->preco < arr[j]->preco) {
                Product* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                switched = 1;
            }
        }
        if (switched == 0) {
            break;
        }
    }
}
