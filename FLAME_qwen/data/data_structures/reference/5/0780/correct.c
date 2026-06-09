#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 10000

typedef struct Node
{
    int x;
    int a;
    struct Node *pNext;
}*PNODE,NODE;

PNODE create(char s[])
{
    PNODE list=(PNODE)malloc(sizeof(NODE));
    list->pNext=NULL;
    list->x=-1;
    list->a=0;
    int i,x=0,div=1,flag=0;
    PNODE p=list;
    for(i=0;i<=strlen(s);i++)
    {
        if(s[i]>='0' && s[i]<='9')
            x=x*10+s[i]-'0';
        else
        {
            if(s[i]=='-')
                div=-1;
            else if(s[i]==' ' || s[i]=='\0')
            {
                if(flag==0)
                {
                    PNODE pNew=(PNODE) malloc(sizeof(NODE));
                    pNew->a=x*div;
                    pNew->pNext=NULL;
                    p->pNext=pNew;
                    div=1;
                    p=pNew;
                    flag=1;
                }
                else
                {
                    p->x=x;
                    flag=0;
                }
                x=0;
            }
        }
    }
    return list;
}
void sort(PNODE list,int len)
{
    PNODE q;
    int i;
    for(i=0;i<len-1;i++)
    {
        for(q=list->pNext;q->pNext!=NULL;q=q->pNext)
        {
            if(q->x<q->pNext->x)
            {
                int x;
                x=q->x;
                q->x=q->pNext->x;
                q->pNext->x=x;
                x=q->a;
                q->a=q->pNext->a;
                q->pNext->a=x;
            }
            else if(q->x==q->pNext->x)
            {
                q->a += q->pNext->a;
                q->pNext->a=0;
            }
        }
    }
}
void clear(PNODE list)
{
    PNODE q,p=list;
    while(p!=NULL)
    {
        q=p->pNext;
        free(p);
        p=q;
    }
}

int main()
{
    char s1[MAXN],s2[MAXN];
    fgets(s1,MAXN,stdin);
    fgets(s2,MAXN,stdin);
    PNODE list1,list2;
    list2=create(s2);
    list1=create(s1);
    PNODE list3=(PNODE) malloc(sizeof(NODE));
    list3->pNext=NULL;
    list3->x=-1;
    list3->a=0;
    PNODE p=list1->pNext,q,k=list3;
    int len=0;
    while(p!=NULL)
    {
        q=list2->pNext;
        while(q!=NULL)
        {
            PNODE pNew=(PNODE) malloc(sizeof(NODE));
            pNew->a=p->a*q->a;
            pNew->x=p->x+q->x;
            k->pNext=pNew;
            pNew->pNext=NULL;
            k=pNew;
            q=q->pNext;
            len++;
        }
        p=p->pNext;
    }
    sort(list3,len);
    for(p=list3;p!=NULL;p=p->pNext)
        if(p->a!=0)
            printf("%d %d ",p->a,p->x);
    clear(list1);
    clear(list2);
    clear(list3);
    return 0;
}

