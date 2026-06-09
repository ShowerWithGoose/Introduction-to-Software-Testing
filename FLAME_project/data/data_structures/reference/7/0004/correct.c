# include <stdio.h>
# include <malloc.h>
typedef struct bst
{
    int data;
    int high;
    struct bst* left_child;
    struct bst* right_child;
}Btree,*pBtree;

pBtree SET(pBtree,int,int);
void OUTPUT(pBtree);
int main()
{
    int n=0;
    scanf("%d",&n);
    pBtree tree_root=NULL;
    for(int i=0;i<n;i++)
    {
        int deep=0;
        int temp=0;
        scanf("%d",&temp);
        tree_root=SET(tree_root,temp,deep);
    }
    OUTPUT(tree_root);
    getchar();
    getchar();
    return 0;
}
pBtree SET(pBtree root,int num,int count)
{
    count++;
    if (root == NULL)
    {
        root=(pBtree)malloc(sizeof(Btree));
        root->data=num;
        root->high=count;
        root->left_child=NULL;
        root->right_child=NULL;
    }
    else if(num < root->data)
        root->left_child=SET(root->left_child,num,count);
    else if(num >= root->data)
        root->right_child=SET(root->right_child,num,count);
    return root;
}
void OUTPUT(pBtree root)
{
    if(root == NULL)
        return;
    if(root->left_child == NULL && root->right_child == NULL)
        printf("%d %d\n",root->data,root->high);
    OUTPUT(root->left_child);
    OUTPUT(root->right_child);
}


