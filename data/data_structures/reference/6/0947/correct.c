#include<stdio.h>
int main()
{
	int STACK[100];
	int print[100];
	int top=-1,i=0,j=0;
	int work,num;
	while(scanf("%d",&work)!=EOF)
	{
		if(work==1)
		{
			scanf("%d",&num);
			if(top<99)
			{
				top++;
				STACK[top]=num;
			}
			else
			{
				print[i]=-1;
				i++;
			}
		}
		else if(work==0)
		{
			if(top!=-1)
			{
				print[i]=STACK[top];
				i++;
				top--;	
			}
			else
			{
				print[i]=-1;
				i++;
			}
		}
		else if(work==-1)
		break;	
	}
	for(j=0;j<i;j++)
	{
		if(print[j]!=-1)
		printf("%d ",print[j]);
		else if(print[j]==-1)
		printf("error ");
	}
	return 0;
}

