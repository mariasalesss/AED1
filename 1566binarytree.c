#include <stdio.h>
#include <stdlib.h>


int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); 
}

int main() {
    int quantidadeCasos;
    int quantidadePessoas;
    int altura;
    
    scanf("%d", &quantidadeCasos); 
    
    while (quantidadeCasos--) {
        
        scanf("%d", &quantidadePessoas);
        
        int *alturas = (int*)malloc(quantidadePessoas * sizeof(int)); // vetor para armazenar as alturas
        
        
        for (int i = 0; i < quantidadePessoas; i++) {
            scanf("%d", &alturas[i]);
        }
        
         
        qsort(alturas, quantidadePessoas, sizeof(int), comparar);
        
       
        for (int i = 0; i < quantidadePessoas; i++) {
            
            if (i == quantidadePessoas - 1) {
                printf("%d", alturas[i]);
            } else {
                printf("%d ", alturas[i]);
            }
        }
        printf("\n"); 
        
        free(alturas); 
    }
    
    return 0;
}
