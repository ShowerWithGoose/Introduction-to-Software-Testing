#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 100
int Stack[maxsize];
int top;
void initStack() {
	top=-1;
}
int isFull() {
	return top==maxsize-1;
}

int isEmpty() {
	return top==0;	
}

int pop(int s[]) {
	if(isEmpty()) 
	printf("error ");
	else{
	printf("%d ",Stack[top]);
	return s[top--];	
	}
	
	
}


void push(int s[],int item) {
	scanf("%d",&item);
	if(isFull())
	printf("error ");
	else
	
	s[++top]=item;
}

int item,flag;
int main() {
	while(flag!=-1) {
		scanf("%d",&flag);
		if(flag==1) 
		push(Stack,item);
		if(flag==0)
		pop(Stack);
	
	}
	
	return 0;
	
	
	
	
	
	
}

