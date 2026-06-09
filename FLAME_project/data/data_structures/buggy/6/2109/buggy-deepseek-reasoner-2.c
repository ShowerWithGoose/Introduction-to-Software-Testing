#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top; // @@ top is not initialized; should be initialized to -1 (e.g., by calling initstack())
void initstack();
int isempty();
int isfull();
void push(int stack[],int a);
void error(char s[]);
int main()
{
    int op,a;
    scanf("%d",&op); // @@ missing call to initstack() before using stack; top is 0 by default, should be -1
    while(op != -1){
        if(op == 1){
            scanf("%d %d",&a,&op); // @@ incorrect: reads next operation code as well; should read only a, then read next op at loop beginning
            push(stack,a);
        }
        else{
            scanf("%d",&op); // @@ incorrect: reads next operation code before popping; should pop first then read next op
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