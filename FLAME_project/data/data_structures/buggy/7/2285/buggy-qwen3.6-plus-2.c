#include<stdio.h>
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
        p=(BTREE)malloc(sizeof(BTNode));
        p->data=i;
        p->roof=k;
        p->lc=p->rc=NULL;    
    }
    else if(i<p->data)
    {
        k++;
        p->lc=insertBST(p->lc,i);
    }
    else if(i>=p->data)
    {
        k++;
        p->rc=insertBST(p->rc,i);
    }
    return p;
}
void search(BTREE p)
{
    if(p==NULL) return; // @@ [Missing null check causes Runtime Error (Segmentation Fault) when accessing members of NULL pointer in leaf nodes' children]
    if(p->lc==NULL&&p->rc==NULL)
    {
        printf("%d %d\n",p->data,p->roof);
    }
    else
    {
        search(p->lc);
        search(p->rc);
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
        k=1;
    }
    search(root);
    return 0;
}