#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[1001];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", str);

        int contar = 0; 
        int abrir = 0; 

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] == '<') {
                abrir++; 
            } else if (str[i] == '>') {
                if (abrir > 0) { 
                    contar++;
                    abrir--;
                }
            }
        }

        printf("%d\n", contar);
    }

    return 0;
}
