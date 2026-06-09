#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct term
{
    int xishu;
    int zhishu;
    struct term *next;
};
typedef struct term Term;
int main(void)
{
    Term *first=(Term *)malloc(sizeof(Term));
    Term *second=(Term *)malloc(sizeof(Term));
    Term *result=(Term *)malloc(sizeof(Term));
    Term *p=first;
    Term *q=second;
    Term *r=result;
    char c;
    while(1)
    {
        scanf("%d %d",&p->xishu,&p->zhishu);
        c=getchar();
        if(c=='\n')
            break;
        else
        {
            p->next=(Term *)malloc(sizeof(Term));
            p=p->next;
            p->xishu=0;
            p->zhishu=0;
            p->next=NULL;
        }
    }
    while(1)
    {
        scanf("%d %d",&q->xishu,&q->zhishu);
        c=getchar();
        if(c=='\n')
            break;
        else
        {
            q->next=(Term *)malloc(sizeof(Term));
            q=q->next;
            q->xishu=0;
            q->zhishu=0;
            q->next=NULL;
        }
    }
    p=first;
    q=second;
    while(1)
    {
        if(p->next==NULL&&q->next==NULL)
        {
            while(r->next!=NULL)
                r=r->next;
            r->next=(Term *)malloc(sizeof(Term));
            r->next->xishu=p->xishu*q->xishu;
            r->next->zhishu=p->zhishu+q->zhishu;
            r->next->next=NULL;
            break;
        }
        else
        {
            r=result;
            int result_zhishu=p->zhishu+q->zhishu;
            Term *last=r;
            while(r->zhishu>result_zhishu)
            {
                if(r->next==NULL)
                {
                    r->next=(Term *)malloc(sizeof(Term));
                    r->next->xishu=0;
                    r->next->zhishu=0;
                    r->next->next=NULL;
                }
                else
                {
                    last=r;
                    r=r->next;
                }
            }
            if(r->zhishu==0&&r->xishu==0)
            {
                r->xishu=p->xishu*q->xishu;
                r->zhishu=result_zhishu;
            }
            else if(r->zhishu==result_zhishu)
            {
                r->xishu+=p->xishu*q->xishu;
            }
            else if(r->zhishu<result_zhishu)
            {
                last->next=(Term *)malloc(sizeof(Term));
                last->next->next=r;
                last->next->xishu=p->xishu*q->xishu;
                last->next->zhishu=result_zhishu;
            }
        }
        if(q->next==NULL)
        {
            p=p->next;q=second;
        }
        else
            q=q->next;
    }
    r=result;
    while(r->next!=NULL)
    {
        if(r->xishu!=0)
            printf("%d %d ",r->xishu,r->zhishu);
        r=r->next;
        
    }
    printf("%d %d",r->xishu,r->zhishu);
    Term *last=p;
    while(p->next!=NULL)
    {
        last=p;
        p=p->next;
        free(last);
    }
    free(p);
    while(q->next!=NULL)
    {
        last=q;
        q=q->next;
        free(last);
    }
    free(q);
    while(r->next!=NULL)
    {
        last=r;
        r=r->next;
        free(last);
    }
    free(r);
    return 0;
}
/*

 
 
 
 
 
 
 */

