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
    struct shu *rlink; // @@ The type 'struct shu' is undefined. It should be 'struct jiedian'. Also, forward declaration is missing or incorrect.
    struct shu *llink; // @@ The type 'struct shu' is undefined. It should be 'struct jiedian'.
}*nt;
nt createjiedian(int n)
{
    nt p=(nt)malloc(sizeof(nt)+1); // @@ Incorrect memory allocation size. 'sizeof(nt)' is the size of a pointer, not the structure. It should be 'sizeof(struct jiedian)' or 'sizeof(*p)'.
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
    for(i=1;i<n;i++) // @@ This loop starts from 1, ignoring the root node (index 0 in 'tou', but nodes are stored in p starting from index 1? No, 'tou' is separate. The nodes inserted are in p[1]...p[n-1]. However, if n=1, this loop doesn't run, which is correct for non-root leaves. But wait, where is the root's leaf status checked? If n=1, the root is a leaf. The current logic misses the root node entirely because 'tou' is not in array 'p' and the loop starts at 1.
    {

        if(p[i]->llink==NULL&&p[i]->rlink==NULL)
        {
            b[j]=p[i]->zhi;
            gao[j]=gaodu[i];
            j++;
        }
    }
    // @@ Missing check for the root node 'tou'. If n==1, 'tou' is a leaf with height 1. The code outputs nothing.
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