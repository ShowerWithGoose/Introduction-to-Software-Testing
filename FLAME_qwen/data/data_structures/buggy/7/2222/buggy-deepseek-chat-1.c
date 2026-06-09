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
    else if(r->lc!=NULL) shuchu(r->lc,h+1);
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ [Error: This should be a separate if statement, not else if. The current logic only traverses one branch (left if it exists, otherwise right), but the correct inorder traversal should visit both children. Change to: if(r->lc!=NULL) shuchu(r->lc,h+1); if(r->rc!=NULL) shuchu(r->rc,h+1);]
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