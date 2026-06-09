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
int Top = -1;

int main()
{
    int op, num;
    while (scanf("%d", &op) != EOF){
        if (op == 0)
            pop(stack);
        else if (op == 1){
            scanf("%d", &num);
            push(stack, num);
        }
        else if (op == -1)
            break;
    }

    return 0;
}


void push(ElemType stack[], ElemType item)
{
    if (isFull(stack))
        printf("error ");
    else
        stack[++Top] = item;
}

void pop(ElemType stack[])
{
    if (isEmpty(stack))
        printf("error ");
    else
        printf("%d ", stack[Top--]);
}

int isFull(ElemType stack[])
{
    return Top == MAXSIZE - 1;
}

int isEmpty(ElemType stack[])
{
    return Top == -1;
}

