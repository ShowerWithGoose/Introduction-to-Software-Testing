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
    else // @@ 缺少花括号，导致下面的return语句不在else块内，无论栈是否为空都会执行return
        printf("%d ", s[top]);
        return s[top--]; // @@ 当栈为空时，top=-1，访问s[-1]导致越界，且逻辑错误
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