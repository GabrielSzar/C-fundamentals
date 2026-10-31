#include "../include/product.h"
#include <stdio.h>
#include <stdlib.h>

int resultfile(Product arr[], int n)
{
    FILE* result = fopen("result.txt", "w");
    if (result == NULL) {
        printf("Error while oppening result.txt!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(result, "Index[%d] Name: %s | Price: %.00f\n", i, arr[i].name, arr[i].price);
    }
    fclose(result);
    return 0;
}
