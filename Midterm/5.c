#include <stdio.h>
#define SIZE 10101

int record[SIZE];

int step(int n)
{
    if (n > 10000)
    {
        if (n % 2 == 1)
            return 1 + step(3 * n + 1);
        else
            return 1 + step(n / 2);
    }

    int index = 100 + n;

    if (record[index] != -1)
        return record[index];

    if (n < 0)
        record[index] = 1 + step(n * n);
    else if (n == 1)
        record[index] = 1;
    else if (n % 2 == 1)
        record[index] = 1 + step(3 * n + 1);
    else
        record[index] = 1 + step(n / 2);

    return record[index];
}

int main()
{
    int start, end, maxIndex, maxValue;
    for (int i = 0; i < SIZE; i++)
        record[i] = -1;

    record[100] = 0;
    while (scanf("%d %d", &start, &end) != EOF)
    {
        maxIndex = start;
        maxValue = -1;
        for (int i = start; i <= end; i++)
        {
            int val = step(i);
            if (val > maxValue)
            {
                maxIndex = i;
                maxValue = val;
            }
        }

        printf("Room_%d %d\n", maxIndex, maxValue);
    }

    return 0;
}