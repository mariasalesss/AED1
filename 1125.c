#include <stdio.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAM_MAX 105
#define INF 0x3f3f

typedef unsigned short us;

int main ()
{
    us grupos, pilotos, i, j, k;
    us tabela[TAM_MAX][TAM_MAX], sistemaPontuacao[TAM_MAX], pontosTotais[TAM_MAX];

    while (scanf("%hu %hu", &grupos, &pilotos), grupos)
    {
        
        for (i = 0; i < grupos; ++i)
            for (j = 0; j < pilotos; ++j)
                scanf("%hu", &tabela[i][j]);

        us quantidade_sistemas;
        scanf("%hu", &quantidade_sistemas);

        while (quantidade_sistemas--)
        {
            memset(pontosTotais, 0, sizeof(pontosTotais));
            memset(sistemaPontuacao, 0, sizeof(sistemaPontuacao));

            scanf("%hu", &k);

           
            for (i = 0; i < k; ++i)
                scanf("%hu", &sistemaPontuacao[i]);

            
            for (i = 0; i < grupos; ++i)
            {
                for (j = 0; j < pilotos; ++j)
                {
                    us pos = tabela[i][j] - 1;

                    
                    if (pos < k)
                        pontosTotais[j] += sistemaPontuacao[pos];
                }
            }

            
            us maiorPontuacao = 0;
            for (i = 0; i < pilotos; ++i)
                if (pontosTotais[i] > maiorPontuacao)
                    maiorPontuacao = pontosTotais[i];

          
            _Bool primeiro = verdadeiro;

            for (i = 0; i < pilotos; ++i)
            {
                if (pontosTotais[i] == maiorPontuacao)
                {
                    if (primeiro)
                    {
                        printf("%hu", i + 1);
                        primeiro = falso;
                    }
                    else
                    {
                        printf(" %hu", i + 1);
                    }
                }
            }

            printf("\n");
        }
    }

    return 0;
}
