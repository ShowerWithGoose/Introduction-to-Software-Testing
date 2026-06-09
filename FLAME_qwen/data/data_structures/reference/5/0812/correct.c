#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

typedef struct Polynode
{
    int coef;
    int exp;
    struct Polynode *next;
}Node,*Link;

Link insert(Link head,int coef,int exp)//降幂插入链表
{
    Link node,q,p;
    q=head;
    p=head->next;
    node=(Link)malloc(sizeof(Node));
    node->next=NULL;
    node->coef=coef;
    node->exp=exp;

    if(head->next==NULL)
    {
        head->next=node;
    }
    else
    {
        while(p!=NULL)
        {
            if(node->exp>p->exp)
            {
                q->next=node;
                node->next=p;
                return head;
            }
            else if(node->exp==p->exp)
            {
                p->coef+=node->coef;
                return head;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        q->next=node;
    }

    return head;
}

void Polylist(Link head)//生成链表函数
{
    int coef,exp;
    char s;
    scanf("%d%d",&coef,&exp);
    s=getchar();
    while(s!='\n')
    {
        insert(head,coef,exp);
        scanf("%d%d",&coef,&exp);
        s=getchar();
    }
    insert(head,coef,exp);

}

void Mult(Link head_a,Link head_b,Link head_ab)
{
    Link pa,pb;
    int coef,exp;
    pa=head_a->next;
    pb=head_b->next;
    while(pa!=NULL)
    {
        pb=head_b->next;
        while(pb!=NULL)
        {
            coef=pa->coef*pb->coef;
            exp=pa->exp+pb->exp;
            insert(head_ab,coef,exp);
            pb=pb->next;
        }
        pa=pa->next;
    }
}
int main()
{
    Link head_a,head_b,head_ab;
    Link p;
    head_a=(Link)malloc(sizeof(Node));
    head_a->next=NULL;
    head_b=(Link)malloc(sizeof(Node));
    head_b->next=NULL;
    head_ab=(Link)malloc(sizeof(Node));
    head_ab->next=NULL;

    Polylist(head_a);
    Polylist(head_b);

    Mult(head_a,head_b,head_ab);

    p=head_ab->next;
    while(p!=NULL)
    {
        printf("%d %d ",p->coef,p->exp);
        p=p->next;
    }

    return 0;
}



