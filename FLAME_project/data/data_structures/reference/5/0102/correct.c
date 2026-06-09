#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
typedef int ElemType;
typedef struct node{
    ElemType data;
    struct node * link;
}LNode,* LinkList;
int a[10005],b[10005],c[10005],d[10005],e[10005],f[10005];
int depth(int s)
{
    int n=0;
    while (s>0)
    {
        s/=10;
        n++;
    }
    return n;
}
int num(char * p,int * a,int * b)
{
    char *k,*l;
    int s,n=0;
    k=p;
    l=&p[strlen(p)-1];
    for (k=p;k<=l;k++)
    {
        a[n]=atoi(k);
        k=k+depth(a[n])+1;
        b[n++]=atoi(k);
        k=k+depth(b[n-1]);
    }
    return n;
}
int main()
{
    int n=0,m=0,i,j,t=0,u=0,number=0;
    char p[10005],q[10005];
    gets(p);
    gets(q);
    n=num(p,a,b);
    m=num(q,c,d);
    //printf("%d %d\n",n,m);
    for (i=0;i<n;i++)
    {
        for (j=0;j<m;j++)
        {
            e[t]=a[i]*c[j];
            f[t++]=b[i]+d[j];
        }
    }
    for (i=0;i<t;i++)
    {
        for (j=0;j<t-i-1;j++)
        {
            if (f[j]<f[j+1])
            {
                u=e[j];
                e[j]=e[j+1];
                e[j+1]=u;
                u=f[j];
                f[j]=f[j+1];
                f[j+1]=u;
            }
        }
    }
    //for (i=0;i<t;i++) printf("%d %d %d\n",e[i],f[i],t);
    for (i=0;i<t;i++)
    {
        u=f[i];
        number+=e[i];
        if (f[i]!=f[i+1])
        {
            printf("%d %d ",number,u);
            number=0;
        }
        if (i==t-1&&f[i]==0)
        {
            printf("%d %d",number,u);
        }
    }
    return 0;
}

