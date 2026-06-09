#include<stdio.h> 
int stack[100];
int top=-1;
void Push(int x)
{
	if(top==100-1)
	printf("error ");
	else
	stack[++top]=x;
}
void Pop()
{
	if(top==-1)
	printf("error ");
	else 
	printf("%d ",stack[top--]);
}
int main()
{
	int i,j,x;
	while(~scanf("%d",&x))
	{
		if(x==-1)
		break;
		else if(x==1)
		{
			scanf("%d",&x);
			Push(x);
		}
		else
		{
			Pop();
		}
	}
	return 0;
}

