#include <stdio.h>
#include <string.h>
#include <ctype.h>
struct node
{
	int coe;
	int pow;
};
struct node a[10000], b[10000], k[10000];
int jilu[10000];
int main()
{
	int i, j, t, temp;
	int long1, long2,long3;
	char c = 'a';
	for (i = 0;c!='\n'; i++)
	{
		scanf("%d%d%c", &a[i].coe, &a[i].pow, &c);
	}
	long1 = i;
	c = 'a';
	for (i = 0; c != '\n'; i++)
	{
		scanf("%d%d%c", &b[i].coe, &b[i].pow, &c);
	}
	long2 = i;
	
	for (i = 0,t = 0; i < long2; i++)
	{
		for (j = 0; j < long1; j++)
		{
			k[t].coe = a[j].coe * b[i].coe;
			k[t].pow = a[j].pow + b[i].pow;
			t++;
		}
	}
	long3 = t;
	for (i = 0; i < long3 - 1; i++) 
	{
		for (t = 0; t < long3 - 1 - i; t++)
		{
			if (k[t].pow < k[t + 1].pow)
			{
				temp = k[t].pow;
				k[t].pow = k[t + 1].pow;
				k[t + 1].pow = temp;
				temp = k[t].coe;
				k[t].coe = k[t + 1].coe;
				k[t + 1].coe = temp;
			}
			else if (k[t].pow == k[t + 1].pow)
			{
				k[t].coe = k[t].coe + k[t + 1].coe;
				k[t + 1].pow = 0;
				k[t + 1].coe = 0;
			}
		}
	}
	for (i = 0; i<long3; i++)
	{
		if (k[i].coe != 0)
		{
			printf("%d %d ", k[i].coe, k[i].pow);
		}
	}
		
	
}



