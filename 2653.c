#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAM 1000100

typedef struct NoArvore {

    char texto[TAM];
    struct NoArvore *esquerda;
    struct NoArvore *direita;

} NoArvore;

unsigned resposta;

NoArvore *inserir(NoArvore *, char *);

int main(int argc, char **argv)
{

    char texto[TAM];

    NoArvore *arvore = NULL;
    while (scanf("%s", texto) != EOF)
        arvore = inserir(arvore, texto);

    printf("%d\n", resposta);

    return 0;

}

NoArvore *inserir(NoArvore *arvore, char *palavra)
{

    if (!arvore)
    {

        arvore = (NoArvore *) malloc(sizeof(NoArvore));
        arvore->esquerda = arvore->direita = NULL;
        strcpy(arvore->texto, palavra);
        ++resposta;

    }
    else if (strcmp(arvore->texto, palavra) > 0)
        arvore->esquerda = inserir(arvore->esquerda, palavra);
    else if (strcmp(arvore->texto, palavra) < 0)
        arvore->direita = inserir(arvore->direita, palavra);

    return arvore;

}
