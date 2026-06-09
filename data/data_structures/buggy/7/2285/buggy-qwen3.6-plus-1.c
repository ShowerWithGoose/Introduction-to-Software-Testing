#include<stdio.h> // @@ Missing #include <stdlib.h> for malloc, causing compilation error.
int k=1; // @@ Using a global variable for height tracking is logically flawed; height should be passed as a parameter.
typedef struct node
{
    int data;
    int roof;
    struct node *lc,*rc;
}BTNode,*BTREE;
BTREE insertBST(BTREE p,int i)
{
    if(p==NULL)
    {
        p=(BTREE)malloc(sizeof(BTNode)); // @@ malloc is used without including stdlib.h.
        p->data=i;
        p->roof=k;
        p->lc=p->rc=NULL;    
    }
    else if(i<p->data)
    {
        k++; // @@ Global k increments monotonically across recursive calls, failing to track actual depth.
        p->lc=insertBST(p->lc,i);
    }
    else if(i>=p->data)
    {
        k++; // @@ Same issue: global counter does not correctly represent height per branch.
        p->rc=insertBST(p->rc,i);
    }
    return p;
}
void search(BTREE p)
{
    if(p->lc==NULL&&p->rc==NULL)
    {
        printf("%d %d\n",p->data,p->roof);
    }
    else
    {
        search(p->lc); // @@ Missing NULL check for p before recursive calls may cause segmentation fault.
        search(p->rc); // @@ Same as above.
    }
}
int n;
int main()
{
    scanf("%d",&n);
    int j,i;
    BTREE root=NULL;
    for(j=0;j<n;j++)
    {
        scanf("%d",&i);
        root=insertBST(root,i);
        k=1; // @@ Resetting global k after each insertion corrupts height values for the tree.
    }
    search(root);
    return 0;
}