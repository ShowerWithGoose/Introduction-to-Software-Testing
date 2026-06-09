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
        printf("error "); // @@ [When the stack is empty, the function prints "error " but still returns an undefined value (since there's no return statement in this branch). This causes undefined behavior when the caller tries to print the returned value.]
    else
        return s[top--];
} // @@ [Missing return statement in the 'if(isempty())' branch leads to undefined behavior because the function is expected to return an int in all paths.]

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
            printf("%d ", pop(stack)); // @@ [If pop() encounters an empty stack, it prints "error " but also returns an undefined value, which is then printed as "%d ", leading to incorrect output like "error <garbage> ".]
        }
    }while(op != EOF); // @@ [The loop condition is incorrect: 'op != EOF' will not terminate properly because 'scanf' returns the number of successfully read items, not the value of 'op'. When input ends, 'scanf' returns EOF, but 'op' retains its last value, causing an infinite loop or undefined behavior. Also, the problem specifies that -1 ends the operations, but this code doesn't check for -1.]
    return 0;
}