#include<stdio.h>
int s[105],top=-1;
int main()
{
	int op,item;
	scanf("%d",&op);
	while(op!=-1)
	{
		if(op==1)
		{
			scanf("%d",&item);
			if(top==99)
			{
				printf("error ");
			}
			else
			{
				s[++top]=item;
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
				printf("%d ",s[top]);
				top--;
			}
		}
		scanf("%d",&op);
	}
	return 0;
}

