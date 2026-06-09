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
    return p; // @@ The function is declared to return 'str' but was missing a return statement. Without returning the updated pointer (especially when creating a new node), the parent node's child pointer remains NULL or uninitialized, leading to an incorrect tree structure and potential crashes.
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