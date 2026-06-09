#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define MAX 101
int Min(int a,int b){return a<b?a:b;}
int Max(int a,int b){return a>b?a:b;}

struct Node{
    int data[MAX];
    int top;
}x;
typedef struct Node stack;
int input, i, op;

void initstack(stack *x)
{
    x->top = -1;
}

int pushstack(stack *x, int input)
{
    if ((x->top == MAX) != 0)
    {
        printf("error ");
        return 0;
    }
    x->top++;
    x->data[x->top] = input;
    return 1;
}

int popstack(stack *x, int input)
{
    if (x->top == -1)
    {
        printf("error ");
        return 0;
    }
    input = x->data[x->top];
    x->top--;
    printf("%d ", input);
    return 1;
}

int main(void)
{
    initstack(&x);
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        else if (op == 0)
            popstack(&x, input);
        else if (op == 1)
        {
            scanf("%d", &i);
            pushstack(&x, i);
        }
    }
    return 0;
}

