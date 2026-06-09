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
        search(root->left,llevel); @@ [Passing NULL pointer to search when root->left is NULL leads to dereferencing NULL in recursive call]
        search(root->right,llevel); @@ [Passing NULL pointer to search when root->right is NULL leads to dereferencing NULL in recursive call]
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
    search(root,&level); @@ [Calling search with root=NULL when n=0 causes dereference of NULL pointer; also, initial level should be 1 for root height]
    return 0;
}