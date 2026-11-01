#include "../include/product.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void populate_products(Product arr[], int n)
{ // the buffer is [64], so no strings bigger than that
    const char* product_name_seed[] = {
        "Tung-tung-tung-tung-tung-tung-tung-tung-tung-Sahur",
        "Tung-tung-sahurcles",
        "Skibidi-toilet",
        "Tiki-Tiki-Phonk",
        "Roblox",
        "Verity",
        "Lovety",
        "Falsity",
        "Cruelty",
        "Obesity",
        "Israelity",
        "Mommyty",
        "Six-seven",
    };
    const size_t num_name_seed = sizeof(product_name_seed) / sizeof(product_name_seed[0]);
    const size_t price_range = 1000;
    for (int i = 0; i < n; i++) {
        int r_price = rand() % price_range;
        int r_name = rand() % num_name_seed;
        snprintf(arr[i].name, sizeof(arr[i].name), "%s#%d", product_name_seed[r_name], i);
        arr[i].price = r_price;
    }
}
