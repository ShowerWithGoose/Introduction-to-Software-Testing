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
        printf("error "); // @@ [When the stack is empty, this function prints "error " but still returns an undefined (garbage) value because there's no return statement in the if branch. This causes undefined behavior when the caller tries to print the returned value.]
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
            printf("%d ", pop(stack)); // @@ [If pop() prints "error " due to an empty stack, it still returns an undefined value, which is then printed as "%d ", leading to garbage output or undefined behavior. Additionally, the loop condition `op != EOF` is incorrect because `scanf` returns the number of successfully read items, not the value of `op`; when input ends, `scanf` fails and `op` remains unchanged, potentially causing an infinite loop. Also, the problem specifies that -1 terminates the input, but the loop only checks for EOF.]
        }
    }while(op != EOF); // @@ [The loop should terminate when op == -1 as per problem description, not only on EOF. Also, comparing op (which holds operation codes like 1, 0, -1) directly to EOF is incorrect because EOF is a return value of scanf, not a value stored in op.]
    return 0;
}