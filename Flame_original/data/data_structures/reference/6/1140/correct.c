#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int ElemType;      //(int)依条件替换
ElemType stack[MAXSIZE];
int Top=-1;

void push( ElemType s[ ], ElemType item )
{
    if(Top==MAXSIZE-1)
        printf("error ");
    else
        s[++Top]=item;
}

void pop( ElemType s[ ])
{
    if(Top== -1)
        printf("error ");
    else
        printf("%d ",s[Top--]);
}

int main()
{
	int num,op;
    while (scanf("%d",&op)!=EOF)
    {
        switch (op)
        {
        case 1:
            scanf("%d",&num);
            push(stack,num);
            break;
        case 0:
            pop(stack);
            break;
        case -1:
            return 0;
        }
    }
    
	return 0;
}

