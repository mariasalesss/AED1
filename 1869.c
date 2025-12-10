#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0

typedef unsigned long long inteiro_longo;

void inverterString(char *);
char valorParaCaractere(inteiro_longo);
char * converterBase(inteiro_longo, unsigned, char *);

int main (int argc, char **argv)
{

    inteiro_longo numero;
    char *texto = (char *) calloc(100, sizeof(char));

    do
    {

        scanf("%llu", &numero);
        printf("%s\n", numero ? converterBase(numero, 32, texto) : "0");

    } while (numero);

    free(texto);

}

char valorParaCaractere(inteiro_longo valor)
{

    if (valor >= 0 && valor <= 9)
        return (char)(valor + '0');
    else
        return (char)(valor - 10 + 'A');

}

void inverterString(char *str)
{

    unsigned i;
    unsigned tamanho = strlen(str);
    unsigned limite = tamanho / 2;

    for (i = 0; i < limite; ++i)
    {

        char temp = str[i];
        str[i] = str[tamanho - i - 1];
        str[tamanho - i - 1] = temp;

    }

}

char * converterBase(inteiro_longo x, unsigned base, char *destino)
{

    unsigned indice = 0;

    while (x > 0)
        destino[indice++] = valorParaCaractere(x % base), x /= base;

    destino[indice] = '\0';
    inverterString(destino);
    return destino;

}
