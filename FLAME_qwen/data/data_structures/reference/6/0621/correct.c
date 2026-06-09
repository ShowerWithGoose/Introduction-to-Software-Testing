#include<stdio.h>
#include<string.h>
int stack[1005];
int top=-1;
void push(int a[],int item);
void pop(int a[]);

int main(){
	int sign;
	int num;
	while(scanf("%d",&sign)!=-1){
		if(sign==1){
			scanf("%d",&num);
			push(stack,num);
		}
		if(sign==0){
			pop(stack);
		}
	}
	return 0;
} 

void push(int a[],int item){
	if(top==1004) printf("error ");
	else a[++top]=item;
}

void pop(int a[]){
	if(top==-1) printf("error ");
	else printf("%d ",a[top--]);
}

