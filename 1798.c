#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define verdadeiro 1
#define falso 0
#define TAM_MAX 2500
#define MAIOR(a, b) a > b ? a : b

int quantidadeTipos;
int valor[TAM_MAX];
int peso[TAM_MAX];
int memo[TAM_MAX][TAM_MAX];

int resolver(int indice, int restante);

int main(int argc, char **argv)
{

    int i, material;

    while (scanf("%d %d", &quantidadeTipos, &material) != EOF)
    {

        for (i = 0; i < quantidadeTipos; ++i)
            scanf("%d %d", &peso[i], &valor[i]);

        memset(memo, -1, sizeof(memo));
        printf("%d\n", resolver(0, material));

    }

    return 0;

}

int resolver(int indice, int restante)
{

    if (indice == quantidadeTipos)
        return 0;
    
    if (restante == 0)
        return 0;
    
    if (restante < 0)
        return INT_MIN;

    if (memo[indice][restante] == -1)
        memo[indice][restante] = MAIOR(resolver(indice + 1, restante),
                                       valor[indice] + resolver(indice, restante - peso[indice]));

    return memo[indice][restante];

}
