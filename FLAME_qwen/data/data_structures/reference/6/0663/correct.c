#include<stdio.h>
int STACK[100];
int top=-1;
void push(int s[],int a)
{
    	s[++top]=a;
}
void pop(int s[])
{
    if(top==-1)
        printf("error ");
    else
    	printf("%d ",s[top--]);
}

int main()
{
	int op,a;
	scanf("%d",&op);
	while(op!=-1)
	{
		if(op==1)
		{
			scanf("%d",&a);
			push(STACK,a);
		}
		else if(op==0)
		{
			pop(STACK);
		}
		scanf("%d",&op);
	}
	return 0;
}

