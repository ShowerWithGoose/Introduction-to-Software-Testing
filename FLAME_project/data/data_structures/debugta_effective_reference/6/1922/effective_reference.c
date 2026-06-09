#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 102

struct opstack{
    int data[MAX];
    int top;
} s;

int u, item;
typedef struct opstack stack;

void initstack(stack *s) { s->top = -1; }

int isempty_stack(stack *s) { return s->top == -1; }

int isfull_stack(stack *s) { return s->top == MAX - 1; }

int push_stack(stack *s, int u)
{
    if (isfull_stack(s) != 0)
    {
        printf("error ");
        return 0;
    }
    s->data[++s->top] = u;
    return 1;
}

int pop_stack(stack *s, int u)
{
    if (s->top == -1)
    {
        printf("error ");
        return 0;
    }
    u = s->data[s->top--];
    printf("%d ", u);
    return 1;
}

int main(void)
{
    initstack(&s);
    int type = -1;
    while (1)
    {
        scanf("%d", &type);
        if (type == -1)
            break;
        else if (type == 0)
            pop_stack(&s, u);
        else if (type == 1)
        {
            scanf("%d", &item);
            push_stack(&s, item);
        }
    }
}
/*【问题描述】
 
 假设给定的整数栈初始状态为空，栈的最大容量为100。从标准输入中输入一组栈操作，按操作顺序输出出栈元素序列。栈操作：1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素；0表示出栈操作；-1表示操作结束。

 【输入形式】

 从标准输入读取一组栈操作，入栈的整数和表示栈操作的整数之间都以一个空格分隔。

 【输出形式】

 在一行上按照操作的顺序输出出栈元素序列，以一个空格分隔各元素，最后一个元素后也要有一个空格。如果栈状态为空时进行出栈操作，或栈满时进行入栈操作，则输出字符串“error”，并且字符串后也要有一空格。所有操作都执行完后，栈也有可能不为空。

 【样例输入】

 1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1

 【样例输出】

 7 5 8 13 12 3 error 89

 【样例说明】

 入栈元素依次为3、5、7，然后有两次出栈动作，所以先输出7和5，这时栈中只有元素3；之后元素8入栈，又出栈，输出8；随后元素12和13入栈，再进行4次出栈操作，输出13、12和3，这时栈为空，再进行出栈操作会输出error；最后90和89入栈，进行一次出栈操作，输出89，栈中剩余1个元素。 */

