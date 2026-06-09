#include<stdio.h>
typedef struct li
{
	int x1, y1;
	int x2, y2;
}line;
line arr[105];
int n;
int ans;
int sum;
line c;
int check(line a)
{
	for (int i = 0;i < n;i++)
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
		if (sum > ans)
		{
			ans = sum;
			c = arr[x];
		}
		return;
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			if (a.x2 == arr[i].x1 && a.y2 == arr[i].y1)
			{
				sum++;
				dfs(x,arr[i]);
				sum--;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d%d%d%d", &arr[i].x1, &arr[i].y1, &arr[i].x2, &arr[i].y2);
	}
	for (int i = 0;i < n;i++)
	{
		sum = 0;
		dfs(i,arr[i]);
	}
	printf("%d ", ans+1);
	printf("%d %d", c.x1, c.y1);
}

