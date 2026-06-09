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
        printf("error "); // @@ [When the stack is empty, this function prints "error " but still returns an undefined (garbage) value, which is then printed in main. This leads to printing both "error " and a garbage number. The function should not return a value in the error case, or main should not print the return value unconditionally.]
    else
        return s[top--];
}

int main()
{
    int op, item;
    initstack();
    do{
        scanf("%d", &op); // @@ [The loop condition checks `op != EOF`, but `scanf` returns the number of successfully read items, not the value of `op`. If input ends, `scanf` returns EOF (typically -1), so `op` will be uninitialized or retain its last value, leading to incorrect behavior. Also, when `scanf` fails (e.g., at end of input), `op` is not updated, causing potential infinite loop or processing invalid `op`.]
        if(op == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if(op == 0){
            printf("%d ", pop(stack)); // @@ [This always prints the return value of pop(), even when pop() prints "error ". In the error case, pop() does not return a valid integer, so printing it results in undefined behavior (garbage output).]
        }
    }while(op != EOF); // @@ [This condition is incorrect. It should check the return value of scanf, not the value of `op`. Since -1 is a valid operation (end marker), but EOF is not the same as op==-1, the loop may not terminate correctly on end-of-file or may process -1 incorrectly. According to problem, -1 means end of operations, but this code doesn't handle -1 specially—it only stops on EOF, which may never occur if input ends with -1.]
    return 0;
}