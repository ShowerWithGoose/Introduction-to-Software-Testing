//
//  main.c
//  stack
//
//  Created by  on 2022/4/15.
//
/*本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 100
void initS(int *);
int isEmptyS(int);
int isFullS(int);
int push(int [], int *, int);
int pop(int [], int *, int *);
int main()
{
    int stack[MAXN], top;
    initS(&top);
    int op, elem;
    while(~scanf("%d", &op))
    {
        if (op==1)//入栈
        {
            scanf("%d", &elem);
            if (push(stack, &top, elem)==0)
                printf("error ");
        }
        else if(op==0)//出栈
        {
            if (pop(stack, &top, &elem)==0)
                printf("error ");
            else
                printf("%d ", elem);
        }
        else//结束
        {
            return 0;
        }
    }
}

void initS(int *topPtr)
{
    *topPtr=-1;
}

int isEmptyS(int top)
{
    return top==-1;
}

int isFullS(int top)
{
    return top==MAXN-1;
}

int push(int stack[], int *topPtr, int item)
{
    if (isFullS(*topPtr))
        return 0;
    else
    {
        stack[++(*topPtr)]=item;
        return 1;
    }
}

int pop(int stack[], int *topPtr, int *itemPtr)
{
    if (isEmptyS(*topPtr))
        return 0;
    else
    {
        *itemPtr=stack[(*topPtr)--];
        return 1;
    }
    
}


