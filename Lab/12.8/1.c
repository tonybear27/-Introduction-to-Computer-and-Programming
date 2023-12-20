#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool sieve[1000000];
int primes[1000000];
int digitprimes[1000000];
int ans[1000000];

void prime()
{
    sieve[0] = sieve[1] = true;
    for (int i = 2; i <= sqrt(1000000); i++)
        if (!sieve[i])
            for (int k = (1000000 - 1) / i, j = i * k; k >= i; k--, j -= i)
                if (!sieve[k])
                    sieve[j] = true;
}

void build()
{
    int index = 0;
    for (int i = 0; i < 1000000; i++)
        if (!sieve[i])
            primes[index++] = i;

    int index1 = 0;
    for (int i = 0; i < index; i++)
    {
        int sum = 0, temp = primes[i];
        while (temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (!sieve[sum])
            digitprimes[index1++] = primes[i];
    }

    int x = 0, y = 0;
    for (int i = 1; i < 1000000; i++)
    {
        if (i == digitprimes[x])
            y++, x++;

        ans[i] = y;
    }
}

int main()
{
    prime();
    build();

    int times;
    scanf("%d", &times);
    while (times--)
    {
        int s, d;
        scanf("%d%d", &s, &d);

        printf("%d\n", ans[d] - ans[s - 1]);
    }

    return 0;
}