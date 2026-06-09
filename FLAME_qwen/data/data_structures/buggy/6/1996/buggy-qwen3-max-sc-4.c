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
    stack*p=(stack*)malloc(sizeof(stack)); @@ // Missing check for malloc failure, but more critically, missing #include <stdlib.h> is already present so this isn't the issue. However, the real error is logic in pop handling.
    inistack(p);
    int ente=0;
    int oper=0;
    int*x=(int *)malloc(sizeof(int)); @@ // Unnecessary dynamic allocation; could just use a local int variable. But not the main bug.
    do{
    scanf("%d",&oper);
    if(oper==1){
    scanf("%d",&ente);
    push(p,ente);
    }
    else if(oper==0){
    pop(p,x);  @@ // First call to pop() discards its return value and overwrites *x even if stack is empty (which causes undefined behavior when stack is empty because *y is assigned before checking return).
    if(pop(p,x)==1){ @@ // Second call to pop() again modifies the stack (double pop!) and also uses uninitialized *x if first pop failed. Logic is inverted: return 1 means error, but then it prints *x which is invalid.
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}