#include<stdio.h>
int main()
{
	int stack[150];
	int pop[150];
	int i=1;
	int error[150];
	int top=0;
	int op=0;
	do
	{
		scanf("%d",&op);
		if(op==1)
		{
			if(top>=100)
			{
				pop[i]=31415926;
				i++;
			}
			else
			{
				int topush=0;
				scanf("%d",&topush);
				stack[++top]=topush;
			}
		}
		else if(op==0)
		{
			if(top<1)
			{
				pop[i]=31415926;
				i++;
			}
			else
			{
				pop[i]=stack[top];
				i++;
				top--;
			}
		}
	}while(op!=-1);
	for(int j=1;j<=i-1;j++)
	{
		if(pop[j]!=31415926)
		printf("%d ",pop[j]);
		else
		{
			printf("error ");
		}
	}
	return 0;
}


