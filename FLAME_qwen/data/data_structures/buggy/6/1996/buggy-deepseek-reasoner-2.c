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
    push(p,ente); // @@ [Error: Return value of push() ignored; should check if push fails (returns 1) and print "error "]
    }
    else if(oper==0){
    pop(p,x); // @@ [Error: This first pop call is unnecessary and leads to double pop; should remove this line and only call pop inside the condition]
    if(pop(p,x)==1){ // @@ [Error: Calling pop again here causes double pop; logic reversed: if pop returns 1 (empty), should print "error ", else print the popped value]
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}