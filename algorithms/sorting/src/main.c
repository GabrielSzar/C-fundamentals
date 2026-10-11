#include "../include/sort.h"
#include <stdio.h>
int main(void)
{
    Product produtos[] = {
        { "Terceiro", 3 },
        { "Primeiro", 1 },
        { "Quinto", 5 },
        { "Segundo", 2 },
        { "Sexto", 6 },
        { "Quarto", 4 },
    };
    int size = sizeof(produtos) / sizeof(Product);
    // quick_sort_value(produtos, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("Index[%d] %s | Valor : %f\n", i, produtos[i].nome, produtos[i].preco);
    }
}
