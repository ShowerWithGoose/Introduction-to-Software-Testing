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
        (*llevel)++; // @@ The level is incremented even if child nodes are NULL, causing incorrect depth and potential crash when recursing on NULL.
        search(root->left,llevel); // @@ No NULL check; if left is NULL, this call will cause a segmentation fault.
        search(root->right,llevel); // @@ No NULL check; same issue for right child.
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
    search(root,&level);
    return 0;
}