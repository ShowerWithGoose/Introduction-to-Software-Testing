#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINE 1024
int a[10086];
int gaodu[10086];
int b[10086];
int gao[10086];
typedef struct jiedian{
    int zhi;
    struct shu *rlink;
    struct shu *llink;
}*nt;
nt createjiedian(int n)
{
    nt p=(nt)malloc(sizeof(nt)+1); // @@ [Error: sizeof(nt) is the size of a pointer, not the struct; should be sizeof(struct jiedian) or sizeof(*p)]
    p->zhi=n;
    p->llink=NULL;
    p->rlink=NULL;
    return p;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int t;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    nt tou,p[1000],q;
    tou=createjiedian(a[0]);
    for(i=1;i<n;i++)
    {
        p[i]=createjiedian(a[i]);
        t=0;
        q=tou;
        gaodu[i]=1;
        while(t!=1)
        {
            if(a[i]<q->zhi&&q->llink!=NULL)
            {
                q=q->llink;
                gaodu[i]++;
            }


            else if(a[i]<q->zhi&&q->llink==NULL)
            {
                t=1;
                q->llink=p[i];
                gaodu[i]++;
            }
            else if(a[i]>=q->zhi&&q->rlink!=NULL)
            {
                q=q->rlink;
                gaodu[i]++;
            }
            else if(a[i]>=q->zhi&&q->rlink==NULL)
            {
                t=1;
                q->rlink=p[i];
                gaodu[i]++;
            }

        }
    }
    j=0;
    for(i=1;i<n;i++)
    {

        if(p[i]->llink==NULL&&p[i]->rlink==NULL)
        {
            b[j]=p[i]->zhi;
            gao[j]=gaodu[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        t=0;
        for(k=0;k<j;k++)
        {
            if(b[k]<b[t])
            {
                t=k;
            }
        }
        printf("%d %d\n",b[t],gao[t]);
        b[t]=10086;
    }
}