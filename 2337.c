#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAM_MAX 1010

typedef long long ll;

void resolver();
ll calcular_mdc(ll, ll);
ll calcular_mmc(ll, ll);

typedef struct {

    ll numerador;
    ll denominador;

} resposta_t;

ll fibonacci[TAM_MAX];
resposta_t respostas[TAM_MAX];

// https://www.fq.math.ca/Papers1/49-3/GriffithsCoinToss.pdf

int main(int argc, char **argv)
{

    ll n;
    resolver();
    while (~scanf("%lld", &n))
        printf("%lld/%lld\n", respostas[n].numerador, respostas[n].denominador);

    return 0;

}

void resolver()
{

    fibonacci[0] = 0LL;
    fibonacci[1] = 2LL;
    fibonacci[2] = 3LL;

    int i;
    for (i = 3; i < 42; ++i)
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];

    for (i = 1; i < 42; ++i)
    {

        ll temp = calcular_mdc(fibonacci[i], 1LL << i);
        respostas[i].numerador = fibonacci[i] / temp;
        respostas[i].denominador = (1LL << i) / temp;

    }

}

ll calcular_mdc(ll a, ll b)
{

    if (!b)
        return a;

    return calcular_mdc(b, a % b);

}

ll calcular_mmc(ll a, ll b)
{

    return (a / calcular_mdc(a, b)) * b;

}
