#include <stdio.h>
#include <stdlib.h>
struct numo{
    int coe;
    int pow;
    struct numo *next;
};
typedef struct numo node;
typedef struct numo *nodep;
int  comp(const void* p1,const void *p2)
{
    return (((int *)p2)[1]-((int *)p1)[1]);
}
int main() {
    int a,n;
    char c='a';
    int sum1=0,sum2=0;
    nodep first1=NULL,first2=NULL,p=NULL,q,r;
    while(c!='\n')
    {
        scanf("%d%d%c",&a,&n,&c);
        q=(nodep)malloc(sizeof(node));
        q->coe=a;
        q->pow=n;
        q->next=NULL;
        if(first1==NULL) first1=p=q;
        else
        {
            p->next=q;
            p=p->next;
        }
        sum1++;
    }
    c='a';
    while(c!='\n')
    {
        scanf("%d%d%c",&a,&n,&c);
        q=(nodep)malloc(sizeof(node));
        q->coe=a;
        q->pow=n;
        q->next=NULL;
        if(first2==NULL) first2=p=q;
        else
        {
            p->next=q;
            p=p->next;
        }
        sum2++;
    }
    int ans[1000][2]={};
    int i,j,k=0;
    p=first2;
    r=first1;
    int sum3=0;
    for(i=0;i<sum1;i++,r=r->next)//
    {
        for(j=0;j<sum2;j++,p=p->next,sum3++)
        {
            ans[k][0]=(p->coe)*(r->coe);
            ans[k++][1]=(p->pow)+(r->pow);
        }
        p=first2;
    }
    qsort(ans,sum3,sizeof(ans[0]),comp);
    for(i=0;i<sum3;i++)
    {
        if(ans[i][0]!=0)
        {
            for(k=1;ans[k+i][1]==ans[i][1];k++)
            {
                ans[i][0]+=ans[k+i][0];
                ans[k+i][0]=0;
            }
            printf("%d %d ",ans[i][0],ans[i][1]);
        }
    }
    free(q);
    return 0;
}

