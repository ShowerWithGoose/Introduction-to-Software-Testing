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
    else if(r->lc!=NULL) shuchu(r->lc,h+1); // @@ [Only traverses left subtree if it exists, skips right subtree when left exists, violating in-order (left-to-right) leaf traversal requirement]
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ [Only traverses right subtree if left is NULL and right exists; misses cases where both children exist — should always traverse both subtrees recursively]
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
    shuchu(r,1); // @@ [If the tree is empty (n=0), r is NULL, and passing NULL to shuchu causes dereference of NULL pointer in 'if(r->lc==NULL&&r->rc==NULL)', leading to runtime crash]
    return 0;
}