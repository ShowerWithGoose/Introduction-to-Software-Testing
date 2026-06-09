#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>

typedef struct tree{
    int num;
    int high;
    struct tree *left,*right;
} tree, *treep;

treep in(treep root,int num,int high){
    if(root == NULL){
        root = (treep)malloc(sizeof(tree));
        root->num = num;
        root->high = high;
        root->left=root->left=NULL; // @@ [Error: Both left and right should be initialized; this sets left twice and leaves right uninitialized. Should be root->left=root->right=NULL;]
    }
    else if(num < root->num){
        root->left = in(root->left,num,high++); // @@ [Error: high++ passes the current height, not increased by 1. Should be high+1 to properly set child's height.]
    }
    else{
        root->right = in(root->right,num,high++); // @@ [Error: Same as above; should be high+1.]
    }
    return root;
}

void dfs(treep root)
{
    if (root->left==NULL && root->right==NULL)
    {
        printf("%d %d\n", root->num, root->high);
        return;
    }
    if (root->left!=NULL)
    {
        dfs(root->left);
    }
    if (root->right!=NULL)
    {
        dfs(root->right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    treep T=NULL;
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        T = in(T,num,1);
    }
    dfs(T);
    return 0;
}