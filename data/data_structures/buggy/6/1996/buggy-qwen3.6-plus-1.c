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
    push(p,ente); // @@ The return value is ignored; if push returns 1 (stack full), "error " should be printed.
    }
    else if(oper==0){
    pop(p,x); // @@ Unnecessary first call to pop; it modifies the stack state before checking the result.
    if(pop(p,x)==1){ // @@ Calls pop a second time, causing incorrect double pop; also, the condition is inverted since pop returns 1 on error.
    printf("%d ",*x); // @@ Executes when pop returns 1 (error), which incorrectly prints the value instead of handling the error.
    }
    else 
    printf("error "); // @@ Executes when pop returns 0 (success), which incorrectly prints error instead of the popped value.
    }
    }while(oper!=-1);
    
    return 0;
}