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
        root->left=root->right=NULL; // @@ [Typo: assigned root->left twice instead of root->right]
    }
    else if(num < root->num){
        root->left = in(root->left,num,high+1); // @@ [Used post-increment high++ which passes original value; should use high+1]
    }
    else{
        root->right = in(root->right,num,high+1); // @@ [Used post-increment high++ which passes original value; should use high+1]
    }
    return root;
}

void dfs(treep root)
{
    if (root==NULL) return; // @@ [Missing null check before dereferencing root; causes crash on empty tree or invalid access]
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