#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct S
{
    int xi;
    int zhi;
    struct S *next;
};

struct S* creat(int num1,int num2)
{
    struct S* newone = (struct S*)malloc(sizeof(struct S));
    newone->xi = num1;
    newone->zhi = num2;
    newone->next = NULL;
    return newone;
}

void in(struct S *head,struct S* newone)
{
    newone->next = head->next;
    head->next = newone;
}

int main()
{
     int a,b,max1 = 0,max2 = 0,m1,m2,min = 2000000000;
     char c;
     struct S *h1,*h2,*p1,*p2,*u,*h3,*p3,*h4,*p4;
     scanf("%d%d%c",&a,&b,&c);
     p1 = creat(a,b);
     h1 = p1;
     if(c!= '\n')
     {
        do{
        scanf("%d%d%c",&a,&b,&c);
        u = creat(a,b);
        in(p1,u);
        p1 = p1->next;
       }while(c!= '\n');
     }
    scanf("%d%d%c",&a,&b,&c);
      p2 = creat(a,b);
      h2 = p2;
      if(c!= '\n')
     {
        do{
        scanf("%d%d%c",&a,&b,&c);
        u = creat(a,b);
        in(p2,u);
        p2 = p2->next;
       }while(c!= '\n');
     }
     p1 = h1;
     p2 = h2;
     p3 = creat((p1->xi)*(p2->xi),(p1->zhi)+(p2->zhi));
     h3 = p3;
     p2=p2->next;
     goto U;
     for(;p1!=NULL;p1=p1->next)
     {
         p2 = h2;
         U:for(;p2!=NULL;p2=p2->next)
         {
             u = creat((p1->xi)*(p2->xi),(p1->zhi)+(p2->zhi));
             in(p3,u);
             p3=p3->next;
         }
     }

     p3 = h3;
     for(;p3!=NULL;p3=p3->next)
     {
        if((p3->zhi)>max1)
        {
            max1 = p3->zhi;
            max2 = p3->xi;
        }

        else if((p3->zhi)<min)
        {
            min = p3->zhi;
        }

        else if((p3->zhi)==max1)
        {
            max2+= p3->xi;
        }
     }
     p4 = creat(max2,max1);
     h4=p4;
     while(max1!=min)
     {
         m1 = 0;
         m2 = 0;
         p3 = h3;
         for(;p3!=NULL;p3=p3->next)
        {
          if((p3->zhi)>m1&&(p3->zhi)<max1)
          {
              m1 = p3->zhi;
              m2 = p3->xi;
          }
          else if((p3->zhi)==m1&&(p3->zhi)<max1)
          {
              m2+= p3->xi;
           }
         }
         u = creat(m2,m1);
         in(p4,u);
         p4=p4->next;
         max1 = m1;
     }
    p4 = h4;
    while(p4!=NULL)
    {
        printf("%d %d ",p4->xi,p4->zhi);
        p4 = p4->next;
    }
     return 0;
}



