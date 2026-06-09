#include<stdio.h>
#include<malloc.h>

typedef struct{
	int data[100];
	int top;
	int bottom;
}stack;

stack *StackCreate(){
	stack *aaa=(stack*)malloc(sizeof(stack));
	if(aaa==NULL)
	return 0;
	aaa->bottom=aaa->top=0;
	return aaa;
}

void StackInput(stack *aaa,int str){
	aaa->data[aaa->top]=str;
	aaa->top++;
}

int StackOutput(stack *aaa){
	int str;
	if(aaa->top!=aaa->bottom){
		str=aaa->data[aaa->top-1];
		aaa->top--;
		return str;
	}
	else 
	return 0;
}

int main(){
	int type[202];
	int i=0,i0,a;
	stack *aaa;
	aaa=StackCreate();
	for(i=0;type[i-1]!=-1;i++){
		scanf("%d",&type[i]);
	} 
	i0=i;
	for(i=0;i<i0;i++){
		if(type[i]==1){
			if(aaa->top!=100){
			StackInput(aaa,type[i+1]);
			i++;
		}
			else 
			printf("error ");
		}
		else if(type[i]==0){
			a=StackOutput(aaa);
			if(a==0){
				printf("error ");
			}
			else{
				printf("%d ",a);
			}
		}
	}
} 

