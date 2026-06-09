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
    if(root->left==NULL && root->right==NULL) // @@ [Error: root may be NULL if called recursively; accessing root->left causes segmentation fault. Need a NULL check first.]
        printf("%d %d\n",root->data,*llevel+1);
    else
    {
        (*llevel)++;
        search(root->left,llevel); // @@ [Error: root->left may be NULL; recursive call passes NULL and will crash in the next call.]
        search(root->right,llevel); // @@ [Error: root->right may be NULL; same issue as above.]
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