#include<stdio.h>
#include<math.h>
int main()
{
	long long int x[110], y[110];
	long long int z[110], k[110];
	int i, p, j = 0, l = 0;
	char s;
	
	for(i = 0;i < 110&&s != '\n';i ++)
	{
		scanf("%lld %lld", &x[j], &y[j]); 
		s = getchar();
		j ++;	
	}
	s = 1;
	for(i = 0;i < 110&&s != '\n';i ++)
	{
		scanf("%lld %lld", &z[l], &k[l]); 
		s = getchar();
		l ++;	
	}
	long long int a[220], b[220];
	int c = 0;
	for(i = 0;i < j;i ++)
	{
		if(x[i] != 0)
		{
			for(p = 0; p < l;p ++)
			{
				a[c] = x[i] * z[p];
				b[c++] = y[i] + k[p];
			}
		}	
	}
	long long int temp;
	for(i = 0;i < c;i ++)
	{
		for(j = 0;j < (c-1);j ++)
		{
			if(b[j] < b[j+1])
			{
				temp = b[j];
				b[j] = b[j+1];
				b[j+1] = temp;
				
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	int u, v = 0;
	for(i = 0;i < c - v;i ++)
	{
		for(j = 0;j < (c-v);j ++)
		{
			if(b[i] == b[j] && i != j)
			{
				a[i] = a[j] + a[i];
				for(u = j;u < c;u ++)
				{
					a[u] = a[u+1];
					b[u] = b[u+1];
				}
				v ++;
			}
		}
	}
	for(i = 0;i < c - v;i ++)
	{
		printf("%d %d ", a[i], b[i]);
	}
	return 0;
}

