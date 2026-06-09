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
        printf("error "); // @@ [When the stack is empty, this function prints "error " but still returns an undefined value (since there's no return statement in this branch). The calling code in main() always prints the return value of pop(), leading to undefined behavior and incorrect output.]
    else
        return s[top--];
}

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op); // @@ [The loop condition checks `op != EOF`, but `scanf` returns the number of successfully read items, not the value of `op`. When input ends, `scanf` returns EOF (typically -1), which gets stored in `op`, so the loop continues incorrectly. Also, if `scanf` fails to read (e.g., end of input), `op` remains uninitialized or holds previous value, causing undefined behavior.]
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            printf("%d ", pop(stack)); // @@ [This line always prints the return value of pop(), even when the stack is empty. In the empty case, pop() prints "error " but returns an undefined value (due to missing return), so this prints garbage after "error ".]
        }
    }while(op != EOF); // @@ [This condition is wrong: it should check the return value of scanf, not the value of `op`. Since -1 (EOF) is a valid operation terminator per problem description, but here the loop stops only when op equals EOF, which may never happen if input ends normally. Also, the problem says operations end with -1, not EOF.]
    return 0;
}