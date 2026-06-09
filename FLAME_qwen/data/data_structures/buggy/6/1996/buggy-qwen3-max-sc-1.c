#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define arrLen(x) (sizeof(x)/sizeof(x[0]))
#define Max 100
typedef struct{
    int data[Max];
    int top;
}stack; 
void inistack(stack*p){
    p->top=-1;
}
int push(stack*p,int x){
    if(p->top==Max-1){
    return 1;
    }
    (p->top)++;   
    p->data[p->top]=x;
    return 0;
}
int pop(stack*p,int *y){
    if(p->top==-1){ 
    return 1;
    }
    *y=p->data[p->top];
    (p->top)--;
    return 0;
}
int main(){
    stack*p=(stack*)malloc(sizeof(stack)); @@ // Missing check for malloc failure, but not the main error here
    inistack(p);
    int ente=0;
    int oper=0;
    int*x=(int *)malloc(sizeof(int)); @@ // Unnecessary dynamic allocation; could just use int x;
    do{
    scanf("%d",&oper);
    if(oper==1){
    scanf("%d",&ente);
    push(p,ente);
    }
    else if(oper==0){
    pop(p,x);  @@ // First call to pop modifies the stack and stores value in *x
    if(pop(p,x)==1){ @@ // Second call to pop again! This pops another element (or fails again), causing logic error
    printf("%d ",*x); @@ // If first pop succeeded but second failed, *x is from first pop but condition says error
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}