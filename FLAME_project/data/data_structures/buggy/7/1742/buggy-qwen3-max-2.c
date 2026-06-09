#include<stdio.h>
#include<malloc.h>
struct bst
{
    int data;
    int depth;
    struct bst *lchild,*rchild;
}*head,*p;
struct bst* paixu(struct bst *p,int n,int t);
void bianli(struct bst *p);
int main()
{
    int n,number,i,t=1;
    scanf("%d",&number);
    for(i=0;i<number;i++)
    {
        scanf("%d",&n);
        head=paixu(head,n,1); // @@ [The function paixu does not return a value in all control paths, leading to undefined behavior when assigning to head. Also, the initial depth passed is always 1, but recursive calls correctly use t+1; however, the missing return statement breaks the tree construction.]
    }
    bianli(head);
    return 0;
}
struct bst *paixu(struct bst *p,int n,int t)
{
    if(p==NULL)
    {
        p=(struct bst*)malloc(sizeof(struct bst));
        p->data =n;
        p->depth =t;
        p->lchild =NULL;
        p->rchild =NULL;
        return p; // @@ [Missing return statement here causes the function to return garbage when creating a new node, breaking the BST structure.]
    }
    else if(n<(p->data))
    p->lchild=paixu(p->lchild,n,t+1);
    else if(n>=(p->data))
    p->rchild=paixu(p->rchild,n,t+1);
    return p; // @@ [Missing return statement at the end of the function; without it, the function returns an undefined value in non-base cases, causing incorrect tree links.]
}
void bianli(struct bst *p)
{
    if(p!=NULL)
    {
        bianli(p->lchild );
        if(p->lchild ==NULL&&p->rchild ==NULL)
            printf("%d %d\n",p->data ,p->depth );
        bianli(p->rchild );
    }
}