#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
int stack[101];
void push(int* tail,int num)
{ 
    if(*tail==100)
	{
		 printf("error ");
		 return ;
	 } 
	else 
	{
		  stack[++(*tail)]=num;
		  return;
	}
}
void pop(int*tail)
{
	 if(*tail==0)
	 {
	 	  printf("error ");
	 	  return;
	 }
	 else 
	 {
	 	  printf("%d ",stack[*tail]);
	 	  (*tail)--;
	 	  return;
	 }
}
int main()
{
	 int tail=0;
	 int op,num;
	 while(scanf("%d",&op),op!=-1)
	 {
	 	 if(op==1)
	 	 {
	 	 	   scanf("%d",&num);
	 	 	   push(&tail,num);
		  }
		 if(op==0)
		 {
		 	   pop(&tail);
		 }
	 }
	 return 0;
}

