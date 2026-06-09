#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top;
void initstack();
int isempty();
int isfull();
void push(int stack[],int a);
void error(char s[]);
int main()
{
    int op,a;
    scanf("%d",&op);
    while(op != -1){
        if(op == 1){
            scanf("%d %d",&a,&op); // @@ [Incorrect input reading: reads two integers at once, causing the next operation to be consumed prematurely and skipping proper handling of subsequent operations]
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ [Incorrect input reading: for pop (op == 0), it reads the next operation immediately, but doesn't handle the current pop operation correctly; also causes misalignment in input sequence]
            pop(stack);
        }
    }
    return 0;
}

void initstack(){
    top = -1; // @@ [initstack() is never called, so 'top' remains uninitialized (global default is 0), leading to incorrect stack state]
}

int isempty(){
    return top == -1;
}

int isfull(){
    return top == MAXSIZE - 1;
}

void push(int stack[],int a){
    if(isfull() ){
        printf("error ");
    }
    else{
        stack[++top] = a;
    }
}

void pop(int stack[]){
    if(isempty() ){
        printf("error ");
    }
    else{
        printf("%d ",stack[top--]);
    }
}

void error(char s[]){
    printf("%s",s);
}