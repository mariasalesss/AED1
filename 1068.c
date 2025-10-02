#include <stdio.h>

int main() {
    char expressao[1001];
    
    // Lê linhas até EOF (fim da entrada)
    while (fgets(expressao, sizeof(expressao), stdin)) {
        int balance = 0;
        int correto = 1;
        
        for (int i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                balance++;
            } else if (expressao[i] == ')') {
                balance--;
                if (balance < 0) {
                    correto = 0;
                    break; // Sai cedo se inválido
                }
            }
        }
        
        if (balance != 0) {
            correto = 0;
        }
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
