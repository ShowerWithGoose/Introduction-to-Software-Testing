#include<stdio.h>
#include<string.h>
#include<math.h>
#define max 1000
int STACK[max];
int top=-1;
void push(int n[],int item)
{
	if(top==max-1)
	printf("error ");
	else 
	n[++top]=item;
}
void pop(int n[])
{
	if(top==-1)
	printf("error ");
	else 
	printf("%d ",n[top--]);
}
int main(int argc,const char *argv[])
{
while(1)
{
	int mark;
	scanf("%d",&mark);
	if(mark==1)
	{
		int putin;
		scanf("%d",&putin);
		push(STACK,putin);
	}
	else if(mark==0)
	{
		pop(STACK);
	}
	else if(mark==-1)
	{
		break;
	}
}

return 0;
}


