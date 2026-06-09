#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
int stack[MAXSIZE]={0};
int top=-1;
int isempty()
{
 return top==-1;
}
int isfull()
{
 return top==MAXSIZE-1;
}
void push(int stack[],int item)// 1
{
 if(!isfull())
  
  stack[++top]=item; 
}
void pop(int stack[])// 0
{
 if(!isempty())
  printf("%d ",stack[top]); 
  stack[top--]=0;
  
}
int main()
{
	int op;
	int n;
	while(1){
		scanf("%d",&op);
		if(op==-1)	break;
		else if(op==0){
			if(isempty()){
				printf("error ");
			}
			else {
				pop(stack);
			}
		}
		else if(op==1){
			scanf("%d",&n);
			if(isfull()){
				printf("error ");
			}
			push(stack,n);
		}
	}
 
 return 0;
}

