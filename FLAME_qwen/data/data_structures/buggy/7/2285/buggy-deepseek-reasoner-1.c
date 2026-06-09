#include<stdio.h> // @@ missing #include <stdlib.h> for malloc
int k=1;
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
        p=(BTREE)malloc(sizeof(BTNode)); // @@ implicit declaration of malloc; stdlib.h required
        p->data=i;
        p->roof=k; // @@ uses global k which may not reflect correct depth; should pass depth as parameter
        p->lc=p->rc=NULL;    
    }
    else if(i<p->data)
    {
        k++; // @@ increments global k without restoring; depth tracking is incorrect
        p->lc=insertBST(p->lc,i);
    }
    else if(i>=p->data)
    {
        k++; // @@ increments global k without restoring; depth tracking is incorrect
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
        search(p->lc); // @@ no NULL check; will crash if p->lc is NULL
        search(p->rc); // @@ no NULL check; will crash if p->rc is NULL
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
        k=1; // @@ resets global k incorrectly; depth context lost for subsequent insertions
    }
    search(root);
    return 0;
}