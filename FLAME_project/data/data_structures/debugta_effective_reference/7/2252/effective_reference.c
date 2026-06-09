#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *lchild,*rchild;
};

typedef struct node BTNode;
typedef struct node *BTNodeptr;

int num=0;
int *leaf;

BTNodeptr insertBST(BTNodeptr t,int num);
void leafprint(BTNodeptr root);
void visit(BTNodeptr p,int leaf[]);
int laysearch(BTNodeptr root,int key);

int main()
{
    int n,i;
    int *a;
    BTNodeptr root=NULL;
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    leaf=(int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        root=insertBST(root,a[i]);
        //printf("%d\n",item[i]);
    }

    leafprint(root);
    for(i=0;i<num;i++)
    {
        printf("%d %d\n",leaf[i],laysearch(root,leaf[i]));
    }
    return 0;
}



BTNodeptr insertBST(BTNodeptr t,int num)
{
    if(t==NULL)
    {
        t=(BTNodeptr)malloc(sizeof(BTNode));
        t->data=num;
        t->lchild=NULL;
        t->rchild=NULL;
    }else if(num<t->data)
    {
        t->lchild=insertBST(t->lchild,num);
    }else{
        t->rchild=insertBST(t->rchild,num);
    }
    return t;

}

void leafprint(BTNodeptr root)
{
    if(root!=NULL)
    {
        visit(root,leaf);
        leafprint(root->lchild);
        leafprint(root->rchild);
    }

}

void visit(BTNodeptr p,int leaf[])
{
    if(p->lchild==NULL&&p->rchild==NULL)
    {
        leaf[num++]=p->data;
    }
}


int laysearch(BTNodeptr root,int key)
{
    BTNodeptr p=root;
    int layer=1;
    while(p!=NULL)
    {
        if(key==p->data&&p->lchild==NULL&&p->rchild==NULL)
        {
            return layer;
        }else if(key>p->data)
        {
            p=p->rchild;
            layer++;

        }else if(key<p->data)
        {
            p=p->lchild;
            layer++;
        }else{
            return (laysearch(p->lchild,key)==-1)?((laysearch(p->rchild,key))+1):((laysearch(p->lchild,key))+1);
        }
    }
    return -1;
}





