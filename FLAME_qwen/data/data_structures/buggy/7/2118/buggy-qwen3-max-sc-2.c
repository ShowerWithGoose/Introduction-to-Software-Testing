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
        printf("%d %d\n",root->data,*llevel+1); // @@ [The height of the root is defined as 1, but llevel starts at 0 and is incremented before visiting children. However, for leaf nodes that are the root (only one node), *llevel is 0, so *llevel+1 = 1 is correct. But for deeper leaves, the level tracking is flawed because the increment/decrement approach doesn't correctly track depth per path. The function should pass depth as a value, not use a shared pointer.]
    else
    {
        (*llevel)++;
        search(root->left,llevel);
        search(root->right,llevel);
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
    search(root,&level); // @@ [Passing a pointer to a single level variable causes incorrect depth calculation during traversal because left and right subtrees interfere with each other's level counts. Depth should be passed by value, not by reference.]
    return 0;
}