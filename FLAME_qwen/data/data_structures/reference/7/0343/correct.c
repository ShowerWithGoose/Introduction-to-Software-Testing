#include<stdio.h>
#include<stdlib.h>

typedef struct node* ptr;
struct node
{
    int data;
    ptr left;
    ptr right;
};

int max(int a,int b);
int height(ptr p);
int nodeheight(ptr n,ptr t);//求某个节点所在高度
ptr insertBST(ptr p,int item);
ptr buildBST(int n,ptr *p,int k[]);//创建n个节点的BST
void preorderheight(ptr t,int i);//首次i取1

int a[100];

int main()
{
    int n=0;
    scanf("%d",&n);
    int i=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    ptr p=NULL;
    buildBST(n,&p,a);
    //int h=0;
    preorderheight(p,1);
    system("pause");
    return 0;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    return b;
}

int height(ptr p)
{
    if(p==NULL)
        return 0;
    else
        return 1+max(height(p->left),height(p->right));
}

ptr insertBST(ptr p,int item)
{
    if(p==NULL)
    {
        p=(ptr)malloc(sizeof(struct node));
        p->data=item;
        p->left=p->right=NULL;
    }
    else if(item<p->data)
        p->left=insertBST(p->left,item);
    else
        p->right=insertBST(p->right,item);
    return p;
}

ptr buildBST(int n,ptr *p,int k[])
{
    int i;
    *p=NULL;
    for(i=0;i<n;i++)
    {
        *p=insertBST(*p,k[i]);
    }
    return *p;
}

void preorderheight(ptr t,int i)
{
    if(t!=NULL)
    {
        if(t->right==NULL && t->left==NULL)
            printf("%d %d\n",t->data,i);
        preorderheight(t->left,i+1);
        preorderheight(t->right,i+1);
    }
}
