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
        search(root->left,llevel); @@ [When root->left is NULL, calling search with NULL leads to dereferencing NULL in the next recursive call, causing undefined behavior. Also, llevel is modified even when traversing NULL children, which corrupts level tracking.]
        search(root->right,llevel); @@ [Same issue as above: if root->right is NULL, this call will crash or behave incorrectly. Additionally, the level should only be incremented when moving to a valid child, not unconditionally.]
        (*llevel)--;
    }
}
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
    search(root,&level); @@ [The initial level is 0, but the root's height should be 1. The logic in search() does not correctly track node heights because it increments before recursing and doesn't handle NULL pointers safely.]
    return 0;
}