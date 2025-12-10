#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100009

int controle[TAM_MAX];
int valores[TAM_MAX];

int main(int argc, char **argv)
{

    int total_numeros, total_bolas;
    while (scanf("%d %d", &total_numeros, &total_bolas), total_numeros)
    {

        for (size_t i = 0; i < total_bolas; ++i)
        {

            scanf("%d", &valores[i]);
            for (size_t j = 0; j <= i; ++j)
                controle[abs(valores[i] - valores[j])] = 1;
        }

        size_t i = 0;
        for (; i <= total_numeros; ++i)
            if (!controle[i])
                break;

        printf("%c\n", (i - 1UL) != total_numeros ? 'N' : 'Y');
        memset(controle, 0, sizeof(int) * (total_numeros + 1));
    }

    return 0;
}
