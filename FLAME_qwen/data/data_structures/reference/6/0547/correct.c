#include<stdio.h>
#define MAX 100
int sta[MAX];
int top=-1;

int isempty(){ //栈空返回1,否则返回0
	return top==-1;
}
int isfull(){ //栈满返回1,否则返回0
	return top==MAX-1;
}
void push(int x){
	if(isfull()==1) printf("error ");
	else{
		sta[++top]=x;
	}
}
void pop(){
	if(isempty()==1) printf("error ");
	else{
		printf("%d ",sta[top]);
		top--;
	}
}

int main() {
	int op,tem;
	do{
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&tem);
			push(tem);
		}
		else if(op==0){
			pop();
		}
	}while(op!=-1);
	
	
	return 0;
}

