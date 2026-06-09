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
        head=paixu(head,n,1); // @@ [The function paixu does not return the root node correctly when inserting into an empty tree. The recursive call updates child pointers but the top-level assignment to head only happens on the first insertion. Subsequent insertions do not update head, but that's okay; however, the real issue is that paixu lacks a return statement in non-base cases, leading to undefined behavior.]
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
        return p; // @@ [Missing return statement in base case causes undefined behavior. Although p is assigned, without returning it, the caller receives garbage. This line should return p.]
    }
    else if(n<(p->data))
    p->lchild=paixu(p->lchild,n,t+1); // @@ [Function paixu does not return p at the end, so even though the recursive assignment may work, the function has no return value in non-NULL cases, causing undefined behavior when used in assignment (like head=paixu(...)).]
    else if(n>=(p->data))
    p->rchild=paixu(p->rchild,n,t+1); // @@ [Same as above: missing return p; at the end of the function leads to undefined behavior because the function is expected to return a struct bst*.]
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