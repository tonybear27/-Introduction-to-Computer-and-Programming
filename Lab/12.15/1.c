#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10010

typedef struct Node
{
	int d, p;
} node;

node a[maxn];
int f[maxn], ans, n;

int cmp(const void *a, const void *b)
{
	node *aa = (node *)a;
	node *bb = (node *)b;
	return aa->p < bb->p ? 1 : -1;
}

int find(int x)
{
	if (f[x] < 0)
		return x;
	return f[x] = find(f[x]);
}

int main()
{
	while (scanf("%d", &n) && n != -1)
	{
		ans = 0;
		memset(f, -1, sizeof(f));

		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i].p, &a[i].d);

		qsort(a, n, sizeof(a[0]), cmp);

		for (int i = 0, r; i < n; i++)
			if ((r = find(a[i].d)) > 0)
			{
				ans += a[i].p;
				f[r] = r - 1;
			}

		printf("%d\n", ans);
	}

	return 0;
}