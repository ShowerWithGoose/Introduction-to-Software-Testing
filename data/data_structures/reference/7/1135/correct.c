#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int num;
    int depth;
    struct tree *left;
    struct tree *right;
} bst;
struct tree *root=NULL;
void build(struct tree *(*p),int num,int depth);//构建二叉排序树
void find(struct tree *p);//查找叶节点并且打印
int main()
{
    int i,n,num,depth;
    scanf("%d",&n);
    for(i=0,depth=0; i<n; i++)
    {
        scanf("%d",&num);
        build(&root,num,depth);
    }
    find(root);
    return 0;
}

void build(struct tree *(*p),int num,int depth)//传址
{
    if(*p==NULL)
    {
        *p=(struct tree*)malloc(sizeof(bst));
        (*p)->num=num;
        (*p)->depth=depth;
        (*p)->left=NULL;
        (*p)->right=NULL;
    }
    else if(num<(*p)->num)
        build(&((*p)->left),num,depth+1);
    else
        build(&((*p)->right),num,depth+1);
}

void find(struct tree *p)//形参
{
    if(p!=NULL)
    {
        if(p->left==NULL&&p->right==NULL)
            printf("%d %d\n",p->num,p->depth+1);
        find(p->left);
        find(p->right);
    }
}


