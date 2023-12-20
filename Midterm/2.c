#include <stdio.h>
#include <string.h>
#define maxr 100
#define maxc 100

int main()
{
    int cs = 1;
    int m, n;
    char map[maxr][maxc];
    char field[maxr][maxc];

    while (scanf("%d%d", &m, &n))
    {
        if (m == 0 && n == 0)
            break;

        getchar();

        for (int i = 0; i < maxr; i++)
            for (int j = 0; j < maxc; j++)
                map[i][j] = '-';

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf(" %c", &map[i][j]);

        printf("Field #%d:\n", cs++);

        for (int r = 0; r < m; r++)
        {

            for (int c = 0; c < n; c++)
            {
                int cnt = 0;
                if (map[r][c] == '*')
                {
                    field[r][c] = '*';
                    continue;
                }
                for (int i = r - 1; i <= r + 1; i++)
                {
                    for (int j = c - 1; j <= c + 1; j++)
                    {
                        if (i < 0 || j < 0 || i >= m || j >= n)
                            continue;
                        if (map[i][j] == '*')
                            cnt++;
                    }
                }
                field[r][c] = (char)(cnt + '0');
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%c", field[i][j]);
            printf("\n");
        }

        puts("");
    }

    return 0;
}