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
        printf("error ");
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
            if (isempty()) { // @@ The original code directly prints the return value of pop. If the stack is empty, pop prints "error " but returns an undefined/garbage value (or 0 depending on compiler/state), which is then printed as a number. We need to check emptiness before calling pop or handling the output to match the expected behavior where "error " is printed instead of a number.
                printf("error ");
            } else {
                printf("%d ", pop(stack));
            }
        }
    }while(op != -1); // @@ The loop condition should check for op != -1 as per the problem description ("-1 represents the end of operations"). The original code checks for EOF, which will cause the loop to continue indefinitely or behave incorrectly when -1 is encountered, as -1 is a valid integer input, not necessarily EOF. Also, the problem states -1 ends operations, so we must break or stop when op is -1.
    return 0;
}