#include <stdio.h>

typedef struct node
{
    int data;
    int depth;
    struct node *lchild, *rchild;
}Tree;

Tree *insert(Tree *root, int temp, int depth); 
void search(Tree *root);                   

int main()
{
    Tree *root = NULL;
    int n,item;
    scanf("%d",&n);
    for (int i=0;i<n;i++) 
    {
        scanf("%d", &item);
        int depth=0;           //每个节点的深度 
        root=insert(root,item,depth);
    }
    search(root);             //查找叶节点 
    return 0;
}

Tree *insert(Tree *root,int temp,int depth)
{
    depth++;                                     //每个节点的深度 
    if (root==NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->data=temp;
        root->lchild=root->rchild=NULL;
        root->depth=depth;
    }
    else if (temp<root->data)
        root->lchild=insert(root->lchild,temp,depth);
    else if (temp>=root->data)
        root->rchild=insert(root->rchild,temp,depth);
    return root;
}

void search(Tree *root)
{
    if (root!=NULL)
    {
        if (root->lchild==NULL&&root->rchild==NULL)
        {
            printf("%d %d\n", root->data, root->depth);
        }
        search(root->lchild);
        search(root->rchild);
    }
}



