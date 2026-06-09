#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
int main()
{
	int stack[100],top=-1;
	int flag;
	while(scanf("%d",&flag)!=-1)
	{
		if(flag)
		{
			if(top>=100)
				printf("FULL STACK");
			else
				scanf("%d",&stack[++top]);
		}
		else
		{
			if(top<0)
				printf("error ");
			else
				printf("%d ",stack[top--]);
		}
	}
	return 0;
} 

