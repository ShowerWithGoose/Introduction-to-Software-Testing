#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct tree
{
    int data;
    int depth;
    struct tree *lchild;
    struct tree *rchild;
};
typedef struct tree Tree;
typedef struct tree *Treeptr;
void Visit(Treeptr t)
{
    printf("%d %d\n",t->data,t->depth);
}
void Traverse(Treeptr t)
{
    if(t != NULL)
    {
        Traverse(t->lchild);
        if(t->lchild == NULL && t->rchild == NULL)
            Visit(t);
        Traverse(t->rchild);
    }
}
Treeptr insert(Treeptr t,int data,int depth)
{
    if(t == NULL)
    {
        t = (Treeptr)malloc(sizeof(Tree));
        t->data = data;
        t->depth = depth;
        t->lchild = t->rchild = NULL;

    }
    else if(data < t->data)
        t->lchild = insert(t->lchild,data,depth+1);
    else if(data >= t->data)
        t->rchild = insert(t->rchild,data,depth+1);
    return t;
}
int main()
{
    int n,i;
    int data;
    Treeptr root = NULL;
    scanf("%d",&n);
    for(i = 0; i< n; i++)
    {
        scanf("%d",&data);
        //printf("test == %d\n",data);
        root = insert(root,data,1);

    }
    Traverse(root);
    return 0;

}



