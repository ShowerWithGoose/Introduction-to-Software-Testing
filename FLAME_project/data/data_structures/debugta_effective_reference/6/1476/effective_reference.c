#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElemType;

void push(ElemType stack[], ElemType item);
void pop(ElemType stack[]);
int isFull(ElemType stack[]);
int isEmpty(ElemType stack[]);

typedef int ElemType;
ElemType stack[MAXSIZE];
int top = -1;

int main()
{
    int Element, item;
    while (scanf("%d", &Element) != EOF){
        if (Element == 0)
            pop(stack);
        else if (Element == 1){
            scanf("%d", &item);
            push(stack, item);
        }
        else if (Element == -1)
            break;
    }

    return 0;
}


void push(ElemType stack[], ElemType item)
{
    if (isFull(stack))
        printf("error ");
    else
        stack[++top] = item;
}

void pop(ElemType stack[])
{
    if (isEmpty(stack))
        printf("error ");
    else
        printf("%d ", stack[top--]);
}

int isFull(ElemType stack[])
{
    return top == MAXSIZE - 1;
}

int isEmpty(ElemType stack[])
{
    return top == -1;
}

