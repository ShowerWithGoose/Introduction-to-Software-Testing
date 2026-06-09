#include<stdio.h>
#include<string.h>
int top;
void push(int num[],int fresher)
{
	if(top==99)
	{
		printf("error ");
		return;
	}
	top++;
	num[top]=fresher;
}
void out(int num[])
{
	if(top==-1)
	{
		printf("error ");
		return;
	}
	printf("%d ",num[top]);
	top--;	
}
int main()
{
	int num[100];
	top=-1;
	int x;
	while(1)
	{
		scanf("%d",&x);
		if(x==1)
		{
			scanf("%d",&x);
			push(num,x);
		}
		else if(x==0)
		{
			out(num);
		}
		if(x==-1)
		{
			break;
		}
	}
	return 0;
}

