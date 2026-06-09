#include<stdio.h>
#include<stdlib.h>
typedef struct sz
{
    int x;
    struct sz *lchild,*rchild;    
}s,*str;
str intree(int a,str p);
void input(str p,int k);
int main()
{
    int n,i=1,a;
    str p=NULL;
    str root=p;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        p=intree(a,p); // @@ [The root pointer 'p' is updated correctly in the first call, but subsequent calls pass the current 'p' (which may not be the root) to intree. This breaks BST insertion because insertion must always start from the root. The function should always insert starting from the root node, not from the last inserted node.]
    }
    input(p,1);
    return 0;
 } 
str intree(int a,str p)
{
    if(p==NULL)
    {
        p=(str)(malloc)(sizeof(s));
        p->x=a;
        p->lchild=NULL;
        p->rchild=NULL;
    }
    else
    {
        if(a>=p->x)
        p->rchild=intree(a,p->rchild);
        else
        p->lchild=intree(a,p->lchild);
    }
    return p; // @@ [The function 'intree' does not return the node pointer in all code paths. When p != NULL, it modifies children but doesn't return p, leading to undefined behavior. This causes the assignment 'p = intree(a, p)' in main() to assign garbage or undefined value after the first insertion, breaking the tree structure.]
}
void input(str p,int k)
{
    if(p->lchild!=NULL)
    input(p->lchild,k+1);
    if(p->rchild!=NULL)
    input(p->rchild,k+1);
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->x,k);
    }
}