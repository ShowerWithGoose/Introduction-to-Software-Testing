#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct binnode
{
    int data;
    int high;
    struct binnode *parent;
    struct binnode *leftchild;
    struct binnode *rightchild;
}binnode,*bintree;
bintree root;
void initialnode(bintree pointer,int num)
{
    pointer->data=num;
    pointer->high=1;
    pointer->leftchild=NULL;
    pointer->rightchild=NULL;
}
bintree find(bintree source,int n)
{
    if(n>=source->data)
    {
        if(source->rightchild==NULL)
            return source;
        else
            find(source->rightchild,n);
    }
    else
    {
        if(source->leftchild==NULL)
            return source;
        else
            find(source->leftchild,n);
    }
}
void creatnode()
{
    int num;
    bintree tmp,direct;
    scanf("%d",&num);
    tmp=(bintree)malloc(sizeof(binnode));
    initialnode(tmp,num);
    direct=find(root,num);
    if(num>=direct->data)
        direct->rightchild=tmp;
    else
        direct->leftchild=tmp;
    tmp->parent=direct;
    tmp->high=direct->high+1;
}
void output(bintree p)
{
    if(p==NULL)
        return;
    output(p->leftchild);
    if(p->leftchild==NULL&&p->rightchild==NULL)
    {
        printf("%d %d\n",p->data,p->high);
        return;
    }
    output(p->rightchild);
}
int main()
{
    int n,i,num;
    scanf("%d",&n);
    root=(bintree)malloc(sizeof(binnode));
    scanf("%d",&num);
    initialnode(root,num);
    root->parent=NULL;
    for(i=2;i<=n;i++)
        creatnode();
    output(root);
    return 0;
}



