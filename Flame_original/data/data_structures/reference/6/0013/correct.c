#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100 
int top;
void InitStack(){
	top=-1;
}
int isEmpty(){
	return top==-1;
}
int isFull(){
	return top==MAXSIZE-1;
}
void push(int s[],int item){
	if(isFull()){
		printf("error ");
	}
	else{
		s[++top]=item;
	}
}
void pop(int s[]){
	if(isEmpty()){
		printf("error ");
	}
	else{
		printf("%d ",s[top--]);
	}
}
int main()
{
	int s[MAXSIZE+1];
	InitStack();
	int a,b;
	while(scanf("%d",&a),a!=-1){
		if(a==1){
			scanf("%d",&b);
			push(s,b);
		}
		else if(a==0){
			pop(s);
		}
	}
	return 0;
}


