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
            scanf("%d %d",&a,&op); @@ [Incorrect input reading: after reading op==1, it should read only the value to push, not another op. This consumes the next operation as the pushed value's input, causing misalignment in processing subsequent operations.]
            push(stack,a);
        }
        else{
            scanf("%d",&op); @@ [Incorrect input reading: for pop (op==0), it should not read another integer. This overwrites op with the next input, skipping the actual next operation and causing logic errors.]
            pop(stack); @@ [Function 'pop' is called but was never declared before use; declaration is missing in the function prototype list above.]
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

void pop(int stack[]){ @@ [Function 'pop' is defined here but was not declared before being used in main(), leading to a compilation error in strict C standards (implicit function declaration).]
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