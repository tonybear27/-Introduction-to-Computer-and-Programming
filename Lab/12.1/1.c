#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char tree[1000001][100];

void sort(char array[][100], int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        for (int j = 0; j < size_of_array - 1; j++)
        {
            if (strcmp(array[j], array[j + 1]) > 0)
            {
                char temp[100];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}

int main()
{
    int times;
    scanf("%d", &times);
    getchar();
    getchar();
    while (times--)
    {
        int sum = 0;
        memset(tree, 0, sizeof(tree));
        while (1)
        {
            gets(tree[sum++]);
            int check = sum - 1;
            if (tree[check][0] == '\0')
                break;
        }
        sum--;

        sort(tree, sum);

        int swp = 1, pos = 0;
        for (int i = 0; i < sum; i++)
        {
            int cnt = 1;

            while (swp < sum && !strcmp(tree[pos], tree[swp]))
            {
                cnt++;
                swp++;
            }

            printf("%s %.4lf\n", tree[pos], 100. * cnt / sum);
            pos = swp;
            swp = pos + 1;

            if (pos >= sum)
                break;
        }

        printf("\n");
    }

    return 0;
}