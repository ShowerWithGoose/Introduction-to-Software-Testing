#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top; // @@ top is not initialized to -1; global zero initialization causes stack to appear non-empty, leading to logical errors.
void initstack();
int isempty();
int isfull();
void push(int stack[],int a);
void error(char s[]);
int main()
{
    int op,a;
    scanf("%d",&op); // @@ missing call to initstack() to set top to -1; without it, top remains 0, making stack appear non-empty.
    while(op != -1){
        if(op == 1){
            scanf("%d %d",&a,&op); // @@ incorrect input parsing: reads two integers at once, misaligning the sequence of operations.
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ incorrect input parsing: reads the next operation inside the pop branch, causing misalignment.
            pop(stack); // @@ pop() used without prior declaration; implicit int declaration conflicts with later void definition.
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