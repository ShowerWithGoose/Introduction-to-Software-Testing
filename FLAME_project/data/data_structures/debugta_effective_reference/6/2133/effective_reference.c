#include<stdio.h>
int main()
{
	int STACK[100];
	int printnum[100];
	int top=-1,popnum=0,i=0;
	int order,buf;
	while(scanf("%d",&order)!=EOF)
	{
		if(order==1)
		{
			scanf("%d",&buf);
			if(top<99)
			{
				top++;
				STACK[top]=buf;
			}
			else
			{
				printnum[popnum]=-1;
				popnum++;
			}
		}
		else if(order==0)
		{
			if(top!=-1)
			{
				printnum[popnum]=STACK[top];
				popnum++;
				top--;	
			}
			else
			{
				printnum[popnum]=-1;
				popnum++;
			}
		}
		else if(order==-1)
		break;	
	}
	for(i=0;i<popnum;i++)
	{
		if(printnum[i]!=-1)
		printf("%d ",printnum[i]);
		else if(printnum[i]==-1)
		printf("error ");
	}
	return 0;
}

