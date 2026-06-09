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
    push(p,ente); // @@ Missing check for push return value; should print "error " if push fails (stack full).
    }
    else if(oper==0){
    pop(p,x);  // @@ This call to pop is redundant and its return value is ignored; it causes a double pop or consumes an element.
    if(pop(p,x)==1){ // @@ Condition reversed: pop returns 0 on success, 1 on failure. Should check for 0 to print popped value, else print error.
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}