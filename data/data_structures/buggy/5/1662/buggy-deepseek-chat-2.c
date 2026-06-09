#include <stdio.h>
#include <stdlib.h>
typedef struct apo
{
    int c;
    int in;
    struct apo* next;
}apo;
typedef struct bpo
{
    int c;
    int in;
    struct bpo* next;
}bpo;
typedef struct ans
{
    int c;
    int in;
    struct ans* next;
}ans;
typedef struct apo* Nodeptr;
typedef struct bpo* nodeptr;
typedef struct ans* node;
Nodeptr head1=NULL,p;
nodeptr head2=NULL,q;
node head=NULL,r;
void insert1(int c,int in)
{
    Nodeptr p1;
    p1=(Nodeptr)malloc(sizeof(apo));
    p1->c=c;
    p1->in=in;
    p1->next=NULL;
    if(head1==NULL)
        head1=p=p1;
    else
        p->next=p1;
    p=p1;
}
void insert2(int c,int in)
{
    nodeptr q1;
    q1=(nodeptr)malloc(sizeof(bpo));
    q1->c=c;
    q1->in=in;
    q1->next=NULL;
    if(head2==NULL)
        head2=q=q1;
    else
        q->next=q1;
    q=q1;
}
void insert3(int c,int in)
{
    int flag=0;
    node r1,r2,r3;
    if(head==NULL)
    {
        r1=(node)malloc(sizeof(ans));
        r1->c=c;
        r1->in=in;
        r1->next=NULL;
        head=r=r1;
    }
    else
    {
        r2=head;
        while(r2!=NULL)
        {
            if((r2->in)==in)
            {
                flag=1;
                break;
            }
            else if((r2->in)<in)
            {
                flag=2;
                r1=head;
                while(r1!=NULL)
                {
                    if((r1->in)>in&&(r1->next->in)<in) // @@ [Potential null pointer dereference: r1->next may be NULL when checking r1->next->in]
                        break;
                    r1=r1->next;
                }
            }
            if((r2->next)==NULL||flag!=0)
            break;
            else
            r2=r2->next;
        }
        if(flag==0)//无可合并项，另开结点
        {
            r3=(node)malloc(sizeof(ans));
            r3->c=c;
            r3->in=in;
            r3->next=NULL;
            r->next=r3; // @@ [r may be outdated: after previous insertions, r may not point to the last node, causing incorrect linking]
            r=r3;
        }
        else if(flag==1)//有可合并项
        {
            r2->c=c+(r2->c); // @@ [Logic error: should be r2->c += c, not adding c to itself and then adding in]
            r2->in=in+(r2->in); // @@ [Logic error: exponent should not be added; should remain unchanged]
        }
        else if(flag==2)//往中间位置插入
        {
            r3=(node)malloc(sizeof(ans));
            r3->c=c;
            r3->in=in;
            r1->next=r3;
            r3->next=r2;
        }
    }
}
int main()
{
    int c,in;
    char x,y;
    while(1){
        scanf("%d%c%d%c",&c,&x,&in,&y); // @@ [Input format mismatch: problem expects "coefficient exponent" pairs separated by space, not with extra characters]
        insert1(c,in);
        if(y=='\n')
        break;
    }
    while(1){
        scanf("%d%c%d%c",&c,&x,&in,&y); // @@ [Same input format issue as above]
        insert2(c,in);
        if(y=='\n')
        break;
    }
    for(p=head1;p!=NULL;p=p->next)
    {
        int m,n;
        for(q=head2;q!=NULL;q=q->next)
        {
            m=(p->c)*(q->c);
            n=(p->in)+(q->in);
            insert3(m,n);
        }
    }
    r=head;
    while(r!=NULL)
    {
        printf("%d %d",(r->c),(r->in));
        if((r->next)!=NULL)
        {
            printf(" ");
            r=r->next;
        }
        else
        break;
    }
    
    return 0;
}