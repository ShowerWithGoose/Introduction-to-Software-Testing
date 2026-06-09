#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
#define MAX 100
int stack[MAX]; 
int top=-1;
void PUSH(int a)
{
	if(top==MAX-1)
	{
		printf("error ");	
	}	
	else
	{
		stack[++top]=a;
	}
}
void POP()
{
	if(top==-1)
	{
		printf("error ");
	}
	else
	{
		printf("%d ",stack[top]);
		top--;
	}
}
int main()
{
	int op,num;
	scanf("%d",&op);
	while(1)
	{
		if(op==1)
		{	
			scanf("%d",&num);
			PUSH(num);
		}
		if(op==0)
		{
			POP();
		}
		if(op==-1)
		{
			break;
		}
		scanf("%d",&op);
	}
    return 0;
}

