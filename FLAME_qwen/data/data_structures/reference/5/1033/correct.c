#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct Term
{
    int coe;
    int ex;
}Term;

void getTerm(Term *t,int *total)
{
   int n=*total;
   char c;
   do
   {
       scanf("%d%d",&(t[n].coe),&(t[n].ex));
       n++;
       c=getchar();
   }while(c!='\n'&&c!='\r');
   *total=n;
   return ;
}

void multiple(Term *t1,Term *t2,Term *ret,int n1,int n2,int *total)
{
    int n=*total;
    int i,j;
    for(i=0;i<n1;i++)
    {
        for(j=0;j<n2;j++)
        {
            ret[n].coe=(t1[i].coe)*(t2[j].coe);
            ret[n].ex=(t1[i].ex)+(t2[j].ex);
            n++;
        }
    }
    *total=n;
    return ;
}

void bubble_sort(Term *t,int n)
{
     int i,j;
     Term temp;
     for(i=0;i<n;i++)
     {
         for(j=0;j<n-i-1;j++)
         {
             if(t[j].ex<t[j+1].ex)
             {
                 temp=t[j];
                 t[j]=t[j+1];
                 t[j+1]=temp;
             }
         }
     }
     return ;
}

int main()
{
    Term term1[40],term2[40],ret[100];
    int n1=0,n2=0,total=0;
    int i,j,times;
    int coe,ex;
    getTerm(term1,&n1);
    getTerm(term2,&n2);
    multiple(term1,term2,ret,n1,n2,&total);
    bubble_sort(ret,total);
    for(i=0;i<total;i+=times)
    {
        coe=ret[i].coe;
        ex=ret[i].ex;
        for(j=i+1,times=1;j<total&&ret[j].ex==ret[i].ex;j++,times++)
        {
            coe+=ret[j].coe;
        }
        printf("%d %d ",coe,ex);

    }
    return 0;
}

