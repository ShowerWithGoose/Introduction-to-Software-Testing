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
        printf("error "); // @@ [When the stack is empty, this function prints "error " but still returns an undefined (garbage) value because there's no return statement in this branch. This causes undefined behavior when the caller tries to print the returned value.]
    else
        return s[top--];
}

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op); // @@ [The loop condition checks `op != EOF`, but `scanf` returns the number of successfully read items, not the value of `op`. When input ends, `scanf` returns EOF (typically -1), which gets stored in `op`, but the loop condition will then compare that -1 against EOF again incorrectly. Also, if `scanf` fails to read an integer (e.g., at end-of-file), `op` remains uninitialized or holds previous value, leading to incorrect behavior. The correct approach is to check the return value of `scanf` directly in the loop condition.]
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            printf("%d ", pop(stack)); // @@ [If pop() prints "error ", it still returns an undefined value which is then printed by this printf, resulting in printing both "error " and garbage (or causing undefined behavior). The design should avoid returning a value when an error occurs.]
        }
    }while(op != EOF); // @@ [This condition is logically flawed: `op` is the operation code (1, 0, or -1), but EOF is a return value from `scanf`, not a valid operation. The input ends with operation -1, not EOF. The problem states that -1 represents end of operations, so the loop should terminate when op == -1, not when op == EOF. Additionally, using `do-while` means the loop runs at least once even if the first read fails.]
    return 0;
}