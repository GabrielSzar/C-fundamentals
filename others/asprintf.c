#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char* buffer = NULL;
    const char* nome = "Bob";
    int idade = 25;
    int tamanho = snprintf(NULL, 0, "Nome: %s, Idade: %d", nome, idade);
    if (tamanho < 0) {
        return 1;
    }
    buffer = malloc(tamanho + 1);
    if (buffer == NULL) {
        return 1;
    }
    snprintf(buffer, tamanho + 1, "Nome: %s, Idade: %d", nome, idade);
    printf("String portátil: %s\n", buffer);
    free(buffer);
}
