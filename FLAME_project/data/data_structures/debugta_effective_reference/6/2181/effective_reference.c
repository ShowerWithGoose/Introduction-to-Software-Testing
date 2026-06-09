#include<stdio.h>
#include<malloc.h>

typedef struct{
	int data[100];
	int top;
	int bottom;
}stack;

stack *StackCreate(){
	stack *p=(stack*)malloc(sizeof(stack));
	if(p==NULL)
	return 0;
	p->bottom=p->top=0;
	return p;
}

void StackInput(stack *p,int str){
	p->data[p->top]=str;
	p->top++;
}

int StackOutput(stack *p){
	int str;
	if(p->top!=p->bottom){
		str=p->data[p->top-1];
		p->top--;
		return str;
	}
	else 
	return 0;
}

int main(){
	int a[202];
	int n=0,i0,out;
	stack *p;
	p=StackCreate();
	for(n=0;a[n-1]!=-1;n++){
		scanf("%d",&a[n]);
	} 
	i0=n;
	for(n=0;n<i0;n++){
		if(a[n]==1){
			if(p->top!=100){
			StackInput(p,a[n+1]);
			n++;
		}
			else 
			printf("error ");
		}
		else if(a[n]==0){
			out=StackOutput(p);
			if(out==0){
				printf("error ");
			}
			else{
				printf("%d ",out);
			}
		}
	}
} 

