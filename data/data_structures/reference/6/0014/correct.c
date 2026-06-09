#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main()
{
	int n,i,num[100],sign,f=0,p=0,out[100];
	while(scanf("%d",&sign)!=-1)
	{
		if(sign==1&&f<100)
		{
			f=f+1;
			scanf("%d",&num[f]);
		}
		else if(sign==0&&f>0)
		{
			out[p]=num[f];
			f=f-1;
			p=p+1;
		}
		else
		{
			out[p]=1;//error
			p=p+1;
		}
	}
	for(i=0;i<p-1;i++)
	{
		if(out[i]==1)
			printf("error ");
		else
			printf("%d ",out[i]);
	}
	return 0;
}




