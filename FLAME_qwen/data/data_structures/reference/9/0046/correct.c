#include <stdio.h>
#include <string.h>

struct L
{           
	int x1; 
	int y1;
	int x2; 
	int y2;
	int num; 
};

int main()
{
	int i = 0, j = 0, n = 0, k = 0, flag = 0, max = 0, r = 0; 
	int o[100][4];
	struct L a[100];


	scanf("%d", &n); 

	for (i = 0; i < n; i++)
	{
		while (o[i][0] >= o[i][2])
		{ 
			scanf("%d%d%d%d ", &o[i][0], &o[i][1], &o[i][2], &o[i][3]);
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (o[i][0] == o[j][2] && o[i][1] == o[j][3])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			a[k].x1 = o[i][0];
			a[k].y1 = o[i][1];
			a[k].x2 = o[i][2];
			a[k].y2 = o[i][3];
			k++;
		}
		flag = 0;
	}

	for (i = 0; i < k; i++)
	{
		a[i].num = 1;
		for (j = 0; j < n; j++)
		{
			if (a[i].x2 == o[j][0] && a[i].y2 == o[j][1])
			{
				a[i].x2 = o[j][2];
				a[i].y2 = o[j][3];
				a[i].num++;
				j = -1;
			}
		}
	}

	for (i = 0; i < k; i++)
	{
		if (max < a[i].num)
		{
			max = a[i].num;
			r = i;
		}
	}
	printf("%d %d %d\n", a[r].num, a[r].x1, a[r].y1);
	return 0;
}


