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
    stack*p=(stack*)malloc(sizeof(stack));
    inistack(p);
    int ente=0;
    int oper=0;
    int*x=(int *)malloc(sizeof(int));
    do{
    scanf("%d",&oper);
    if(oper==1){
    scanf("%d",&ente);
    push(p,ente); // @@ The return value of push is ignored, failing to print "error " when the stack is full.
    }
    else if(oper==0){
    pop(p,x);  // @@ Unnecessary first call to pop, which incorrectly decrements the stack top and modifies *x before the check.
    if(pop(p,x)==1){ // @@ Calls pop a second time, causing double decrement. The condition checks for error (return 1) but executes the success branch, reversing the logic.
    printf("%d ",*x); // @@ Prints the popped value when pop actually failed due to the reversed condition.
    }
    else 
    printf("error "); // @@ Prints "error " when pop actually succeeded due to the reversed condition.
    }
    }while(oper!=-1);
    return 0;
}