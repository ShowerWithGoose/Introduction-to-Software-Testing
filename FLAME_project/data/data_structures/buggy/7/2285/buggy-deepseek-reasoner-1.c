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
    if(p->lc==NULL&&p->rc==NULL)
    {
        printf("%d %d\n",p->data,p->roof);
    }
    else
    {
        search(p->lc); // @@ [Potential null pointer dereference: p->lc may be NULL, causing crash when accessing p->data in the recursive call.]
        search(p->rc); // @@ [Potential null pointer dereference: p->rc may be NULL, causing crash when accessing p->data in the recursive call.]
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
        k=1; // @@ [Incorrect reset of global variable k after each insertion; height should be tracked recursively, not reset to 1 for each new number.]
    }
    search(root);
    return 0;
}