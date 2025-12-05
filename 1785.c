#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0

void para_string();
void para_vetor(int);
int comparar_crescente(int *, int *);
int comparar_decrescente(int *, int *);

int vet_maior[10], vet_menor[4];
char num_menor[5], num_maior[5];

int main(int argc, char **argv)
{

    _Bool flag;
    int n, caso, x, passos; 

    caso = 0;
    scanf("%d%*c", &n);

    while (n--)
    {

        passos = 0;
        flag = falso;
        scanf("%d", &x);

        while (x != 6174)
        {

            para_vetor(x);

            qsort(vet_maior, 4, sizeof(int), comparar_crescente);
            qsort(vet_menor, 4, sizeof(int), comparar_decrescente);

            para_string();

            x = atoi(num_maior) - atoi(num_menor);

            if (x == 0)
                flag = verdadeiro;

            ++passos;

            if (flag)
                break;

        }

        if (!flag)
            printf("Caso #%d: %d\n", ++caso, passos);
        else
            printf("Caso #%d: %d\n", ++caso, -1);

    }

    return 0;

}

void para_string()
{

    int i;
    for (i = 0; i < 4; ++i)
    {
        num_menor[i] = (char)(vet_maior[i] + 48);
        num_maior[i] = (char)(vet_menor[i] + 48);
    }

}

void para_vetor(int x)
{

    int i = 3;
    memset(vet_maior, 0, sizeof(vet_maior));
    memset(vet_menor, 0, sizeof(vet_menor));
    
    while (x)
    {
        vet_maior[i] = vet_menor[i] = x % 10;
        x /= 10;
        --i;
    }

}

int comparar_crescente(int *a, int *b)
{
    return *a - *b;
}

int comparar_decrescente(int *a, int *b)
{
    return *b - *a;
}
