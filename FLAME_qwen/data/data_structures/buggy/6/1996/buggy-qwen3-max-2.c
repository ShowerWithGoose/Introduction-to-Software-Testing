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
    stack*p=(stack*)malloc(sizeof(stack)); @@ [Missing check for malloc failure, though not the primary error]
    inistack(p);
    int ente=0;
    int oper=0;
    int*x=(int *)malloc(sizeof(int)); @@ [Unnecessary dynamic allocation; could just use int variable]
    do{
    scanf("%d",&oper);
    if(oper==1){
    scanf("%d",&ente);
    push(p,ente);
    }
    else if(oper==0){
    pop(p,x);  @@ [pop is called twice: once here (result ignored), then again in if condition]
    if(pop(p,x)==1){ @@ [This calls pop a second time, causing double pop and wrong output]
    printf("%d ",*x); @@ [If pop fails (returns 1), *x is uninitialized or stale; also logic inverted]
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}