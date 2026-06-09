#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top; // @@ The variable 'top' is not initialized to -1. It should be initialized in main or globally to ensure the stack starts empty.
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
            scanf("%d %d",&a,&op); // @@ This line reads the next operation code into 'op' immediately after reading the value to push. This causes the loop to skip processing the next operation correctly if it's a pop (0) or another push, because the loop structure expects to read 'op' at the start or end specifically. More critically, if the next operation is 0 (pop), this scanf consumes it, and the loop continues. However, the logic flow is flawed because if op becomes 0 here, the loop goes to the else block which tries to scanf again for op, consuming the *next* token incorrectly.
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ This line attempts to read the next operation code. However, because the previous if-block also consumed an operation code, the synchronization of reading operations is broken. Specifically, after a push, 'op' holds the next command. If that command was 0, we enter the else block, but then we scanf again, skipping the actual command intended for this iteration or misaligning the input stream.
            pop(stack);
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