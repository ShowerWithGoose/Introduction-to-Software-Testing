#include<stdio.h>
#define maxline 100
int top=-1;
int stack[maxline];
void push(int stack[],int x)
{
	if(top==maxline-1)
	{
	printf("error ");
    
}
else 
stack[++top]=x;

}
void pop(int stack[])
{
if(top==-1)
printf("error ");
else 

	printf("%d ",stack[top--]);
		
}
int main()
{
	int x;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==1)
		{
			scanf("%d",&x);
			push(stack,x);
		}
		else if(n==0) 
		{
		 pop(stack);
		
		
	}
	else 
	break;
 }
 
 return  0;
}

