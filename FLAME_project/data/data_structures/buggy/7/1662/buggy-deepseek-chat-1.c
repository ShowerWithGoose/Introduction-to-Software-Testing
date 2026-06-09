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
        getchar(); // @@ This line incorrectly consumes a character after each integer, which may cause input issues, especially when there is no newline or space after the number. For the test case "1\n5678", after reading 5678, getchar() will consume the newline, but this is not needed and can cause problems in other cases.
        insert(root,num[i]); // @@ The return value of insert is not assigned to root, so the tree remains empty (root is always NULL). This causes a segmentation fault when print is called with a NULL root.
    }
    print(root,1); // @@ root is still NULL because insert's return value was never assigned, leading to a runtime error when trying to access root->left in print.
    
    return 0;
}