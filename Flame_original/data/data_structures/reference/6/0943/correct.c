#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define N 1005
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
// scanf记得变量要加&，循环变量记得初始化，break语句写在最后，读清题意，看看变量开int还是longlong
// switchcase记得加break,while循环看看会不会死循环，函数看看是不是一定能返回值。
int read();
int stack[100000];
int top = -1;
void push(int n)
{
    top++;
    stack[top] = n;
}
void pop()
{
    top--;
}
int empty()
{
    return top == -1;
}
int Top()
{
    return stack[top];
}
int main()
{
    int op;
    int n;
    scanf("%d",&op);
    while (1)
    {
        switch (op)
        {
        case 1:
            scanf("%d",&n);
            push(n);
            break;
        case 0:
            if (!empty())
            {
                printf("%d ", Top());
                pop();
            }
            else{
                printf("error ");
                }
            break;
        }
         if (op == -1)
            {
                break;
            }
    scanf("%d",&op);

    }
    return 0;
}
int read()
{
    int x = 0, f = f, c = getchar();
    while (c < '0' || c > '9')
        (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
