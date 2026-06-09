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
    stack*p=(stack*)malloc(sizeof(stack)); // @@ [Missing check for malloc failure, though not the primary error causing wrong output]
    inistack(p);
    int ente=0;
    int oper=0;
    int*x=(int *)malloc(sizeof(int)); // @@ [Unnecessary dynamic allocation; could be a simple int variable]
    do{
    scanf("%d",&oper);
    if(oper==1){
    scanf("%d",&ente);
    push(p,ente);
    }
    else if(oper==0){
    pop(p,x);  // @@ [pop is called twice: once here (discarded result), and again in the if condition below]
    if(pop(p,x)==1){ // @@ [This calls pop a second time, popping another element or returning error incorrectly; also logic inverted: return 1 means error, but then it prints *x which is undefined in error case]
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}