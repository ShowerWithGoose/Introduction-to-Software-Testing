#include<stdio.h>
#define STACK_DATA_MAXSIZE (100)//修改最大栈长
typedef int STACK_ELEMENT_TYPE; //修改栈元类型
typedef struct ThisIsStack{//  >读栈首
	STACK_ELEMENT_TYPE ELEM[STACK_DATA_MAXSIZE];
	int top;
}stack;
int stack_pushback(stack*SAK,STACK_ELEMENT_TYPE*e){
	if(SAK->top>STACK_DATA_MAXSIZE)return 0;
	SAK->ELEM[SAK->top++]=*e;
	return 1;
}
int stack_popup(stack*SAK,STACK_ELEMENT_TYPE*e){
	if(!SAK->top)return 0;
	*e=SAK->ELEM[--SAK->top];
	return 1;
}
int stack_visit(stack*SAK,STACK_ELEMENT_TYPE*e){
	if(!SAK->top)return 0;
	*e=SAK->ELEM[SAK->top-1];
	return 1;
}
#define StackEmpty(s) !s.top
#define Stackfull(s) s.top==STACK_DATA_MAXSIZE
int main(){
    stack s={};
    int n;
    while(~scanf("%d",&n)&&n!=-1){
        switch(n){
            case 1:
                scanf("%d",&n);
                if(!(stack_pushback(&s,&n)))printf("error ");
                break;
            case 0:
                if(stack_popup(&s,&n))printf("%d ",n);
                else printf("error ");
                break;
        }
    }
    return 0;
}
