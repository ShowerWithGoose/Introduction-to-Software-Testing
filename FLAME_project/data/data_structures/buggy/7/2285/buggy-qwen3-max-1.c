#include<stdio.h>
int k=1; // @@ [Using a global variable 'k' to track height is incorrect because it doesn't represent the actual depth of the current node in the recursion. Height should be passed as a parameter or computed based on parent's height.]
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
        p->roof=k; // @@ [Assigning global 'k' as roof (height) is wrong. The height of a new node should be parent's height + 1, but 'k' is being manipulated globally and reset after each insertion.]
        p->lc=p->rc=NULL;    
    }
    else if(i<p->data)
    {
        k++; // @@ [Incrementing global 'k' here affects all future insertions and does not correctly track the current path's depth. This leads to incorrect height values.]
        p->lc=insertBST(p->lc,i);
    }
    else if(i>=p->data)
    {
        k++; // @@ [Same issue as above: global 'k' is modified during traversal, leading to incorrect height assignment for nodes.]
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
        search(p->lc); // @@ [If p->lc is NULL, calling search(p->lc) will cause a segmentation fault (runtime error). Need to check for NULL before recursing.]
        search(p->rc); // @@ [Same as above: if p->rc is NULL, this causes a runtime error.]
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
        k=1; // @@ [Resetting 'k' to 1 after each insertion breaks the height tracking for subsequent insertions that require deeper traversal.]
    }
    search(root);
    return 0;
}