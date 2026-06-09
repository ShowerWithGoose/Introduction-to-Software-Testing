#include<stdio.h>
typedef struct li
{
	int x1, y1;
	int x2, y2;
}line;
line arr[105];
int z;
int f;
int p;
line c;
int check(line a)
{
	for (int i = 0;i < z;i++)
	{
		if (a.x1 == arr[i].x1 && a.x2 == arr[i].x2 && a.y2 == arr[i].y2 && a.y1 == arr[i].y1)
			continue;
		if (a.x2 == arr[i].x1 && a.y2 == arr[i].y1)
		{
			return 0;
		}
	}
	return 1;
}
void dfs(int x,line a)
{
	if (check(a))
	{
		if (p > f)
		{
			f = p;
			c = arr[x];
		}
		return;
	}
	else
	{
		for (int i = 0;i < z;i++)
		{
			if (a.x2 == arr[i].x1 && a.y2 == arr[i].y1)
			{
				p++;
				dfs(x,arr[i]);
				p--;
			}
		}
	}
}
int main()
{
	scanf("%d", &z);
	for (int i = 0;i < z;i++)
	{
		scanf("%d%d%d%d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
	}
	for (int i = 0;i < z;i++)
	{
		p = 0;
		dfs(i,arr[i]);
	}
	printf("%d ", f+1);
	printf("%d %d", c.x1, c.y1);
}

