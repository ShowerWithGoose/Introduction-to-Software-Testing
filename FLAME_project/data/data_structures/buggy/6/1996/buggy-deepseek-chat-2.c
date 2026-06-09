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
    push(p,ente); // @@ [Error: The return value of push() is not checked. When the stack is full (capacity 100), push() returns 1, but the program ignores this and does not output "error".]
    }
    else if(oper==0){
    pop(p,x); // @@ [Error: This line calls pop() but discards its return value, then the next line calls pop() again, causing a double pop. This results in incorrect popped values and missing "error" output when the stack is empty.]
    if(pop(p,x)==1){ // @@ [Error: The condition is inverted. According to the function, pop() returns 1 on error (empty stack), but here it prints *x when pop returns 1, which is wrong. It should print "error" when pop returns 1.]
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}