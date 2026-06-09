#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100];
int top;
void initStack()
{
	top=-1;
}
int isEmpty()
{
	return top==0;//栈空返回1，不空返回0 
}
int isFull()
{
	return top==99;//栈满返回1，不满返回0 
}
  

int main()
{
	int opr,elm;//opr指的是操作，elm指的是元素
	int i;
	initStack();
	top++;
	//	printf("%d\n",top);
	while(1)
	{
		scanf("%d",&opr);
		if(opr==1)
		{
			scanf("%d",&elm);
			if(isFull())
			{
				printf("error ");
				continue;
			}
			
			stack[top++]=elm;
		}
		else if(opr==0)
		{
			
			if(isEmpty())
			{
				printf("error ");
				continue;
			 } 
			top--;//注意加减的次序，有可能会越界.因为插入的时候进行了top++，所以这里要减回来 
			printf("%d ",stack[top]);
		
		}
		else if(opr==-1) break;
	}
	
	return 0;
	
	
	
	
	
}

