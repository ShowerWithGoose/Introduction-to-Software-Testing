#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAXSIZE 100
typedef int ElemType;
ElemType stack[MAXSIZE];
int top;
void  initStack()
{
    top = -1;
}
int  isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAXSIZE-1;
}
void  push(ElemType s[], ElemType item) {
    if (isFull())
        printf("error ");
    else
        s[++top] = item;
}
ElemType pop(ElemType s[])
{
    if (isEmpty())
        printf("error ");
    else
        printf("%d ", s[top]); // @@ This line prints the top element before decrementing top, but the return statement below always executes, causing the element to be printed twice on a successful pop and the top to be decremented even when the stack is empty.
        return s[top--]; // @@ This line always executes, including after an empty stack error, causing undefined behavior (accessing s[-1]) and decrementing top below -1. Additionally, on a successful pop, it prints the element again via the return value in main (which is ignored), but the main function does not print the return value, so this is not the primary issue.
}

int main() {
    initStack();
    int n, x;
    while (scanf("%d", &n)) {
        if (n == -1)break;
        else if (n == 1) {
            scanf("%d", &x);
            push(stack, x);
        }
        else if (n == 0)pop(stack);
    }
    return 0;
}