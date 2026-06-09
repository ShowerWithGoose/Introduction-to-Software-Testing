#include <stdio.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top;

void initstack()
{
    top = -1;
}

int isempty()
{
    return top == -1;
}

int isfull()
{
    return top == MAXSIZE-1;
}

void push(int s[ ], int item)
{
    if(isfull())
        printf("error ");
    else
        s[++top] = item;
}

int pop(int s[])
{
    if(isempty())
        printf("error "); // @@ [When the stack is empty, this function prints "error " but still returns an undefined (garbage) value because there's no return statement in this branch. The calling code then prints that garbage value as "%d ", leading to incorrect output.]
    else
        return s[top--];
} // @@ [Missing return statement in the empty case causes undefined behavior when the function is expected to return an int.]

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            printf("%d ", pop(stack)); // @@ [If pop() prints "error " due to empty stack, it still returns an undefined value which is printed here as "%d ", resulting in "error <garbage> " instead of just "error ".]
        }
    }while(op != EOF); // @@ [The loop condition is incorrect: 'op' is never equal to EOF because scanf returns EOF, not store it in 'op'. This causes infinite loop or undefined behavior. Also, the problem specifies that input ends with -1, not EOF.]
    return 0;
}