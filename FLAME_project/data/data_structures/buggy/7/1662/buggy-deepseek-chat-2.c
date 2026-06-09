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
        getchar(); // @@ This line reads and discards the newline character after each integer, but it may cause issues if input is not separated by newlines; more importantly, it does not affect the main error.
        insert(root,num[i]); // @@ The return value of insert is not assigned to root, so the tree remains empty (root is always NULL). This causes a segmentation fault when print(root,1) is called because root is NULL.
    }
    print(root,1); // @@ root is still NULL here, leading to a runtime error when trying to access root->left in the print function.
    
    return 0;
}