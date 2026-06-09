#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int in[2][10000];

int main()
{
	int i,t=0,fl=-1,flag;
	while(scanf("%d",&i)!=-1)
	{
		if(i==1)
		{
			scanf("%d",&in[0][t]);
			t++;
			fl=t-1;
		}
		if(i==0)
		{
			while(in[1][fl]!=0&&fl>=0)
			{
				fl--;
			}
			if(fl>-1)
			{
				printf("%d ",in[0][fl]);
				in[1][fl]=1;
			}
			else printf("error ");
		}
	}
}

