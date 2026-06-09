#include <stdio.h>
#include <string.h>
#include <math.h>;
int a[100],b[100] = {};
void judge(int depth,int n)
{
	int i;
	if (depth == n+1)
	{
		for (i = 1;i <= n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
		return;
	}
	for (i = 1;i <= n;i++)
	{
		if (b[i] == 0)
		{
			a[depth] = i;
			b[i] = 1;
			judge(depth + 1,n);
			b[i] = 0;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	judge(1,n);
}


