#include <stdio.h>
#include <string.h>

void gerarKame(char *, char *);

void main ()
{

	char palavra[201], resultado[100000];
	unsigned short quantidadeCasos;

	scanf("%hu", &quantidadeCasos);

	while (quantidadeCasos--)
	{

		scanf(" %s", palavra);

		if (strcmp(palavra, "hamekame") == 0)
			printf("ka\n");
		else
		{
			gerarKame(palavra, resultado);
			printf("%s\n", resultado);
		}
	}
}

void gerarKame(char *entrada, char *saida)
{
	unsigned short contador = 0, auxiliar;

	*(saida++) = 'k'; 
	entrada++;
	
	while (*entrada == 'a')
	{
		entrada++;
		contador++;
	}

	while (*entrada != 'a')
		entrada++;

	if (contador == 1)
	{

		while (*entrada == 'a')
			*(saida++) = *(entrada++);

		*saida = '\0';

	}
	else
	{	
		while (*entrada == 'a')
		{	
			auxiliar = contador;
			while (auxiliar-- > 0)
				*(saida++) = 'a';

			entrada++;
		}
	}

	*saida = '\0';
}
