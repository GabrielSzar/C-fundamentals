#include "../include/sort.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void populate_products(Product arr[], int n)
{
    const char* product_name_seed[] = {
        "Roblox",
        "Teclado",
        "Garrafa",
        "AUmigos",
        "skibidi_toilet"
    };
    for (int i = 0; i < n; i++) {
        int r_price = rand() % 1000;
        int r_name = rand() % 5;
        snprintf(arr[i].name, sizeof(arr[i].name), "%s#%i", product_name_seed[r_name], i);
        arr[i].price = r_price;
    }
}
