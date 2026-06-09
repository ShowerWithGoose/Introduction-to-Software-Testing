#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
    int coe;//系数
    int pow;//幂
    struct Node *next;
};
struct Node *multi(struct Node*,struct Node*);
int main()
{
    int a,n;
    char c;
    struct Node *head1=NULL,*head2=NULL,*p1=NULL,*p2=NULL,*q=NULL,*outcomehead=NULL,*print=NULL;
    do{//创建链表
    scanf("%d%d%c",&a,&n,&c);
    q=(struct Node*)malloc(sizeof(struct Node));
    q->coe=a; q->pow=n; q->next=NULL;

    if(head1==NULL)
    {
        head1=p1=q;
    }

    else
    {
        p1->next=q;
        p1=q;
    }
   }while(c!='\n');//创建链表因数1


    do{//创建链表
    scanf("%d%d%c",&a,&n,&c);
    q=(struct Node*)malloc(sizeof(struct Node));
    q->coe=a; q->pow=n; q->next=NULL;

    if(head2==NULL)
    {
        head2=p2=q;
    }

    else
    {
        p2->next=q;
        p2=q;
    }
   }while(c!='\n');//创建链表因数2

   outcomehead=multi(head1,head2);

   print=head1;

   while(print!=NULL)
    {
        print=head1->next;

        head1=print;
    }
    print=head2;
    while(print!=NULL)
    {
        print=head2->next;
     head2=print;
    }

   print=outcomehead;

   while(print!=NULL)
    {
        print=outcomehead->next;
        printf("%d %d ",outcomehead->coe,outcomehead->pow);

        outcomehead=print;
    }

    return 0;
}
struct Node *multi(struct Node *head1,struct Node *head2)
{
     struct Node *multi_head=NULL,*p1=head1,*p2=head2,*q=NULL,*cmp=NULL;

     while(p1!=NULL)
     {
         while(p2!=NULL)
         {
             q=(struct Node*)malloc(sizeof(struct Node));

             q->coe=p1->coe*p2->coe;
             q->pow=p1->pow+p2->pow;
             q->next=NULL;

             if(multi_head==NULL)
             {
                 multi_head=q;
                 cmp=q;
             }

             else if(multi_head!=NULL)
             {
                 while(cmp!=NULL)
                 {
                     if(q->pow==cmp->pow)
                     {
                         cmp->coe+=q->coe; // @@ [After adding coefficient, the loop should break to avoid checking remaining nodes, but break is missing.]
                     }

                     else if(cmp->next!=NULL)
                     {
                         if(q->pow<cmp->pow&&q->pow>cmp->next->pow) // @@ [This condition cannot handle the case when q->pow is greater than cmp->pow (should be inserted before head) – logic error.]
                         {
                             q->next=cmp->next;
                             cmp->next=q;
                             break;
                         }

                         else
                            {
                              cmp=cmp->next;
                            }
                     }
                     else
                        {
                            cmp->next=q;
                            cmp=cmp->next;
                            break;
                        }
             }
         }

         p2=p2->next; // @@ [p2 is NULL at this point (inner while loop ends when p2 becomes NULL), so this dereferences a null pointer – runtime error.]

     }

     cmp=multi_head;
         p1=p1->next;
         p2=head2;
     } // @@ [Extra closing brace – this causes a compilation error because it is unmatched.]

     return multi_head;
}