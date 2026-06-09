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
        p=intree(a,p); // @@ [The root pointer 'p' is updated correctly in the first call, but subsequent calls pass the current 'p' (which may not be root) to intree. This breaks BST insertion logic because insertion must always start from the root. The function should always insert starting from the root node, not from the last inserted node.]
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
    return p; // @@ [The function 'intree' is declared to return a 'str', but there is no return statement in the non-NULL branch. This leads to undefined behavior. A return statement is missing at the end of the function.]
}
void input(str p,int k)
{
    if(p==NULL) return; // @@ [The function 'input' does not check for NULL before dereferencing 'p'. When called on an empty tree or with NULL child, it will crash or behave incorrectly. A base case for NULL is needed before accessing p->lchild or p->rchild.]
    if(p->lchild!=NULL)
    input(p->lchild,k+1);
    if(p->rchild!=NULL)
    input(p->rchild,k+1);
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->x,k);
    }
}