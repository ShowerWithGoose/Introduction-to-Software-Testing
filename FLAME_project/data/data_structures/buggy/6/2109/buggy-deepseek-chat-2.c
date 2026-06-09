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
            scanf("%d %d",&a,&op); // @@ [Error: This reads both the push value and the next operation in one scanf, but the input format separates operations by spaces, so the next operation should be read in the next loop iteration. This causes the program to skip reading the next operation correctly, leading to incorrect behavior when a pop (0) follows a push.]
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ [Error: This reads the next operation inside the else branch, but the loop condition already expects op to be updated. This causes the program to read an extra integer, skipping operations and misinterpreting the input sequence.]
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