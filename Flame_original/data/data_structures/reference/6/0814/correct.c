#include <stdio.h>
int main()
{
	int top=-1,stack[100];
	int op,num;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			if(top<100)
			{
				scanf("%d",&num);
				stack[++top]=num;
			}
			else printf("error ");
		}
		else if(op==0)
		{
			if(top>=0)
			{
				printf("%d ",stack[top]);
				top--;
			}
			else printf("error ");
		}
		else break;
	}
	return 0;
}

