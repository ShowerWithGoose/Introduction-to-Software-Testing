#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int a[100]={0},top=0;

void push(int n){
	if(top<99)	a[++top]=n;	
	else	printf("error ");
}

void pop(){
	if(top>0)	printf("%d ",a[top--]);
	else	printf("error ");
}

int main(){
	int op,n;
	while(1){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&n);
			push(n);
		}
		else if(op==0)	pop();
		else if(op==-1)	break;
	}
	return 0;
}

