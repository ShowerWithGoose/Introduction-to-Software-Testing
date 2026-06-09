#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left,*right,*parent;
};
typedef struct node btnode,*btnodeptr;
btnodeptr insertbst(btnodeptr p,int a);
void orphanage(btnodeptr t);
void preorder(btnodeptr t);
void visit(btnodeptr t);
int nodeheight(btnodeptr t);
int nodedepth(btnodeptr t);
int max(int a,int b);
int main()
{
    int i,N,a;
    btnodeptr root=NULL;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&a);
        root=insertbst(root,a);
    }
    orphanage(root);
    preorder(root);
    return 0;
}

btnodeptr insertbst(btnodeptr p,int a)
{
    if(p==NULL)
    {
        p=(btnodeptr)malloc(sizeof(btnode));
        p->data=a;
        p->left=p->right=p->parent=NULL;
    }
    else if(a<p->data)
    {
        p->left=insertbst(p->left,a);
    }
    else if(a>=p->data)
    {
        p->right=insertbst(p->right,a);
    }
    return p;
}

void orphanage(btnodeptr t)
{
    if(t!=NULL)
    {
        if(t->left!=NULL)
        {
            t->left->parent=t;
        }
        if(t->right!=NULL)
        {
            t->right->parent=t;
        }
        orphanage(t->left);
        orphanage(t->right);
    }
}

void preorder(btnodeptr t)
{
    if(t!=NULL)
    {
        visit(t);
        preorder(t->left);
        preorder(t->right);
    }
}

void visit(btnodeptr t)
{
    int d=0;
    if(t->left==NULL&&t->right==NULL)
    {
        d=nodedepth(t);
        printf("\n%d %d\n",t->data,d);
    }
}

int nodeheight(btnodeptr t)
{
    int h;
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        h=max(nodeheight(t->left),nodeheight(t->right))+1;
    }
    return h;
}

int nodedepth(btnodeptr t)
{
    int d=1;
    if(t==NULL)
    {
        return 0;
    }
    else
    {
        while(t->parent!=NULL)
        {
            t=t->parent;
            d++;
        }
        return d;
    }
}

int max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

