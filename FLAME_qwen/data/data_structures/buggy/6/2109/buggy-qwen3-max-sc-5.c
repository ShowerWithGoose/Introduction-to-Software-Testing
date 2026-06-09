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
            scanf("%d %d",&a,&op); @@ [Incorrect input reading: reads two integers after '1', but the input format specifies only one value to push; also overwrites 'op' prematurely, breaking loop logic]
            push(stack,a);
        }
        else{
            scanf("%d",&op); @@ [Unnecessary read of next operation inside pop branch; causes skipping of operations and misalignment in input processing]
            pop(stack); @@ [Function 'pop' is declared without a prototype before use, leading to compilation error]
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

void pop(int stack[]){ @@ [Function 'pop' is defined after being called in main, and no prototype was declared before main, causing implicit function declaration error in strict C standards]
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