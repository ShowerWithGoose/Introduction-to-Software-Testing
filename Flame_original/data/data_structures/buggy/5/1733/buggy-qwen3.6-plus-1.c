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
    }while(s1[num1-1].n!=0);
    do
    {
        scanf("%d%d",&s2[num2].a,&s2[num2].n);
        num2++;
    }while(s2[num2-1].n!=0);

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

        printf("%d %d ",temp->a,temp->n); // @@ If the result list is empty, temp is NULL, causing a segmentation fault.
        temp=temp->next;
    }while(temp!=NULL); // @@ do-while loop executes at least once, which is unsafe if temp is initially NULL; should be a while loop.
    return 0;
}
item * find(item *head,int n)
{
    item *q=head->next; // @@ If the list is empty, q is NULL, leading to a crash when accessing q->n later. Also fails to handle insertion at the head.
    do
    {
        if(q->n>=n&&q->next==NULL) // @@ Dereferences q without NULL check; logic doesn't handle cases where the new term's exponent is greater than existing nodes.
            return q;
        else if((q->n)>=n&&(q->next->n)<n) // @@ Incomplete logic for finding insertion point; may cause incorrect ordering or missed insertions.
        {
            return q;
        }
    q=q->next;
    }while(q!=NULL); // @@ Loop exits without returning a value when q becomes NULL or conditions aren't met, causing undefined behavior.
} // @@ Missing return statement for all control paths, which typically causes a compilation error.