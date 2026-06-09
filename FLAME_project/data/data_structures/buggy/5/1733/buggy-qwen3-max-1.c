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
    }while(s1[num1-1].n!=0); // @@ [The input loop stops only when exponent is 0, but the problem states that only non-zero terms are given and does not guarantee that the last term has exponent 0. This causes incorrect reading of input when the constant term (x^0) is absent or when the polynomial doesn't end with exponent 0.]
    do
    {
        scanf("%d%d",&s2[num2].a,&s2[num2].n);
        num2++;
    }while(s2[num2-1].n!=0); // @@ [Same issue as above: assumes input always ends with exponent 0, which is not guaranteed by the problem statement.]

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
    }while(temp!=NULL); // @@ [This loop will crash if head->next is NULL (i.e., no terms in result), because it tries to access temp->a and temp->n before checking if temp is NULL. Also, the output format requires terms in descending order, but insertion logic may not maintain correct ordering in all cases due to flaws in `find` function.]
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
    }while(q!=NULL); // @@ [If the list is empty (head->next == NULL), then q is NULL and the loop condition is checked after entering the loop body, causing a segmentation fault when accessing q->n. Additionally, the function does not handle the case where all existing exponents are less than `n`; it should return the last node to append at the end, but current logic may return an incorrect or NULL pointer.]
}