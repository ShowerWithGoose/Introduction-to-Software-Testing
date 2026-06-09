#include <stdio.h>
int stack[100];
int top=-1;
int main()
{
	int op;
	int operate;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==-1)
		    return 0;
		else if(op==0)
		{
			if(top==-1)
			    printf("error ");
			else
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
		else if(op==1)
		{
			scanf("%d",&operate);
			if(top==99)
			{
				printf("error ");
			}
			else
			{
				top++;
				stack[top]=operate;
			}
		}
	}
	return 0;
 } 

