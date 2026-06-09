#include <stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int Top=-1;
void push(int s[],int item);
void pop(int s[]);
int main()
{
	while(1)
	{
	int sign;
	scanf("%d",&sign);
	if(sign==1)
	{
		int m;
		scanf("%d",&m);
		push(STACK,m);
	}
	else if(sign==0)
	{
	pop(STACK);
	}
	else if(sign==-1)
	break;
	}
	return 0;
}
void push(int s[],int item)
{
	if(Top==MAXSIZE-1)
	printf("error ");
	else 
	s[++Top]=item;
}
void pop(int s[])
{
	if(Top==-1)
	printf("error ");
	else
	printf("%d ",s[Top--]); 
}

