#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

struct node{
    long long data;
    long long index;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;

Nodeptr ppp(Nodeptr head,long long data,long long index)
{
    Nodeptr p = head,q = NULL,r = NULL;
    r = (Nodeptr)malloc(sizeof(Node));

    r->data = data;
    r->index = index;
    r->link = NULL;

    if(head == NULL)
    {
        return r;
    }

    for(p = head;p != NULL && p->index > index;q = p,p = p->link);

    if(p != NULL && p->index == index)
    {
        p->data += data;
    }

    else if(p == head)
    {
        r->link = p;
        return r;
    }

    else
    {
        q->link = r;
        r->link = p;
    }
    return head;
}


int qpow(Nodeptr head)
{
    if(head == NULL)
    {
        return 0;
    }
    Nodeptr p;
    for(p = head;p != NULL;p = p->link)
    {
        if(p->data != 0)
        {
            printf("%lld ",p->data);
            printf("%lld ",p->index);
        }
    }
    return 1;
}

int main()
{
    Nodeptr line = NULL, num = NULL;
    long long data,index,tmp = 20000000000;
    while((scanf("%lld%lld",&data,&index))!=EOF)
    {
        if(tmp<=index)
        {
            Nodeptr p = NULL;
            for(p = line;p!=NULL;p=p->link)
            {
                num = ppp(num,(p->data)*data,(p->index)+index);
            }
            break;
        }
        line = ppp(line, data, index);
        tmp = index;
    }

    while((scanf("%lld%lld",&data,&index))!=EOF)
    {
        Nodeptr q = NULL;
        for(q = line;q!=NULL;q=q->link)
        {
            num = ppp(num,data*q->data,index+q->index);
        }
    }
    qpow(num);
    return 0;
}

