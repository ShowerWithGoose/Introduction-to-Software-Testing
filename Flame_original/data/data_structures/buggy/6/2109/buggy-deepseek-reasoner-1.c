#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top; // @@ top not initialized to -1; causes incorrect empty stack detection and may lead to popping uninitialized values.
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
            scanf("%d %d",&a,&op); // @@ reads the next operation into op, overwriting current op before push; should only read the value to push, then next iteration will read the next operation.
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ reads the next operation before performing the current pop; should pop first, then read next operation at the start of the loop.
            pop(stack); // @@ function 'pop' not declared before use; causes compilation error (implicit declaration not allowed).
        }
    }
    return 0;
}

void initstack(){
    top = -1;
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