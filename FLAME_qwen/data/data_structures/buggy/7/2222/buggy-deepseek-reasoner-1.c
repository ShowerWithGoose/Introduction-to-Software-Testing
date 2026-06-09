#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree
{
    int data;
    struct tree* lc;
    struct tree* rc;
}tree;
typedef tree* t;
t shuru(t r,int x)
{
    if(r==NULL)
    {
        r=(tree*)malloc(sizeof(tree));
        r->data=x;
        r->lc=r->rc=NULL;
        return r;
    }
    else
    {
        if(x<r->data) r->lc=shuru(r->lc,x);
        else r->rc=shuru(r->rc,x);
        return r;
    }
}
void shuchu(t r,int h)
{
    if(r->lc==NULL&&r->rc==NULL) // @@ [Missing NULL check: if r is NULL (empty tree), this line causes segmentation fault. Should check if(r==NULL) return; first.]
    {
        printf("%d %d\n",r->data,h);
        return;
    }
    else if(r->lc!=NULL) shuchu(r->lc,h+1); // @@ [Incorrect condition: should be a separate if (not else if) to ensure both left and right children are traversed when both exist. Currently, if left child exists, right child is skipped.]
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ [Incorrect condition: should be a separate if (not else if) to ensure both children are traversed. Additionally, the order should be left then right for proper left-to-right output, but the else-if chain only allows one branch.]
}
int main()
{
    int n;
    scanf("%d",&n);
    t r=NULL;
    int x;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        r=shuru(r,x);
    }
    shuchu(r,1);
    return 0;
}