#include<stdio.h>
int stack[100]={0};
int count=0;

void pop()
{
	if(count>0)
	{
		printf("%d ",stack[count-1]);
		stack[count]=0;
		count--; 
	}
	else
	printf("error ");
}
void push(int num)
{
	if(count<100)
	{
		stack[count]=num;
		count++;
	}
	else
	{
		printf("error ");
	}
}

int main()
{
	int op=0,n;
	int lp;
	while(op!=-1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d",&n);
			push(n);
		}
		else if(op==0)
		{
			pop();
		}
	}
	return 0;
 } 

