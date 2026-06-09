#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#define eps 1 e - 7
#define STACK_SIZE 100
struct Stack
{
    int data[STACK_SIZE];
    int top; //空栈top为-1
};

void initStack(struct Stack *stack) //定义一个栈
{
    stack->top = -1;
}
int isEmpty(struct Stack *stack) //验空,空1非空0
{
    return (stack->top == -1) ? 1 : 0;
}
int isFull(struct Stack *stack) //验满，满1非满0
{
    return (stack->top == STACK_SIZE - 1) ? 1 : 0;
}
int push(struct Stack *stack, int value) //压栈
{
    if (isFull(stack))
    {
        return 0;
    }
    stack->data[++stack->top] = value;
    return 1;
}
int pop(struct Stack *stack, int *retValue) //出栈
{
    if (isEmpty(stack))
    {
        return 0;
    }
    *retValue = stack->data[stack->top--];
    return 1;
}
void printStack(struct Stack *stack) //全输出栈中元素
{
    if (isEmpty(stack))
    {
        printf("isEmpty\n");
        return;
    }
    printf("Content:\n");
    for (int i = stack->top; i > -1; i--)
    {
        printf("[%d]:%d\n", i, stack->data[i]);
    }
    printf("End\n");
}
int main()
{
    struct Stack stack;
    initStack(&stack);
    int data;
    int out;
    int op = 0;
    while (1)
    {
        // printf("top:%d\n", stack.top);
        scanf("%d", &op);
        if (op == -1)
            break;
        if (op == 1) //入栈，栈满输出“error ”
        {
            scanf("%d", &data);
            if (isFull(&stack))
                printf("error1 ");
            if (!isFull(&stack))
            {
                push(&stack, data);
            }
        }
        if (op == 0) //出栈，如果空输出“error ”
        {
            if (isEmpty(&stack))
                printf("error ");
            if (!isEmpty(&stack))
            {
                pop(&stack, &out);
                printf("%d ", out);
            }
        }
    }
    //printStack(&stack);

    getchar();
    return 0;
}
