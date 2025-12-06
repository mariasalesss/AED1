#include <stdio.h>
#include <stdbool.h>

#define TAM_MAX 1000000

unsigned long long soma_dos_divisores[TAM_MAX];

void gerar_crivo();

void main ()
{

    unsigned long long numero_lido;
    gerar_crivo();

    while (true)
    {

        scanf("%llu", &numero_lido);

        if (numero_lido == 0)
            break;

        printf("%llu\n", soma_dos_divisores[numero_lido]);

    }

}

void gerar_crivo()
{
    unsigned long long i, j;

    for (i = 1; i <= TAM_MAX; i++)
        for (j = i; j <= TAM_MAX; j += i)
            soma_dos_divisores[j] += i;

    for (i = 2; i <= TAM_MAX; i++)
        soma_dos_divisores[i] += soma_dos_divisores[i - 1];

}
