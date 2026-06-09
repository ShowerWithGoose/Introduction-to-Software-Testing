#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct node{
  int a;
  int b;
  struct node* next;
};
typedef struct node Node;
typedef struct node* Nodeptr;



int main()
{
   Nodeptr p,q,list1,list2;list1=NULL;list2=NULL;    
   int a1,b1;char c;
   while (1)
   {
       scanf("%d%d%c",&a1,&b1,&c);
       p=(Nodeptr)malloc(sizeof(Node));
       p->a=a1;p->b=b1;p->next=NULL;
       if (list1==NULL)
       {
           list1=p;q=p;
       }
       else
       {
         q->next=p;
         q=p;
       }
       p=p->next;
       if (c=='\n')
       {
           break;
       }
       
   }
    while (1)
   {
       scanf("%d%d%c",&a1,&b1,&c);
       p=(Nodeptr)malloc(sizeof(Node));
       p->a=a1;p->b=b1;p->next=NULL;
       if (list2==NULL)
       {
           list2=p;q=p;
       }
       else
       {
         q->next=p;
         q=p;
       }
       p=p->next;
       if (c=='\n')
       {
           break;
       }
       
   }
   Nodeptr p1,q1,r1,list3;int x,y;
   list3=(Nodeptr)malloc(sizeof(Node));
   list3->a=0;list3->b=0;list3->next=NULL;
   for (p = list1; p!=NULL; p=p->next)
   {
       for (q = list2; q!=NULL; q=q->next)
       {
           x=p->a*q->a;
           y=p->b+q->b;
           for(r1=list3;r1!=NULL;)
           {
             if (r1->b<y)
             {
                if (r1==list3)
                {
                    p1=(Nodeptr)malloc(sizeof(Node));
                    p1->a=x;p1->b=y;p1->next=list3;list3=p1;
                    break;
                }
                else
                {
                 p1=(Nodeptr)malloc(sizeof(Node));
                 p1->a=x;p1->b=y;p1->next=r1;
                 q1->next=p1;
                 break;

                }
             }
             else if (r1->b==y)
             {
                 r1->a=r1->a+x;
                 break;
             }
             else
             {
               q1=(Nodeptr)malloc(sizeof(Node));
               q1=r1;
               r1=r1->next;
             }
           }

       }
       
   }
   for (p=list3; p!=NULL; p=p->next)
   {
       if (p->a!=0)
       {
           printf("%d %d ",p->a,p->b);
       }
       
   }
   

    return 0;
}
