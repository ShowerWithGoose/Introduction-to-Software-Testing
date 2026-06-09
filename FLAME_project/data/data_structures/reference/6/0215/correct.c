#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const int maxline=100;
int stack[100];
int top;
void stack_push();
int stack_out();
int stack_error(int num0);//回0无错，回1有错 
int main()
{
	int op,temp;
	top=-1;
	scanf("%d",&op);
	while(op!=-1)
	{
		if(op) stack_push();
		  else if(!stack_error(2)) printf("%d ",stack_out());
		scanf("%d",&op);
	}
	return 0;	
}
void stack_push()
{
	int x;
	scanf("%d",&x);
	if(!stack_error(1)) stack[++top]=x;
}
int stack_out()
{
	int x;
	x=stack[top--];
	return x;
}
int stack_error(int num0)
{
	if(num0==1)
	 {
	 	if(top==maxline-1) {printf("error ");return 1;}
	 	  else return 0;
	 }
	 else
	  {
	  	if(top==-1) {printf("error ");return 1;}
	  	  else return 0;
	  }
}

