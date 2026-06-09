#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int top;
void initStack()
{
	top=-1;
}
int isEmpty()
{
	return top==-1;
}
int isFull()
{
	return top==MAXSIZE-1;
}
void push(int s[],int item)
{
	if(isFull())
	printf("error");
	else 
	s[++top]=item;
}
int pop(int s[])
{
	if(isEmpty())
	printf("error ");
	else{
		printf("%d ",s[top]);
		return s[top--];
	}
}
int main()
{
	int i,c[MAXSIZE],item;
	initStack();
	while(scanf("%d",&c[i])){
		if(c[i]==-1)break;
		else if(c[i]==1){
			scanf("%d",&item);
			push(STACK,item);
		}else if(c[i]==0){
			pop(STACK);
		}
	}	
	return 0;
}

