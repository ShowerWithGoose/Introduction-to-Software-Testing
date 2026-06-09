#include <stdio.h>
#include <malloc.h>
#define MAXSIZE 100
typedef struct{
    int data[MAXSIZE];
    int top;
}SeqStack;
SeqStack* Init_SeqStack(){  //栈初始化
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    if(!s){
        printf("空间不足\n");
        return NULL;
    }else{
        s->top = -1;
        return s;
    }
}
int Empty_SeqStack(SeqStack* s){  //判栈空
    if(s->top == -1) return 1;
    else return 0;
}
int Push_SeqStack(SeqStack* s, int x){  //入栈
    if(s->top == MAXSIZE - 1) return 0;//栈满不能入栈
    else{
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}
int Pop_SeqStack(SeqStack* s, int* x){  //出栈
    if(Empty_SeqStack(s)) return 0;//栈空不能出栈
    else{
        *x = s->data[s->top];
        s->top--;
        return 1;
    }//栈顶元素存入*x，返回
}
int main(){
	int control,input,output;
	SeqStack *L;
	L=Init_SeqStack();
	scanf("%d",&control);
	while(control!=-1){
		if(control==1){
			scanf("%d",&input);
			if(Push_SeqStack(L,input)==0)	printf("error ");
		}
		else if(control==0){
			if(Pop_SeqStack(L,&output)==0) printf("error ");
			else printf("%d ",output);
		}
		scanf("%d",&control);
	} 
	return 0;
}

