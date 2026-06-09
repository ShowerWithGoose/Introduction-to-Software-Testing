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
        head=paixu(head,n,1);
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
    }
    else if(n<(p->data))
    p->lchild=paixu(p->lchild,n,t+1);
    else if(n>=(p->data))
    p->rchild=paixu(p->rchild,n,t+1);
} // @@ The function `paixu` is declared to return `struct bst*`, but it lacks a `return p;` statement at the end. When `p` is not NULL (i.e., we are recursing down the tree), the function does not return the updated pointer, leading to undefined behavior and likely causing the root or intermediate nodes to be lost or corrupted in the caller (`head=paixu(...)`). This results in an incorrect tree structure and thus wrong output.
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