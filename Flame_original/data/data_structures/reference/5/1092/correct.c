#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct st{
    int c,e;
}a[10],b[10],s[100];
int cmp(const void *s1,const void *s2)
{
    struct st *a=(struct st*)s1;
    struct st *b=(struct st*)s2;
    return b->e-a->e;
}
int main()
{
    int i=0,j=0,n;
    char c;
    while(1) 
    {
        scanf("%d%d%c",&a[i].c,&a[i].e,&c);
        i++;
        if(c=='\n') break;
    }
    while(1) 
    {
        scanf("%d%d%c",&b[j].c,&b[j].e,&c);
        j++;
        if(c=='\n') break;
    }
    n=i*j;
    for(int k=0;k<i;k++)
    {
       for(int t=0;t<j;t++)
       {
           s[k*j+t].c=a[k].c*b[t].c;
           s[k*j+t].e=a[k].e+b[t].e;
       }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i].e==s[j].e)
            {
                s[i].c+=s[j].c;
                s[j].c=0;
            }
        }
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++)
    {
        if(s[i].c!=0)
        printf("%d %d ",s[i].c,s[i].e);
    }
    return 0;
}
