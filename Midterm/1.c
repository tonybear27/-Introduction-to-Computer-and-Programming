#include <stdio.h>

int counting(int n)
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (!(tmp % 5))
        {
            cnt++;
            tmp /= 5;
        }
    }

    return cnt;
}

int main()
{
    int times, n;
    scanf("%d", &times);
    while (times--)
    {
        scanf("%d", &n);
        printf("%d\n", counting(n));
    }

    return 0;
}