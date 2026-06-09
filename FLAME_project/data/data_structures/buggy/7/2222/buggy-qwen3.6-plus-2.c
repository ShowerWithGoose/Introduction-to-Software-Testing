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
    if(r==NULL) return; // @@ The function lacks a null check for the root node, which can cause a crash or undefined behavior if called on an empty tree or during recursion logic adjustments. More importantly, the logic below is flawed.
    if(r->lc==NULL&&r->rc==NULL) 
    {
        printf("%d %d\n",r->data,h);
        return;
    }
    else if(r->lc!=NULL) shuchu(r->lc,h+1); // @@ The use of 'else if' prevents traversing the right subtree if the left subtree exists. This means only one path is followed, missing other leaf nodes. It should be two separate if statements or an else block that handles both children properly without mutual exclusion.
    else if(r->rc!=NULL) shuchu(r->rc,h+1); // @@ Because of the previous 'else if', this line is only reached if the left child is NULL. If both children exist, the right child is never visited. This causes the program to miss most leaf nodes.
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