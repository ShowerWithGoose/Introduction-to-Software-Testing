#include<stdio.h>
#define max 100
int main()
{
	int op,z[max]={0},num,flag=0;
	while(scanf("%d",&op)!=-1)
	{
		if(op==1&&flag<99)
		{
			scanf("%d",&z[flag++]);
		}
		else if(op==1&&flag==99) printf("error ");
		else if(op==0&&flag>0)
		{
			printf("%d ",z[flag-1]);
			z[flag-1]=0;
			flag--;
		}
		else if(op==0&&flag==0)printf("error ");
	}
	return 0;
} 

