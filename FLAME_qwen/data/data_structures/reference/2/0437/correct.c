#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int i=0,j=0;
	int a[1000]={0},b=0,k=0;
	char d[10000];
	for(;;)
	{
		scanf("%d",&a[i]);
		i++;
		for(;;)
		{
			scanf("%c",&d[j]);
			if(d[j]=='+'||d[j]=='-'||d[j]=='*'||d[j]=='/'||d[j]=='=')
			{
				j++;
				break;
			}
		}
		if(d[j-1]=='=')
		break;
	}
	for(;k<j-1;k++)
	{
		if(d[k]=='*')
		{
			a[k+1]=a[k]*a[k+1];
			a[k]=0;
			d[k]=d[k-1];
		}
		else if(d[k]=='/')
		{
			a[k+1]=a[k]/a[k+1];
			a[k]=0;
			d[k]=d[k-1];
		}
	}
	for(k=0;k<i;k++)
	{
		if(a[k]==0)
		{
			continue;
		}
		else
		{
			b=a[k];
			break;
		}
    }
    for(;k<i;k++)
	{
		if(d[k]=='+')
		{
			b=b+a[k+1];
		}
		else if(d[k]=='-')
		{
			b=b-a[k+1];
		}
	}
	printf("%d",b);
}

