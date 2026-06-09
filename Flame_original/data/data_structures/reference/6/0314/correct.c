#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define clear(a) memset(a,0,sizeof(a))

#define MAXSIZE 100
#define OK 0
#define ERROR -1
typedef int Status;
typedef int ElemType;//int 可改
typedef struct 
{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

//初始化
void InitStack(SqStack *S)
{
    S->top=-1;
}

//判栈空
int StackEmpty(SqStack S)
{
    if(S.top==-1)
        return 1;
    else
        return 0;
}

//进栈
Status Push(SqStack *S,ElemType e)
{
    if(S->top==MAXSIZE-1)
        return ERROR;
    S->top++;
    S->data[S->top]=e;
    return OK;
}

//出栈,用e返回其值
Status Pop(SqStack *S,ElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];
    S->top--;
    return OK;
}

//读栈顶元素
Status GetTop(SqStack *S,ElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];
    return OK;
}

int main()
{
    int a,b,c,d1;
    int *d=&d1;
    SqStack line;
    InitStack(&line);
    while(1)
    {
        scanf("%d",&a);
        if(a==-1)
            break;
        else if(a==1)
        {
            scanf("%d",&b);
            c=Push(&line,b);
            if(c==ERROR)
            {
                printf("error ");
            }
        }
        else
        {
            c=Pop(&line,d);
            if(c==ERROR)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",*d);
            }
        }
    }
    return 0;
}
