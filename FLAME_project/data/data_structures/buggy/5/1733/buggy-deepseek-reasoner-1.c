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
    }while(s1[num1-1].n!=0); // @@ [Error: assumes input always ends with exponent 0; for the given test case, exponent is 1000000000, never 0, so this loop will not terminate correctly and may read garbage or wait indefinitely]
    do
    {
        scanf("%d%d",&s2[num2].a,&s2[num2].n);
        num2++;
    }while(s2[num2-1].n!=0); // @@ [Same error as above: input does not contain exponent 0, causing infinite loop or undefined behavior]

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
    }while(temp!=NULL);
    return 0;
}
item * find(item *head,int n)
{
    item *q=head->next; // @@ [Error: if the list is empty (head->next is NULL), q becomes NULL, and the subsequent do-while will dereference NULL pointer, causing crash]
    do
    {
        if(q->n>=n&&q->next==NULL) // @@ [Error: when q is the last node and its exponent is less than n, this condition fails, and then else if tries to access q->next->n, but q->next is NULL, resulting in dereferencing NULL]
            return q;
        else if((q->n)>=n&&(q->next->n)<n) // @@ [Error: same as above, q->next may be NULL if q is the last node; also logic incorrect for descending order insertion]
        {
            return q;
        }
    q=q->next;
    }while(q!=NULL);
} // @@ [Error: function does not have a return statement after the loop; if the loop exits without finding a suitable q (e.g., q becomes NULL), the function ends without returning a value, leading to undefined behavior]