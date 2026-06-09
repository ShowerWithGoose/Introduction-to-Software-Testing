#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct bst
{
    int num;
    int height;
    struct bst *right,*left;
}bst;
typedef struct bst* node;
node insert(node root,int num)
{
    if(root==NULL){
        root=(node)malloc(sizeof(bst));
        root->num=num;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else{
        if(num<root->num)
            root->left=insert(root->left,num);
        else
            root->right=insert(root->right,num);
        return root;
    }
}
void print(node root,int height)
{
    if(root->left==NULL&&root->right==NULL){
        printf("%d %d\n",root->num,height);
        return;
    }
    if(root->left!=NULL)
        print(root->left,height+1);
    if(root->right!=NULL)
        print(root->right,height+1);
}
int main()
{
    int num[1000],n,i;
    scanf("%d",&n);
    node root=NULL;
    for(i=0;i<n;i++){
        scanf("%d",&num[i]);
        getchar();
        insert(root,num[i]); // @@ [The return value of insert is not assigned back to root, so the tree remains empty (root stays NULL). This causes a null pointer dereference in print().]
    }
    print(root,1); // @@ [If root is NULL (e.g., when n=1 but insert didn't update root), this will crash because print() dereferences root without checking for NULL.]
    
    return 0;
}