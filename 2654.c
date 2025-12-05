#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {

    char nome[150];
    unsigned short poder;
    unsigned short matou;
    unsigned short morreu;

} Heroi;

void ordenarPoder(Heroi *, unsigned short);
void ordenarMatou(Heroi *, unsigned short);
void ordenarMorreu(Heroi *, unsigned short);
void ordenarNome(Heroi *, unsigned short);

int main()
{

    unsigned short totalInscritos;
    unsigned short i;

    scanf("%hu", &totalInscritos);

    Heroi lista[totalInscritos];

    for (i = 0; i < totalInscritos; i++)
        scanf(" %s %hu %hu %hu", 
            lista[i].nome,
            &lista[i].poder,
            &lista[i].matou,
            &lista[i].morreu
        );

    ordenarNome(lista, totalInscritos);
    ordenarMorreu(lista, totalInscritos);
    ordenarMatou(lista, totalInscritos);
    ordenarPoder(lista, totalInscritos);

    printf("%s\n", lista[0].nome);

    return 0;
}

void ordenarPoder(Heroi *lista, unsigned short tam)
{

    short i = 1, j;
    Heroi pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = lista[i];

        while (j >= 0 && lista[j].poder < pivo.poder)
        {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = pivo;
        i++;
    }
}

void ordenarMatou(Heroi *lista, unsigned short tam)
{

    short i = 1, j;
    Heroi pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = lista[i];

        while (j >= 0 && lista[j].matou < pivo.matou)
        {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = pivo;
        i++;
    }
}

void ordenarMorreu(Heroi *lista, unsigned short tam)
{

    short i = 1, j;
    Heroi pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = lista[i];

        while (j >= 0 && lista[j].morreu > pivo.morreu)
        {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = pivo;
        i++;
    }
}

void ordenarNome(Heroi *lista, unsigned short tam)
{

    short i = 1, j;
    Heroi pivo;

    while (i < tam)
    {

        j = i - 1;
        pivo = lista[i];

        while (j >= 0 && strcmp(lista[j].nome, pivo.nome) > 0)
        {
            lista[j + 1] = lista[j];
            j--;
        }

        lista[j + 1] = pivo;
        i++;
    }
}
