#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

int a[15];
int flag[100]={0};
int n;

void sort(int curbox)
{
	int i;
	if(curbox==n+1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
		return;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			if(!flag[i])
			{
				a[curbox]=i;
				flag[i]=1;
				sort(curbox+1);
				flag[i]=0;
			}
		}
	}
}

int main (void)
{
	scanf("%d",&n);
	sort(1);
    return 0;
}


