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
        root = insert(root,num[i]); // @@ The return value of insert (which may be the newly allocated root) was ignored, causing root to remain NULL when the tree was empty, leading to a crash in print() or incorrect behavior.
    }
    print(root,1);
    
    return 0;
}