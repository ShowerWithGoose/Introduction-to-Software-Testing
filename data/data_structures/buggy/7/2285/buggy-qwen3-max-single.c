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
        search(p->lc); // @@ [If p->lc is NULL, calling search(p->lc) leads to dereferencing a NULL pointer, causing runtime error (segmentation fault).]
        search(p->rc); // @@ [Same issue: if p->rc is NULL, this call will crash. The function assumes non-NULL children when recursing.]
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
        k=1; // @@ [Resetting k to 1 after each insertion breaks height tracking. Height should accumulate during recursive descent, not reset globally per insertion.]
    }
    search(root);
    return 0;
}