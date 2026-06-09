#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int a[100]={0},b[100]={0};

void print(int n)
{
	int i;
	for(i=1; i<=n; i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
	
void sea(int n,int k)
{
	int i;
	if(k == n+1)
	{
		print(n);
		return;
	}
	else
	{
		for(i=1; i<=n; i++)
		{
			if(b[i] == 0)
			{
				a[k] = i;
				b[i] = 1;
				sea(n,k+1);
				b[i] = 0;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	sea(n,1);
	return 0;
}




