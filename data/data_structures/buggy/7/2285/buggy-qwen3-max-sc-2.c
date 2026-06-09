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
        p=(BTREE)malloc(sizeof(BTNode)); // @@ [Missing #include <stdlib.h> for malloc, causing compilation error]
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
        search(p->lc); // @@ [Dereferencing NULL pointer when p->lc is NULL, leading to runtime crash; should check for NULL before recursive call]
        search(p->rc); // @@ [Dereferencing NULL pointer when p->rc is NULL, leading to runtime crash; should check for NULL before recursive call]
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