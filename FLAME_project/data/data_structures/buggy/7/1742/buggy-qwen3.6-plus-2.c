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
} // @@ The function 'paixu' is declared to return 'struct bst*', but it lacks a return statement. When 'p' is not NULL, the recursive calls update the children pointers, but the function does not return the current node 'p'. This leads to undefined behavior when the returned value is used in assignments like 'head=paixu(...)' or 'p->lchild=paixu(...)'. It should return 'p' at the end of the function.
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