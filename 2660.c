#include <stdio.h>

long long mdc(long long, long long);
long long mmc(long long, long long);

int main()
{

    long long i, ciclo, temp;
    long long totalPopulacoes, limiteSuperior;
    long long melhorCiclo, melhorMmc, novoMmc;

    scanf("%lld %lld", &totalPopulacoes, &limiteSuperior);

    temp = 1;

  
    for (i = 0; i < totalPopulacoes; ++i)
        scanf("%lld", &ciclo), temp = mmc(temp, ciclo);

    melhorCiclo = 1;
    melhorMmc = temp;

   
    for (i = 2; i <= limiteSuperior; ++i)
    {
        novoMmc = mmc(temp, i);

        if (novoMmc <= limiteSuperior && novoMmc > melhorMmc)
        {
            melhorMmc = novoMmc;
            melhorCiclo = i;
        }
    }

    printf("%lld\n", melhorCiclo);

    return 0;
}

long long mdc(long long a, long long b)
{
    long resto;

    resto = a % b;

    while (resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }

    return b;
}

long long mmc(long long a, long long b)
{
    return (a / mdc(a, b)) * b;
}
