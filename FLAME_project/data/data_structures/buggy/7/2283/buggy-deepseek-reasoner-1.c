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
} // @@ The function is missing a return statement; it does not return the pointer p, leading to undefined behavior when the caller assigns the result.
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