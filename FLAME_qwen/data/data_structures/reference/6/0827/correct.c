#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define pi acos(-1)
#define eps 1e-10
#define M 100
int stack[M];
int top=-1;

int isempty(){
	return top==-1;
}

int isfull(){
	return top==M-1;
}

void out(int stack[]){
	if(isempty())
	printf("error ");
	else
	printf("%d ",stack[top--]);
}

void in(int stack[],int item){
	if(isfull())
	printf("error ");
	else
	stack[++top]=item;
}

int main(){
	int i,op,n;
	for(i=0;op!=-1;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&n);
			in(stack,n);
		}
		if(op==0){
			out(stack);
		}
	}
}


