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
	int n[202];
	int i=0,i0,ans;
	stack *p;
	p=StackCreate();
	for(i=0;n[i-1]!=-1;i++){
		scanf("%d",&n[i]);
	} 
	i0=i;
	for(i=0;i<i0;i++){
		if(n[i]==1){
			if(p->top!=100){
			StackInput(p,n[i+1]);
			i++;
		}
			else 
			printf("error ");
		}
		else if(n[i]==0){
			ans=StackOutput(p);
			if(ans==0){
				printf("error ");
			}
			else{
				printf("%d ",ans);
			}
		}
	}
} 

