#include<stdio.h>
#include<stdlib.h>
int a1[100],a2[100],b1[100],b2[100];
char h1,h2;
typedef struct 
{
    int di;
    int zhi;
}num;
int cmp(const void *a,const void *b)
{
    return (*(num *)b).zhi-(*(num *)a).zhi;
}
int main()
{
    int i=1,j,p1=0,q1=0,a=1,p2=0,q2=0,k=0,h=0,n,fl=0,fla=0;
    num c[500];
    while(h1!='\n')
    {
        scanf("%d",&a);
        scanf("%c",&h1);
        if(i%2==1)
        {
            a1[p1]=a;
            p1++;
        }
        else
        {
            b1[q1]=a;
            q1++;

        }
        i++;
    }
    b1[q1]=0;
    i=1;
   a=1;
    while(h2!='\n')
    {
        scanf("%d",&a);
        scanf("%c",&h2);
        if(i%2==1)
        {
            a2[p2]=a;
            p2++;
        }
        else
        {
            b2[q2]=a;
            q2++;
        }
        i++;
    }
    b2[q2]=0;
   for(i=0;i<p1;i++)
   {
       for(j=0;j<p2;j++)
       {
           c[k].di=a1[i]*a2[j];
           k++;
       }
   }
   for(i=0;i<q1;i++)
   {
       for(j=0;j<q2;j++)
       {
           c[h].zhi=b1[i]+b2[j];
           h++;
       }
   }
qsort(c,h,sizeof(num),cmp);
for(k=0;k<h-1;k++)
{
    if(c[k].zhi==c[k+1].zhi)
    {
        c[k].di+=c[k+1].di;
        for(n=k+1;n<h-1;n++)
        {
            c[n].zhi=c[n+1].zhi;
            c[n].di=c[n+1].di;
        }
        h--;
        k--;
    }
}
for(i=0;i<h;i++)
{
    printf("%d %d ",c[i].di,c[i].zhi);
}
    return 0;
}

