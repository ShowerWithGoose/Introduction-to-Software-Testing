#include<stdio.h> 
#include<stdlib.h>

#define ElemType int
#define Stack_Init_Size 100
#define StackIncrement 100
typedef int Status;
typedef struct{
	ElemType * base;
	ElemType * top;
	int stacksize;//栈的最大长度 
}SqStack;


Status InitStack(SqStack *S);
Status EmptyStack(SqStack *S);
Status FullStack(SqStack *S);
Status LengthStack(SqStack *S);
Status PushStack(SqStack *S, ElemType e);
Status PopStack(SqStack *S,ElemType *e);
Status DestroyStack(SqStack *S);


int main()
{	
	int i=0,j=0,k=0,e=0;
	SqStack q,*S;
	S=&q;
	InitStack(S);
	int order,op;
	while(scanf("%d",&op)!=EOF){
		
		if(op==1) {
			if(FullStack(S))
				printf("error ");
			else {
				scanf("%d",&op);
				PushStack(S,op);
			}
		}
		
		else if(op==0) {
			if(EmptyStack(S))
				printf("error ");
			else{
				PopStack(S,&e);
				printf("%d ",e);
			}
		}
		
		else if(op==-1){
			break;
		}
			
	}
	DestroyStack(S);
	return 0;
			
	}
	
	
	



Status InitStack(SqStack *S)
{
	S->base=(ElemType *)malloc(Stack_Init_Size*sizeof(ElemType));
	if(S->base==NULL)
		exit(0);//?
	S->top=S->base;
	S->stacksize=Stack_Init_Size;
	return 1;
}

Status EmptyStack(SqStack *S){
	return S->base==S->top;
} 

Status FullStack(SqStack *S){
	return (S->top-S->base)==S->stacksize;
}

Status LengthStack(SqStack *S){
	if(S->base==S->top) 
		return 0;
	return (Status)(S->top-S->base);
}

Status PushStack(SqStack *S, ElemType e) {
	if(S->top-S->base>=S->stacksize) {
		S->base=(ElemType*)realloc(S->base,(S->stacksize+StackIncrement));
		if(!S->base) return 0;
		S->top=S->base+S->stacksize;
		S->stacksize+=StackIncrement;
	}
	//
	*S->top++=e;
	return 1;
}

Status PopStack(SqStack *S,ElemType *e)
{
	if(S->base==S->top) return 0;
	*e=*--S->top;
	return 1;
}

Status DestroyStack(SqStack *S){
	free(S->base);
	S->base=S->top=NULL;
	S->stacksize=0;
	return 1;
	
}






