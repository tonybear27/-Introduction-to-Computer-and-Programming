#include <stdio.h>

void bangla(long long n)
{
    if (n >= 10000000)
    {
        bangla(n / 10000000);
        printf(" kuti");
        n %= 10000000;
    }
    if (n >= 100000)
    {
        bangla(n / 100000);
        printf(" lakh");
        n %= 100000;
    }
    if (n >= 1000)
    {
        bangla(n / 1000);
        printf(" hajar");
        n %= 1000;
    }
    if (n >= 100)
    {
        bangla(n / 100);
        printf(" shata");
        n %= 100;
    }
    if (n)
        printf(" %lld", n);
}

int main()
{
    int cs = 1;
    long long n;
    while (1)
    {
        scanf("%lld", &n);
        if (n == -1)
            break;
        printf("%d.", cs++);
        if (n == 0)
        {
            printf(" 0\n");
            continue;
        }
        bangla(n);
        puts("");
    }

    return 0;
}