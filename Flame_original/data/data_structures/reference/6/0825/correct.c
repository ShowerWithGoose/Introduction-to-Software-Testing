#include<stdio.h>
#define M 100
int a[100];
int top=-1;
int full(void);
int empty(void);
void push(int x);
void pop(void);
int main(){
	int x;
	int n;
	while(1){
		scanf("%d",&x);
		if(x==1){
			scanf("%d",&n);
			push(n);
			continue;
		}else if(x==0){
			pop();
			continue;
		}else if(x==-1){
			break;
		}
	}
	return 0;
}
int full(void){
	return (top==M-1);
}
int empty(void){
	return (top==-1);
}
void push(int x){
	if(full()){
		printf("error ");
	}else{
		a[++top]=x;
	}
}
void pop(void){
	if(empty()){
		printf("error ");
	}else{
		printf("%d ",a[top--]);
	}
}


