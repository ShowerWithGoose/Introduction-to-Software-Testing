#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int top=-1;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

int isfull(){
	return top==MAX-1;
}

int isempty(){
	return top==-1;
}

void push(int *s,int x){
	if(isfull()){
		printf("error ");
	}
	else{
		s[++top]=x;
	}
	return;
}

int pop(int *s){
	if(!isempty()){
		return s[top--];
	}
}

int main(){
	int stack[MAX];
	int i,x;
	while(scanf("%d",&i)!=EOF){
			if(i==1){
				x=read();
				push(stack,x);
//				printf("%d ",stack[top]);
			}
			else if(i==0){
				if(isempty())
				  printf("error ");
			    else
			      printf("%d ",pop(stack));
			}
			else if(i==-1){
				return 0;
			}
	}
}

