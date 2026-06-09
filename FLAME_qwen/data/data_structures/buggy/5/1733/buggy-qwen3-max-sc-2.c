#include<stdio.h>
#include<stdlib.h>
struct ITEM
{
   int a;
   int n;
   struct ITEM *next;
};
typedef struct ITEM item;
item * find(item *,int);
int main()
{
    item s1[20],s2[20];
    int num1=0,num2=0;
    do
    {
        scanf("%d%d",&s1[num1].a,&s1[num1].n);
        num1++;
    }while(s1[num1-1].n!=0); @@ [The input may not end with exponent 0; the problem states only non-zero terms are given, and the polynomial may not have a constant term. This causes premature termination or infinite loop.]
    do
    {
        scanf("%d%d",&s2[num2].a,&s2[num2].n);
        num2++;
    }while(s2[num2-1].n!=0); @@ [Same issue as above: assuming input ends with exponent 0 is incorrect per problem description.]

    item *head,*tail,*p;
    p=(item*)malloc(sizeof(item));
    p->next=NULL;
    head=p;
    tail=p;
    for(int i=0;i<num1;i++)
    {
        for(int j=0;j<num2;j++)
        {
            if(i==0&&j==0)
            {
                p=(item*)malloc(sizeof(item));
                p->a=s1[i].a*s2[j].a;
                p->n=s1[i].n+s2[j].n;
                head->next=p;
                tail=p;
                p->next=NULL;
            }
            else
            {p=(item*)malloc(sizeof(item));
            p->a=s1[i].a*s2[j].a;
            p->n=s1[i].n+s2[j].n;
            p->next=NULL;
            item *q=find(head,p->n);
            if(q->n==p->n)
            {
                q->a+=p->a;
            }
            else
                {
                    p->next=q->next;
            q->next=p;}}
        }

    }
    item *temp=head->next;
    do
    {

        printf("%d %d ",temp->a,temp->n);
        temp=temp->next;
    }while(temp!=NULL); @@ [If result polynomial is zero (all coefficients cancel), head->next is NULL, causing dereference of NULL pointer.]

    return 0;
}
item * find(item *head,int n)
{
    item *q=head->next;
    do
    {
        if(q->n>=n&&q->next==NULL)
            return q;
        else if((q->n)>=n&&(q->next->n)<n)
        {
            return q;
        }
    q=q->next;
    }while(q!=NULL); @@ [If head->next is NULL (empty list), q is NULL, and accessing q->n causes segmentation fault. Also, loop condition should be while(q != NULL) before accessing members.]
}