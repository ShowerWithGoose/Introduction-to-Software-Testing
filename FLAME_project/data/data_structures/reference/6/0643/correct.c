#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType stack[MAXSIZE];
int top;

void initStack(){
	top=-1;
}

int isEmpty(){
	return top==-1;
}

int isFull(){
	return top==MAXSIZE-1;
}

void Error(char s[]){
	printf("%s ",s);
	exit(-1);
}

void push(ElemType s[],ElemType item){
	if(isFull()){
		Error("error");
	}
	else{
		s[++top]=item;
	}
}

ElemType pop(ElemType s[]){
	if(isEmpty()){
		
		Error("error");
	}
	else{
		return s[top--];
	}
}

int main(){
	int i,j,k;
	int m,n;
	initStack();
	while(scanf("%d",&m)!=EOF){
		if(m==1){
			scanf("%d",&n);
			if(top<MAXSIZE){
				push(stack,n);
			}
			else{
				printf("error ");
			}
		}
		else if(m==0){
			if(top>-1){
				printf("%d ",pop(stack));
			}
			else{
				printf("error ");
			}
		}
		else if(m==-1){
			break;
		}
	}
	return 0;
}







