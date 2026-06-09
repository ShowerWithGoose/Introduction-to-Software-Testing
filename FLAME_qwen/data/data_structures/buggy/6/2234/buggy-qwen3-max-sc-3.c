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
        printf("error "); // @@ [When the stack is empty, the function prints "error " but still returns an undefined value (since there's no return statement in this branch), which leads to undefined behavior when the caller tries to print the returned value.]
    else
        return s[top--];
}

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op); // @@ [The loop condition checks `op != EOF`, but `scanf` returns the number of successfully read items, not the value of `op`. When input ends, `scanf` returns EOF (typically -1), so `op` will be uninitialized or hold the last value, and the loop may not terminate correctly. Also, if `scanf` fails to read an integer (e.g., at end of input), `op` remains unchanged, leading to infinite loop or incorrect behavior.]
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            printf("%d ", pop(stack)); // @@ [If pop() prints "error ", it still returns an undefined value (due to missing return in error case), so this printf will print garbage after "error ". Also, even if pop() printed "error ", this line would print another value, causing double output like "error <garbage> ".]
        }
    }while(op != EOF); // @@ [This condition is incorrect: it should check the return value of scanf, not the value of `op`. The correct approach is to check if scanf returned 1 (successfully read an integer). As written, when input ends, scanf returns EOF, `op` is not updated, and the loop may run indefinitely or process stale data.]
    return 0;
}