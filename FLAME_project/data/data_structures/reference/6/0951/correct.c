//4-1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int stack[100],top=-1;
int full()
{
	return top==99;
}
int empty()
{
	return top==-1;
}
void push(int t)
{
	stack[++top]=t;
}
int pop()
{
	int t=stack[top];
	top--;
	return t;
}
int main()
{
	int op,t;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==1)
		{
			scanf("%d",&t);
			if(full())
				printf("error ");
			else
				push(t);
		}
		else if(op==0)
		{
			if(!empty())
				printf("%d ",pop());
			else
				printf("error ");	
		}
	}
	return 0;
}


