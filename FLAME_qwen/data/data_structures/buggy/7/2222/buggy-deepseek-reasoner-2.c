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
    if(r->lc==NULL&&r->rc==NULL) 
    {
        printf("%d %d\n",r->data,h);
        return;
    }
    else if(r->lc!=NULL) shuchu(r->lc,h+1); // @@ [This else-if causes only the left subtree to be traversed when both left and right children exist. It should be a plain if to ensure both subtrees are visited.]
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ [This else-if is only executed when the left child is NULL. It should also be a plain if to always traverse the right subtree, ensuring all leaves are reached.]
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