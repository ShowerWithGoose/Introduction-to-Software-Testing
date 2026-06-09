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
    push(p,ente);
    }
    else if(oper==0){
    pop(p,x); // @@ The first call to pop performs the actual pop operation and stores the value in x, but its return value (success/failure) is ignored.
    if(pop(p,x)==1){ // @@ This second call to pop attempts to pop again. If the stack was not empty after the first pop, this changes the state further and returns 0 (success), causing the logic below to print "error" incorrectly. If the stack became empty after the first pop, this returns 1 (failure), causing the code to print the value from the first pop as if it were an error case, or worse, print garbage/old value. The logic for checking success/failure and printing is completely inverted and duplicated.
    printf("%d ",*x);
    }
    else 
    printf("error ");
    }
    }while(oper!=-1);
    return 0;
}