#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
typedef struct
{
    int Data[MaxSize];
    int top;
}SeqStack;//顺序栈（数组栈//

int Push(SeqStack *L, int e)
{
	if(L->top==MaxSize -1)
    {
        return 0;
    }
    L->Data[L->top++] = e;
    return e;
}
int Pop(SeqStack *L)
{
     if(L->top == 0)
    {
         return 0;
    }
    int x = L->Data[--L->top];
    printf("%d ",x);
    return x;
}

int isEmpty(SeqStack *L)
{
    if(L->top != 0)
    {
        return 1;
    }
    return 0;
}

int main(){
    int c,n;
    SeqStack arr;
    SeqStack *l=&arr;
    while (scanf("%d",&c)!=EOF)
    {
        switch (c)
        {
        case 1:{scanf("%d",&n);Push(l,n);}
            break;
        case 0:{isEmpty(l) ? Pop(l) : printf("error ");}
            break;
        case -1:{return 0;}
        }
    }
    return 0;
}
