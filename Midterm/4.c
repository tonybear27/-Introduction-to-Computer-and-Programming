#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

char a[55][1010];
char b[1010];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, m;
        scanf("%d%d", &m, &n);

        for (int i = 0; i < m; i++)
            scanf("%s", a[i]);

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            int cnta = 0, cntt = 0, cntc = 0, cntg = 0;
            for (int i = 0; i < m; i++)
            {
                if (a[i][j] == 'A')
                    cnta++;
                else if (a[i][j] == 'T')
                    cntt++;
                else if (a[i][j] == 'C')
                    cntc++;
                else
                    cntg++;
            }

            int cnt_max = MAX(cnta, cntc);
            cnt_max = MAX(cnt_max, cntg);
            cnt_max = MAX(cnt_max, cntt);

            if (cnt_max == cnta)
                b[j] = 'A';
            else if (cnt_max == cntc)
                b[j] = 'C';
            else if (cnt_max == cntg)
                b[j] = 'G';
            else
                b[j] = 'T';

            ans += (m - cnt_max);
        }

        for (int i = 0; i < n; i++)
            printf("%c", b[i]);

        printf("\n%d\n", ans);
    }

    return 0;
}