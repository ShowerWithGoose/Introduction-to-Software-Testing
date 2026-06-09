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
void search(treeptr root,int *llevel) @@ [The function does not handle the case when root is NULL, which can lead to segmentation fault when traversing empty subtrees. Additionally, the height calculation is incorrect because it uses a shared pointer to level that gets decremented after recursive calls, but leaf nodes in different branches interfere with each other's level counts.]
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
    search(root,&level); @@ [Calling search with an uninitialized level logic; if the tree is empty (n=0), root is NULL and search will crash. Also, even for non-empty trees, the level tracking mechanism is flawed due to shared state across recursive paths.]
    return 0;
}