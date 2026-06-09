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
    if(r==NULL) return; // @@ Missing null check for root or empty subtree, causing potential crash or logical error if called on NULL
    if(r->lc==NULL&&r->rc==NULL) 
    {
        printf("%d %d\n",r->data,h);
        return;
    }
    // @@ The use of 'else if' prevents traversing both subtrees. If a node has both left and right children, only the left is visited. If it has only right, it is visited. But if it has left, right is ignored. This fails to print all leaves.
    else if(r->lc!=NULL) shuchu(r->lc,h+1);
    // @@ Should be an independent 'if' statement to ensure the right subtree is also traversed when necessary, not mutually exclusive with the left subtree traversal.
    else if(r->rc!=NULL) shuchu(r->rc,h+1);
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