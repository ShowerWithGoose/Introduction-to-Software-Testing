#include<stdio.h>
int main()
{
	int stack[100], re[100];
	int n, i=0, j=0;
	while(scanf("%d",&n))
	{
		if(n==1)
		{
			if(i==100)
				re[j++]=-1;
			else
				scanf("%d",&stack[i++]);
		}
		else if(n==0)
		{
			if(i==0)
				re[j++]=-1;
			else
				re[j++]=stack[--i];
		}
		else if(n==-1)
			break;
		else
			continue;
	}
	for(i=0;i<j;i++)
	{
		if(re[i]==-1)
			printf("error ");
		else
			printf("%d ",re[i]);
	}
	return 0;
}

