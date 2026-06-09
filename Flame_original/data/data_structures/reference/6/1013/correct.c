#include<stdio.h>
#define MAXSIZE 100
int STACK[MAXSIZE];
int top=-1;
int isEmpty();
int isFull();
void push(int s[],int a);
void pop(int s[]);
int main(){
	int a, b;
	do{
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&b);
			push(STACK,b);
		}
		else if(a==0) pop(STACK);
	}while(a!=-1);
	return 0;
}
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==MAXSIZE-1;
}
void push(int s[],int a){
	if(isFull()) printf("error ");
	else s[++top]=a;
}
void pop(int s[]){
	if(isEmpty()) printf("error ");
	else printf("%d ",s[top--]);
}

