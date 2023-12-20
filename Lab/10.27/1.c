#include <stdio.h>

int main()
{
    int index[100];
    char s[200][200];
    int times;
    char c;
    scanf("%d", &times);

    while (times--)
    {
        int cnt = 0;
        scanf(" ");

        do
        {
            c = getchar();
            if (c != ' ')
                index[cnt++] = (int)(c - 49);
        } while (c != '\n');

        cnt--;

        for (int i = 0; i < cnt; i++)
            scanf("%s", s[index[i]]);

        for (int i = 0; i < cnt; i++)
            printf("%s\n", s[i]);

        puts("");
    }

    return 0;
}