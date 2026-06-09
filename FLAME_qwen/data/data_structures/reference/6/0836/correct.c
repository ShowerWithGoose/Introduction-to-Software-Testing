#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top=-1;
void push(int item)
{
	if(top==MAXSIZE-1)
	printf("error ");
	else
	stack[++top]=item;
 } 
int main()
{
	int n,item;
	while(scanf("%d",&n)!=-1)
	{
		if(n==1)
		{
			scanf("%d",&item);
			push(item);
		}
		if(n==0)
		{
			if(top==-1)
			printf("error ");
			else{
				item=stack[top--];
				printf("%d ",item);
			} 
			
		}
	}
	return 0;
 } 

