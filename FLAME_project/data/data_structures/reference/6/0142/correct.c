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
	int in[202];
	int i=0,i0,out;
	stack *p;
	p=StackCreate();
	for(i=0;in[i-1]!=-1;i++){
		scanf("%d",&in[i]);
	} 
	i0=i;
	for(i=0;i<i0;i++){
		if(in[i]==1){
			if(p->top!=100){
			StackInput(p,in[i+1]);
			i++;
		}
			else 
			printf("error ");
		}
		else if(in[i]==0){
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

