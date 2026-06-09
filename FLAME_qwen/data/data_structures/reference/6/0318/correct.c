#include<stdio.h>
int stack[99];
int top=-1;
int main()
{
	int op;
	int n;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==1)
		{
			if(top==100)
			{
				printf("error ");
			}
			else
			{
				scanf("%d",&n);
				stack[++top]=n;
			}
		}
		else if(op==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else 
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
		else if(op==-1)
			return 0;
	}
}

