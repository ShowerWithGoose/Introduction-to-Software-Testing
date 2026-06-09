# include <stdio.h>
# include <stdlib.h>

typedef struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
} node;
typedef node* bst;

bst insert(bst root, int insert_data) ;
void printleaf(bst root, int height);


int main()
{
    int n;
    scanf("%d", &n);
    bst root = NULL;
    int tmp;
    for (int i = 0; i < n; i++) { 
        scanf("%d", &tmp);
        root = insert(root, tmp);
    }
    printleaf(root, 1); 
    return 0;
}

bst insert(bst root,int insert_data)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=insert_data;
        root->lchild=NULL;
        root->rchild=NULL;
        return root;
    }
    else
    {if(insert_data<root->data)
    {
    
        root->lchild=insert(root->lchild,insert_data);
    }
    else
    {
        

        root->rchild=insert(root->rchild,insert_data);} // @@ Missing return statement for the non-NULL case; the function does not return the root after insertion, causing undefined behavior.
    }
}

void printleaf(bst root, int height)
{
    if (root -> lchild == NULL && root -> rchild == NULL) {
        printf("%d %d\n", root -> data, height);
        return;
    }
    if (root -> lchild != NULL) {
        printleaf(root -> lchild, height + 1);
    }
    if (root -> rchild != NULL) {
        printleaf(root -> rchild, height + 1);
    }
}