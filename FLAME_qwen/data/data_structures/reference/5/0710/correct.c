#include <stdio.h>
#include <stdlib.h>
struct node
{
    int xs;
    int zs;
    struct node *next;
};
int main()
{   struct node *p1=NULL,*p2=NULL,*first1=NULL,*first2=NULL,*p3=NULL,*p4=NULL,*first3=NULL,*p5=NULL,*p6=NULL;
    int i,n,axs,azs,l1=0,l2=0,j,temp1,temp2,x=0;
    char a;
    while(scanf("%d%d",&axs,&azs))
    {
        p1=(struct node *)malloc(sizeof(struct node));
        p1->xs=axs;
        p1->zs=azs;
        l1++;
        a=getchar();
        if(first1==NULL)
            first1=p2=p1;
        else
        {
            p2->next=p1;
            p2=p2->next;
        }
        if(a=='\n')
            break;
    }
    while(scanf("%d%d",&axs,&azs))
    {
        p3=(struct node *)malloc(sizeof(struct node));
        p3->xs=axs;
        p3->zs=azs;
        l2++;
        a=getchar();
        if(first2==NULL)
            first2=p4=p3;
        else
        {
            p4->next=p3;
            p4=p4->next;
        }
        if(a=='\n')
            break;
    }
    for(i=0,p1=first1;i<l1;i++,p1=p1->next)
    {
        for(j=0,p3=first2;j<l2;j++,p3=p3->next)
        {   p5=(struct node *)malloc(sizeof(struct node));
            p5->xs=p1->xs*p3->xs;
            p5->zs=p1->zs+p3->zs;
            if(first3==NULL)
                first3=p6=p5;
            else
            {
                p6->next=p5;
                p6=p6->next;
            }
        }
    }p6->next=NULL;
    for(i=0;i<l1*l2-1;i++)
        for(j=0,p1=first3;j<l1*l2-i-1;j++,p1=p1->next)
    {
        p2=p1->next;
        if(p1->zs<p2->zs)
        {
            temp1=p1->zs;
            p1->zs=p2->zs;
            p2->zs=temp1;
            temp2=p1->xs;
            p1->xs=p2->xs;
            p2->xs=temp2;
        }
    }
   for(i=0,p1=first3;p1->next!=NULL;i++)
   {    p2=p1->next;
       if(p1->zs==p2->zs)
       {
          p1->xs=p1->xs+p2->xs;
          x++;
          p1->next=p2->next;
          free(p2);
          i++;
       }
       else
        p1=p1->next;
   }
   for(i=0,p1=first3;i<l1*l2-x;i++,p1=p1->next)
    {printf("%d %d",p1->xs,p1->zs);
    printf(" ");}
   return 0;
}

