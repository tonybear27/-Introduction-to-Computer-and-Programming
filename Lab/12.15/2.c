#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Segment
{
    int start;
    int end;
} segment;

int cmp(const void *a, const void *b)
{
    segment *aa = (segment *)a;
    segment *bb = (segment *)b;

    return aa->start > bb->start ? 1 : -1;
}

int main()
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int M;
        scanf("%d", &M);

        int sizeioflines = 0, sizeofans = 0;
        segment input;
        segment lines[50000], ans[50000];

        while (scanf("%d%d", &input.start, &input.end) && (input.start != 0 || input.end != 0))
            lines[sizeioflines++] = input;

        qsort(lines, sizeioflines, sizeof(lines[0]), cmp);

        int left = 0;
        int right = 0;
        int temp;

        for (int i = 0; i < sizeioflines; i++)
        {
            temp = -1;
            for (; i < sizeioflines && lines[i].start <= left; i++)
                if (lines[i].end > right)
                {
                    right = lines[i].end;
                    temp = i;
                }
            if (temp == -1)
                break;
            ans[sizeofans++] = lines[temp];

            if (right >= M)
                break;
            left = right;
            i--;
        }

        if (right < M)
        {
            printf("0\n");
            continue;
        }

        printf("%d\n", sizeofans);
        for (int i = 0; i < sizeofans; i++)
            printf("%d %d\n", ans[i].start, ans[i].end);
    }

    return 0;
}