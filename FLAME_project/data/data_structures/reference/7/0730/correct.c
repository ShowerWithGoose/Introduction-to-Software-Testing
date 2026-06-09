#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
    int num;
    struct bst *l;
    struct bst *r;
}
*t;
t f(int n,t p)
{
    if(!p)
    {
        p=(t)malloc(sizeof(struct bst));
        p->num=n;
        p->l=NULL;
        p->r=NULL;
    }
    else
    {
        if(p->num>n)
        p->l=f(n,p->l);
        else
        p->r=f(n,p->r);
    }
    return p;
}
void bian(t T,int h)
{
    if(!T)
    return;
    if(!T->l&&!T->r)
    printf("%d %d\n",T->num,h);
    else
    {
        bian(T->l,h+1);
        bian(T->r,h+1);
    }
}
int s,i,x;
int main() {
    t root=NULL;
    scanf("%d",&s);
    for(i=0;i<s;i++){
        scanf("%d",&x);
        root=f(x,root);
    }
    bian(root,1);
    return 0;
}

