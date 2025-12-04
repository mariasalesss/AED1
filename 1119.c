#include <stdio.h>
#include <stdlib.h>

typedef struct __no
{
    int id;
    struct __no *anterior;
    struct __no *proximo;
} no_t;

no_t *preencher(int);
no_t *remover(no_t *, no_t *);
int contar(no_t *);
no_t *percorrer(no_t *, int, int);

int main(int argc, char **argv)
{
    int total, passoK, passoM;
    no_t *lista, *ptrK, *ptrM, *proxK, *proxM;

    while (scanf("%d %d %d", &total, &passoK, &passoM), total)
    {
        lista = preencher(total);
        ptrK = lista;
        ptrM = lista->anterior;

        while (contar(lista) > 2)
        {
            ptrK = percorrer(ptrK, passoK, 0);
            ptrM = percorrer(ptrM, passoM, 1);

            if (ptrK->proximo == ptrM)
                proxK = ptrM->proximo;
            else
                proxK = ptrK->proximo;

            if (ptrM->anterior == ptrK)
                proxM = ptrK->anterior;
            else
                proxM = ptrM->anterior;

            if (ptrK == ptrM)
            {
                printf("%3d,", ptrM->id);
                lista = remover(lista, ptrK);
            }
            else
            {
                printf("%3d%3d,", ptrK->id, ptrM->id);
                lista = remover(lista, ptrM);
                lista = remover(lista, ptrK);
            }

            ptrK = proxK;
            ptrM = proxM;
        }

        if (contar(lista) == 2)
        {
            ptrK = percorrer(ptrK, passoK, 0);
            ptrM = percorrer(ptrM, passoM, 1);

            if (ptrK == ptrM)
                printf("%3d,%3d\n", ptrK->id, ptrK->proximo->id);
            else
                printf("%3d%3d\n", ptrK->id, ptrK->proximo->id);
        }
        else
            printf("%3d\n", lista->id);
    }

    return 0;
}

no_t *preencher(int tamanho)
{
    no_t *no;
    no_t *no_ant;
    no_t *inicio = NULL;

    for (int i = 1; i <= tamanho; ++i)
    {
        no = (no_t *)malloc(sizeof(no_t));
        no->id = i;

        if (inicio == NULL)
            inicio = no;
        else
        {
            no_ant->proximo = no;
            no->anterior = no_ant;
        }

        no_ant = no;
    }

    inicio->anterior = no;
    no->proximo = inicio;

    return inicio;
}

no_t *remover(no_t *lista, no_t *reg)
{
    no_t *no_ant = reg->anterior;
    no_t *no_prox = reg->proximo;

    if (reg == lista)
    {
        lista = lista->proximo;
        no_ant->proximo = lista;
        lista->anterior = reg->anterior;
    }
    else
    {
        no_ant->proximo = no_prox;
        no_prox->anterior = no_ant;
    }

    free(reg);
    return lista;
}

int contar(no_t *lista)
{
    int i;
    no_t *no = lista;
    for (i = 1; lista != no->proximo; ++i)
        no = no->proximo;

    return i;
}

no_t *percorrer(no_t *lista, int n, int direcao)
{
    no_t *no = lista;

    if (direcao == 0)
        while (--n)
            no = no->proximo;
    else
        while (--n)
            no = no->anterior;

    return no;
}
