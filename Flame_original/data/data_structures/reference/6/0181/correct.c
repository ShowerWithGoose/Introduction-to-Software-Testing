#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int stack[100];
int top=-1;

void pop(){
	if(top==-1){
		printf("error ");
		return ;
	}
	printf("%d ",stack[top--]);
	return ;
}
void push(int dat){
	if(top==99){
		printf("error ");
		return ;
	}
	stack[++top]=dat;
	return ;
}
int main(){
	int a,b;
	scanf("%d",&a);
	while(a!=-1){
		if(a==0){
			//≥ˆ’ª 
			pop();
		}else if(a==1){
			//»Î’ª 
			scanf("%d",&b);
			push(b);
		} 
		scanf("%d",&a);
	}
	
	return 0;
}

