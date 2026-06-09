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
        printf("%d ", s[top]);
        return s[top--]; // @@ Missing braces for the else block causes this statement to execute unconditionally, leading to out-of-bounds array access and incorrect stack state when the stack is empty.
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