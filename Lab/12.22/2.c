#include <stdio.h>

int joseph[15] = {0};

void build()
{
    for (int i = 1; i <= 14; i++)
    {
        int m = i + 1;
        while (1)
        {
            int k = i * 2;
            int kill = -1;

            while (i < k)
            {
                kill += m;
                kill %= k;

                if (kill < i)
                    break;

                k--;
                kill--;
            }

            if (k <= i)
            {
                joseph[i] = m;
                break;
            }

            m++;
        }
    }
}

int main()
{
    build();
    int k;
    while (scanf("%d", &k) && k)
        printf("%d\n", joseph[k]);

    return 0;
}