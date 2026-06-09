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
	int i = 0, j = 0, n = 0, k = 0, isl = 0, max = 0, res = 0; 
	int Ps[100][4];
	struct L arr[100];
	scanf("%d", &n); 
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &Ps[i][0], &Ps[i][1], &Ps[i][2], &Ps[i][3]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (Ps[i][0] == Ps[j][2] && Ps[i][1] == Ps[j][3])
			{
				isl = 1;
				break;
			}
		}
		if (isl == 0)
		{
			arr[k].x1 = Ps[i][0];
			arr[k].y1 = Ps[i][1];
			arr[k].x2 = Ps[i][2];
			arr[k].y2 = Ps[i][3];
			k++;
		}
		isl = 0;
	}
	for (i = 0; i < k; i++)
	{
		arr[i].num = 1;
		for (j = 0; j < n; j++)
		{
			if (arr[i].x2 == Ps[j][0] && arr[i].y2 == Ps[j][1])
			{
				arr[i].x2 = Ps[j][2];
				arr[i].y2 = Ps[j][3];
				arr[i].num++;
				j = -1;
			}
		}
	}
	for (i = 0; i < k; i++)
	{
		if (max < arr[i].num)
		{
			max = arr[i].num;
			res = i;
		}
	}
	printf("%d %d %d\n", arr[res].num, arr[res].x1, arr[res].y1);
	return 0;
}


