#include<stdio.h>
int main()
{
	int top=-1,mem[100],temp;
	scanf("%d",&temp);
	while(temp!=-1)
	{
		if(temp==1)
		{
			if(top==99)
			{
				printf("error ");
				scanf("%d",&temp);
				continue;
			}
			scanf("%d",&mem[++top]);
			scanf("%d",&temp);	
			continue;
		}
		if(temp==0)
		{
			if(top==-1)
			{
				printf("error ");
				scanf("%d",&temp);
				continue;
			}
			printf("%d ",mem[top--]);
			scanf("%d",&temp);	
			continue;
		}
	}
	return 0;
}

