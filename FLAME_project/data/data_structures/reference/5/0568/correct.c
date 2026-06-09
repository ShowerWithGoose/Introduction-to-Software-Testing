#include<stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct line
{int coeff;
 int  index;
 struct line*next;
}Line;
Line *head,*p,*end,*head2,*p2,*end2,*m,*n,*a,*b,*b_left,*headx,*endx,*mid;
int main()
{
int flag=0,temp;
    head=(Line*)malloc(sizeof(Line));
    head->next=NULL;
    p=(Line*)malloc(sizeof(Line));
    p=head;
    p->next=NULL;
    end=head;
    while(1){
            p=p->next;
            p=(Line*)malloc(sizeof(Line));
        scanf("%d%d",&p->coeff,&p->index);
        p->next=NULL;
    end->next=p;
    end=p;
    if(getchar()=='\n')
    {
        break;
    }
               }

    head2=(Line*)malloc(sizeof(Line));
    head2->next=NULL;
    p2=(Line*)malloc(sizeof(Line));
    p2=head2;
    p2->next=NULL;
    end2=head2;
    while(1){
            p2=p2->next;
            p2=(Line*)malloc(sizeof(Line));
        scanf("%d%d",&p2->coeff,&p2->index);
        p2->next=NULL;
    end2->next=p2;
    end2=p2;
    if(getchar()=='\n')
    {
        break;
    }

               }
     /*m=head;
    while(m!=end)
    {
        m=m->next;
        printf("%d %d\n",m->coeff,m->index);

    }

        n=head2;
    while(n!=end2)
    {
        n=n->next;
        printf("%d %d\n",n->coeff,n->index);

    }*/


    headx=NULL;
    m=head->next;
    n=head2->next;
    while(m!=NULL)
    {n=head2->next;
       while(n!=NULL)
       {   flag=0;
           b=headx;
           while(b!=NULL)
           {
               if(b->index==m->index+n->index)
               {flag=1;
                   b->coeff=b->coeff+(m->coeff)*(n->coeff);
                   //printf("-------------\n");
                   break;
               }
               b=b->next;
           }
           if(flag==0)
           {a=(Line*)malloc(sizeof(Line));
           a->coeff=(m->coeff)*(n->coeff);
           a->index=m->index+n->index;
           a->next=NULL;
               if(headx==NULL)
                {
                    headx=endx=a;
                }
                else{
                    endx->next=a;
                    endx=a;
                }
           }
           //printf("%d %d\n",(m->coeff)*(n->coeff),m->index+n->index);

           n=n->next;
       }
       m=m->next;
    }
    n=headx;
    m=headx;
    for(;n!=NULL;){
            m=headx;
    for(;m->next!=NULL;)
    {
        if(m->index<m->next->index)
        {
            temp=m->coeff;
            m->coeff=m->next->coeff;
            m->next->coeff=temp;

            temp=m->index;
            m->index=m->next->index;
            m->next->index=temp;
        }
        m=m->next;
    }

n=n->next;
    }
    m=headx;
    for(;m!=NULL;)
    {
        printf("%d %d ",m->coeff,m->index);
        m=m->next;
    }
   /* a=(Line*)malloc(sizeof(Line));

    a->coeff=(m->coeff)*(n->coeff);
    a->index=m->index+n->index;

    a->next=NULL;
    headx=endx=a;
    while(m!=end)
        {
            n=head2->next;
    while(n!=end2)
    {
    flag=0;
    b=headx;
    b_left=headx;
b=b->next;
    while(b!=NULL)
       {

       if(b->index==m->index+n->index)
          {b->coeff+=m->coeff+n->coeff;

          }

        if(b->index<m->index+n->index)
        {  mid=(Line*)malloc(sizeof(Line));
        mid->coeff=(m->coeff)*(n->coeff);
        mid->index=m->index+n->index;
            b_left->next=mid;
            mid->next=b;

            break;
            flag=1;
        }
        b_left=b_left->next;
           b=b->next;

       }

       if(flag==0)
       {
       a->coeff=(m->coeff)*(n->coeff);
       a->index=m->index+n->index;
       endx->next=a;
       endx=a;
       printf("%d %d ",a->coeff,a->index);
       }
       n=n->next;
    }m=m->next;
        }*/


    /*m=headx;
    while(m!=endx)
    {m=m->next;
        printf("%d %d ",m->coeff,m->index);

    }*/
return 0;}

