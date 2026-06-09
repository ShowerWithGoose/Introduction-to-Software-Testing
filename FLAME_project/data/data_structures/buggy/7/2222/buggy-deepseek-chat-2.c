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
    else if(r->lc!=NULL) shuchu(r->lc,h+1); // @@ [Error: This should not be 'else if' because it prevents traversing the right subtree when the left subtree is NULL but the right subtree is not NULL. The correct logic should traverse both subtrees independently, not as mutually exclusive branches.]
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ [Error: Same as above; this 'else if' prevents traversal of the right subtree when the left subtree exists. The traversal should be unconditional for both children after checking for leaf.]
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