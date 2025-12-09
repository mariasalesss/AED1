#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct{
    char texto[3000];
} string;

void ordenar(string *palavras, unsigned tamanho);

void main() {
    unsigned short casos;
    unsigned short i, j, k;

    scanf("%hu", &casos);

    string palavras[60];
    char entrada[3000];

    while (casos--) {
        memset(palavras, 0, sizeof(palavras));
        memset(entrada, 0, sizeof(entrada));
        scanf(" %[^\n]", entrada);

        i = j = k = 0;
        while (true) {
            while (entrada[i] != ' ') {
                if (entrada[i] == '\0')
                    break;
                else
                    palavras[j].texto[k++] = entrada[i++];
            }

            palavras[j].texto[k] = '\0';

            if (entrada[i] == '\0')
                break;

            i++; j++;
            k = 0;
        }

        j++;
        ordenar(palavras, j);

        for (i = 0; i < j; i++) {
            if (i != j && i != 0)
                printf(" ");
            printf("%s", palavras[i].texto);
        }
        printf("\n");
    }
}

void ordenar(string *palavras, unsigned tamanho) {
    short i = 1, j;
    string pivo;

    while (i < tamanho) {
        j = i - 1;
        pivo = palavras[i];

        while (j >= 0 && strlen(palavras[j].texto) < strlen(pivo.texto)) {
            palavras[j + 1] = palavras[j];
            j--;
        }

        palavras[j + 1] = pivo;
        i++;
    }
}
