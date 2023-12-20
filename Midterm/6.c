#include <stdio.h>
#define M 1234567890
typedef long long ll;

ll bigmod(ll a, ll b, ll c)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll x = bigmod(a, b / 2, c);
        return x * x % c;
    }
    else
        return (a % c * bigmod(a, b - 1, c) % c);
}

ll goodNums(ll length)
{
    ll primeDigitNum = length / 2;
    ll evenDigitNum = length - primeDigitNum;

    ll powOf2 = length - 2 * primeDigitNum;
    ll powOf5 = length - evenDigitNum;

    return (bigmod(2, powOf2, M) * bigmod(5, powOf5, M)) % M;
}

int main()
{
    ll length;
    while (scanf("%lld", &length) != EOF)
    {
        if (length == 0)
            printf("0\n");
        else
            printf("%lld\n", goodNums(length));
    }

    return 0;
}