#include<stdio.h>
#include<stdlib.h>
int stack[105];
int main()
{
	int op,top=0,x;
	while(scanf("%d",&op)&&op!=-1)
	{
		if(op)
		{
		    scanf("%d",&x);
			if(top==100) printf("error ");
			else stack[++top]=x;
		}
		else if(op==0)
		{
			if(top==0) printf("error ");
			else printf("%d ",stack[top--]);
		}
	}
 } 

