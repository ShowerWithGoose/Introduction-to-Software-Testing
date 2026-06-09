#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int x[12],y[12];
int digui(int z,int n);
int main() 
{ 
    int n;
	scanf("%d",&n);
    digui(1,n);
    return 0; 
}
int digui(int z,int n)
{
	if(z<=n)
	{
		for(int i=1;i<=n;i++)
		{
			if(y[i]==0)
			{
				x[z]=i;
				y[i]=1;
			    digui(z+1,n);
				x[z]=0;
				y[i]=0;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
			putchar(10);	
	}
}



