#include <stdio.h>
#include <math.h>

#define TAMANHO_MAX 1000

short quantidadeDivisores[TAMANHO_MAX];

void calcularDivisoresPares();

void main ()
{

    unsigned short quantidadeCasos;
    unsigned totalEsferas, totalDivisoresPares;
    unsigned i;

    calcularDivisoresPares();
    scanf("%hu", &quantidadeCasos);

    while (quantidadeCasos--)
    {

        scanf("%u", &totalEsferas);

        totalDivisoresPares = 1;

        for (i = 3; i <= totalEsferas; i++)
        {

            if (quantidadeDivisores[i] % 2 == 0)
                totalDivisoresPares++;

        }

        printf("%u\n", totalDivisoresPares);
    }

}

void calcularDivisoresPares()
{
    unsigned i, j, limite;
    unsigned quantidadeDiv;

    quantidadeDivisores[0] = 3;
    quantidadeDivisores[1] = 1;

    for (i = 2; i <= 1000; i++)
    {
        quantidadeDiv = 2;
        limite = i / 2;

        for (j = 2; j <= limite; j++)
        {
            if (i % j == 0)
                quantidadeDiv++;
        }

        quantidadeDivisores[i] = quantidadeDiv;
    }

}
