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
}

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
            printf("%d ", pop(stack)); // @@ [This always tries to print the return value of pop(), even when pop() prints "error ". When the stack is empty, pop() prints "error " but returns an undefined value, which is then printed as an integer followed by a space, causing malformed output like "error <garbage> ".]
        }
    }while(op != EOF); // @@ [The loop condition is incorrect. 'scanf' returns the number of successfully read items, not the value of 'op'. When input ends, scanf returns EOF (typically -1), but 'op' will hold the last successfully read value. Thus, the loop may never terminate or behave incorrectly. Also, the problem specifies that -1 marks end of operations, but this loop doesn't check for op == -1.]
    return 0;
}