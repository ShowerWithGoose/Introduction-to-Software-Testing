#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}TREE,*treeptr;
void insert(treeptr* root,int num)
{
    if(*root==NULL)
    {
        treeptr now;
        now=(treeptr)malloc(sizeof(TREE));
        now->data=num;
        now->left=NULL;
        now->right=NULL;
        *root=now;
    }
    else if(num>=(*root)->data)
        insert(&(*root)->right,num);
    else
        insert(&(*root)->left,num);
}
void search(treeptr root,int *llevel)
{
    if(root->left==NULL && root->right==NULL)
        printf("%d %d\n",root->data,*llevel+1);
    else
    {
        (*llevel)++;
        search(root->left,llevel);
        search(root->right,llevel);
        (*llevel)--;
    }
} // @@ [The traversal logic incorrectly modifies a shared level counter, causing incorrect height calculation for leaf nodes. The height should be passed by value, not by reference. Also, when root is NULL (e.g., child of a node), the function will dereference a null pointer, leading to runtime error.]

int main()
{
    int n,num,i,level=0;
    treeptr root=NULL;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&num);
        insert(&root,num);
    }
    search(root,&level); // @@ [Calling search with a NULL root (if n=0) would crash, but more critically, the search function does not handle NULL children safely. When a node has only one child, the recursive call on the NULL child will cause a segmentation fault because the function immediately accesses root->left and root->right without checking if root is NULL.]
    return 0;
}