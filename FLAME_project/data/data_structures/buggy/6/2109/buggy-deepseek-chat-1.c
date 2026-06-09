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
            scanf("%d %d",&a,&op); // @@ [Error: This scanf reads both the value and the next operation, but the input format separates operations by spaces, so after reading the value, the next integer is the next operation. However, this approach skips the pop operation (0) when it appears after a push, because it reads the next operation into 'op' and then the loop continues, but the pop operation is never processed. The correct approach is to read only the value here and let the loop read the next operation separately.]
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ [Error: This scanf reads the next operation inside the else branch, but when op is 0 (pop), it should not read another operation here; instead, it should perform the pop and then let the loop read the next operation. This causes the program to skip the next operation after a pop, leading to incorrect behavior.]
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