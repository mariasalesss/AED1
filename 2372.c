#include <stdio.h>

#define TAMANHO_MAX 110
#define INFINITO 100000

int distancia[TAMANHO_MAX][TAMANHO_MAX];

inline int minimo(int, int);

int main(int argc, char **argv)
{

    int qtdPessoas, qtdCaminhos;
    int i, j, k, peso;

    scanf("%d %d", &qtdPessoas, &qtdCaminhos);

    for (i = 0; i < qtdPessoas; ++i)
        for (j = 0; j < qtdPessoas; ++j)
            distancia[i][j] = INFINITO;

    for (i = 0; i < qtdPessoas; ++i)
        distancia[i][i] = 0;

    for (i = 0; i < qtdCaminhos; ++i)
    {

        scanf("%d %d %d", &j, &k, &peso);
        distancia[j][k] = distancia[k][j] = peso;

    }

    for (i = 0; i < qtdPessoas; ++i)
        for (j = 0; j < qtdPessoas; ++j)
            for (k = 0; k < qtdPessoas; ++k)
                distancia[j][k] = minimo(distancia[j][k], distancia[j][i] + distancia[i][k]);
    
    int maiorDist = -1;
    int menorDist = INFINITO;

    for (i = 0; i < qtdPessoas; ++i)
    {

        maiorDist = -1;
        for (j = 0; j < qtdPessoas; ++j)
            if (distancia[i][j] > maiorDist && distancia[i][j] != INFINITO)
                maiorDist = distancia[i][j];

        if (menorDist > maiorDist && maiorDist > 0)
            menorDist = maiorDist;

    }

    printf("%d\n", menorDist);

    return 0;

}

int minimo(int a, int b)
{
    return a < b ? a : b;
}
