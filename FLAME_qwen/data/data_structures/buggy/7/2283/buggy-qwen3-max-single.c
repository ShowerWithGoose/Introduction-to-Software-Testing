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
        p=intree(a,p);
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
    return p; // @@ [The function 'intree' is declared to return a 'str' (pointer), but lacks a return statement in the non-NULL branch, leading to undefined behavior. Also, when called initially with p=NULL, the updated root is returned, but in recursive calls, the return value must be used to assign to left/right child pointers. However, the main issue causing incorrect height and missing output is that the tree root may not be properly maintained because the first call's result is assigned to 'p', but subsequent insertions do not correctly build the tree due to missing return in all paths.]
}
void input(str p,int k)
{
    if(p==NULL) return; // @@ [The function 'input' does not check for NULL before dereferencing 'p'. When called on an empty tree or during recursion on NULL children, this leads to segmentation fault. The original reference program avoids this by only recursing when child != NULL, but here the base case is missing.]
    if(p->lchild!=NULL)
    input(p->lchild,k+1);
    if(p->rchild!=NULL)
    input(p->rchild,k+1);
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        printf("%d %d\n",p->x,k);
    }
}