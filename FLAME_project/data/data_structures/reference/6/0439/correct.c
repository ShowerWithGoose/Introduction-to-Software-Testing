#include<stdio.h>
#define MAXSIZE 100
int Stack[MAXSIZE];
int Top=-1;
void initStack(){
	Top=-1;
}
int isEmpty(){
	return Top==-1;
}
int isFull(){
	return Top==MAXSIZE-1;
}
void push(int s[],int item){
	if(isFull())
		printf("error ");
	else
		s[++Top]=item;
}
int pop(int s[]){
	if(isEmpty())
		printf("error ");
	else{
		printf("%d ",s[Top]);
		return s[Top--];
	} 
}

void main()
{
	int n;
	
	do{
		scanf("%d",&n);
		if(n==1)
		{
			int e;
			scanf("%d",&e);
			push(Stack,e);
		}	
		else if(n==0)
			pop(Stack);
	}while(n!=-1);
	
} 

