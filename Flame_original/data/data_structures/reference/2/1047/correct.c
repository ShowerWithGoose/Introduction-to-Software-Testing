#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct
{
    int data[100];
    int top;
} Stack;
char s[100];
void push(Stack *, int);
int pop(Stack *);
void calculate(Stack *, Stack *);
int main()
{
    Stack s_num, s_op;
    s_num.top = s_op.top = -1;
    int tag = 0;
    gets(s);
    for (int i = 0; s[i] != '='; i++)
    {
        if (s[i] == ' ')
            continue;
        if (!isdigit(s[i]))
        {
            if (s[i] == '*' || s[i] == '/')
            {
                tag = 1;
                push(&s_op, s[i]);
            }
            else
            {
                if (!tag && s_num.top >= 1)
                    calculate(&s_num, &s_op);
                push(&s_op, s[i]);
                tag = 0;
            }
        }
        else
        {
            int num = 0;
            while (isdigit(s[i]))
                num = num * 10 + s[i++] - '0';
            i--;
            push(&s_num, num);
            if (tag == 1)
            {
                calculate(&s_num, &s_op);
                tag = 0;
            }
        }
    }
    while (s_op.top != -1)
        calculate(&s_num, &s_op);
    printf("%d", s_num.data[s_num.top]);
    return 0;
}
void push(Stack *p_stack, int data)
{
    p_stack->data[++(p_stack->top)] = data;
}
int pop(Stack *p_stack)
{
    int item = p_stack->data[p_stack->top];
    p_stack->data[p_stack->top--] = 0;
    return item;
}
void calculate(Stack *p_num, Stack *p_op)
{
    int b = pop(p_num), a = pop(p_num);
    switch (pop(p_op))
    {
    case '+':
        push(p_num, a + b);
        break;
    case '-':
        push(p_num, a - b);
        break;
    case '*':
        push(p_num, a * b);
        break;
    case '/':
        push(p_num, a / b);
    }
}


