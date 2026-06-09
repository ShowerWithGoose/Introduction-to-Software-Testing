#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int x[110], y[110], z[110], k[110];
	scanf("%d", &n);
	int i, j;
	for(i = 0;i < n;i ++)
	{
		scanf("%d %d %d %d", &x[i], &y[i], &z[i], &k[i]);
	}
	int temp;
	for(i = 0;i < n;i ++) //begin ordered only
	{
		for(j = 0;j < (n-1);j ++)
		{
			if(x[j] > x[j+1])
			{
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
				
				temp = y[j];
				y[j] = y[j+1];
				y[j+1] = temp;
				
				temp = z[j];
				z[j] = z[j+1];
				z[j+1] = temp;
				
				temp = k[j];
				k[j] = k[j+1];
				k[j+1] = temp;
			}
		}
	}
	for(i = 0;i < n;i ++)
	{
		for(j = i+1;j <= n;j ++)
		{
			if(x[i] == x[j])
			{
				if(y[i] > y[j])
				{
					temp = y[j];
					y[j] = y[i];
					y[i] = temp;
				
					temp = z[j];
					z[j] = z[i];
					z[i] = temp;
				
					temp = k[j];
					k[j] = k[i];
					k[i] = temp;
				}
			}
		}
	}
	int l = 0, L = 0;
	int a, b;
	for(i = 0;i < n;i ++) //check, point i fixed,end -> other begin
	{
		temp = i;
		l = 0;
		for(j = 0;j < n;j ++)
		{
			if(z[temp] == x[j]&&k[temp] == y[j])
			{
				l ++;
				temp = j;
			}
		}
		if(l > L)
		{
			L = l;
			a = x[i];
			b = y[i];
		}
	}
	printf("%d %d %d", L + 1, a, b);
	return 0;
} 



