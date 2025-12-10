#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0

char numero1[1010];
char numero2[1010];

int resolver(char *);

int main(int argc, char **argv)
{

    while (verdadeiro)
    {

        scanf("%s %s", numero1, numero2);

        if (strcmp(numero1, "0") == 0 && strcmp(numero2,"0") == 0)
            break;

        int resultado1 = resolver(numero1);
        int resultado2 = resolver(numero2);

        if (resultado1 > resultado2)
            putchar_unlocked('1');
        else if (resultado1 < resultado2)
            putchar_unlocked('2');
        else
            putchar_unlocked('0');

        putchar_unlocked('\n');

    }
    return 0;

}

int resolver(char *str)
{

    int i, soma;

    if (strlen(str) == 1)
        return (int)(str[0] - 48);

    i = soma = 0;
    while (str[i])
        soma += (int)(str[i++] - 48);

    i = 0;
    while (soma)
        str[i++] = (char)((soma % 10) + 48), soma /= 10;

    str[i] = 0;

    return resolver(str);

}
