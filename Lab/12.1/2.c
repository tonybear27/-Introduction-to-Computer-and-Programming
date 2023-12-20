#include <stdio.h>
#include <string.h>
#define MAX 10000

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            printf("The Fibonacci number for 0 is 0\n");
            continue;
        }
        else if (n == 1)
        {
            printf("The Fibonacci number for 1 is 1\n");
            continue;
        }
        char s1[MAX] = "0", s2[MAX] = "1";

        int result[MAX] = {0}, x11[MAX] = {0}, x22[MAX] = {0}, carry[MAX] = {0};
        int lenmax;

        for (int i = 0; i < n - 1; i++)
        {
            int len1 = 0, len2 = 0;
            int v;

            len1 = strlen(s1);
            len2 = strlen(s2);
            lenmax = len1 * (len1 > len2) + len2 * (len1 <= len2);

            for (v = 0; v < len1; v++)
                x11[v] = s1[len1 - v - 1] - '0';
            for (v = 0; v < len2; v++)
                x22[v] = s2[len2 - 1 - v] - '0';

            for (v = 0; v < lenmax; v++)
                result[v] = x11[v] + x22[v];

            for (v = 0; v <= lenmax; v++)
            {
                carry[v + 1] = (carry[v] + result[v]) / 10;
                result[v] = (result[v] + carry[v]) % 10;
            }

            int k;
            int index = 0;
            if (result[lenmax] == 0)
                k = lenmax - 1;
            else
                k = lenmax;

            for (int j = 0; j < strlen(s2); j++)
                s1[j] = s2[j];
            for (; k >= 0; k--)
                s2[index++] = result[k] + '0';
        }

        printf("The Fibonacci number for %d is %s\n", n, s2);
    }

    return 0;
}