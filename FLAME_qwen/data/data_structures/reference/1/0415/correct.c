#include <stdio.h>
int shuo[16];
int bao[16];
void arrange(int now,int max)
{
	if(now>max)
	{
		for(int i=1;i<=max;i++)
		{
			printf("%d ",bao[i]);
		}
		printf("\n");
	}
	for(int i=1;i<=max;i++)
	{
		if(shuo[i]==0)
		{
			shuo[i]=1;
			bao[now]=i;
			arrange(now+1,max);
			shuo[i]=0;
			bao[now]=0; 
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	arrange(1,n);
}

