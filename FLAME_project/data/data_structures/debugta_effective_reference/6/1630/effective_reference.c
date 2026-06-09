#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int top=-1,s[MAXSIZE]={0};
void initStack();
int isEmpty();
int isFull();
void push(int s[],int item);
void pop(int s[]);
int main(){
	int n,x;
	while(scanf("%d",&n)!=-1){
		if(n==1){
			scanf("%d",&x);
			push(s,x);
		}
		else if(n==0){
			pop(s);
		}
		else if(n==-1)
			break;
	}
	return 0;
}
void initStack(){
	top=-1;
}
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==MAXSIZE-1;
}
void push(int s[],int item){
	if(isFull())
		printf("error ");
	else
		s[++top]=item;
}
void pop(int s[]){
	if(isEmpty()){
		printf("error ");
	}
	else
		printf("%d ",s[top--]);
}

