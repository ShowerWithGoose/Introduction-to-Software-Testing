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
    push(p,ente); // @@ The return value of push is not checked; if the stack is full (p->top == Max-1), push returns 1 but the program continues without printing "error". According to the problem, a push on a full stack should output "error ".
    }
    else if(oper==0){
    pop(p,x); // @@ This line calls pop(p,x) but discards its return value, then calls pop(p,x) again in the next line. This causes the pop to be performed twice for a single '0' operation, and the first pop's result is lost. The logic should check the return value of a single pop call.
    if(pop(p,x)==1){ // @@ This calls pop again, performing a second pop. If the first pop succeeded, this second pop may pop a different element or cause an error. The condition is also inverted: pop returns 1 on error (empty stack), but here it prints *x when pop returns 1, which is wrong.
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}