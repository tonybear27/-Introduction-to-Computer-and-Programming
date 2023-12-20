#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);

	while (n--)
	{
		int N, m;
		scanf("%d", &N);
		int *table1 = (int *)(malloc((N + 1) * sizeof(int)));
		for (int i = 0; i < N + 1; i++)
			table1[i] = 0;

		scanf("%d", &m);
		int *mach = (int *)(malloc((m + 1) * sizeof(int)));

		for (int i = 0; i < m; i++)
			scanf("%d", &mach[i + 1]);

		for (int i = 1; i <= N; i++)
		{
			int indicate = 0;
			for (int j = 1; j <= m; j++)
				if (i % mach[j] == 0)
					indicate = 1;
			if (indicate)
				table1[i]++;
			if (((i - 6) % 7 == 0 || (i - 7) % 7 == 0))
				table1[i] = 0;
		}

		int sum = 0;
		for (int i = 1; i <= N; i++)
			if (table1[i])
				sum++;

		printf("%d\n", sum);

		free(table1);
		free(mach);
	}

	return 0;
}