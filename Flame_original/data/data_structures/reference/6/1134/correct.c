#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

typedef struct SNode *Stack;
struct SNode{
    int Data;
    struct SNode *Next;
};

Stack CreateStack()
{
    Stack S;
    S=(Stack)malloc (sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

int IsEmpty(Stack S)
{
    /*判断堆栈S是否为空，如果使空堆栈返回整数1，否则返回0*/
    return (S->Next == NULL);
}

void Push (int item,Stack S)
{
    struct SNode *TmpCell;
    TmpCell=(struct SNode *)malloc(sizeof(struct SNode));
    TmpCell->Data =item;
    TmpCell->Next =S->Next;
    S->Next=TmpCell;
}

int Pop(Stack S)
{
    struct SNode *FirstCell;
    int TopElem;
    if(IsEmpty(S))
    {
        printf("error ");
        return -1;
    }
    else {
        FirstCell=S->Next;
        S->Next=FirstCell->Next;
        TopElem=FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}
int main()
{
    int count=0;
    Stack head=CreateStack();
    int op,num;
    while(~scanf("%d",&op))
    {
        if(op==-1) break;
        else if(op==1)
        {
            if(count!=100)
            {
               scanf("%d",&num);
               Push(num,head);
            }
            else printf("error ");
        }
        else if(op==0)
        {
            int re;
            re=Pop(head);
            if(re==-1) continue;
            else printf("%d ", re);
        }
    }

    getchar();
    return 0;
}
