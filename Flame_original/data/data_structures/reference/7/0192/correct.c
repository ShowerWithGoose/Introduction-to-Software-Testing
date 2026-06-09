#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LL  long long
#define ULL  unsigned long long

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}*Tree;

Tree insertBST(Tree p,int item){
    if(p==NULL){
        p=(Tree)malloc(sizeof(struct TreeNode));
        p->val=item;
        p->left=NULL;
        p->right=NULL;
    }else if(item<p->val){
        p->left=insertBST(p->left,item);
    }else{
        p->right=insertBST(p->right,item);
    }
    return p;
}

void inorder(Tree root,int height)
{
    if(!root)return;
    if(!root->left&&!root->right){
        printf("%d %d\n",root->val,height);
    }
    inorder(root->left,height+1);
    inorder(root->right,height+1);
}

int main(void)
{
    int n;
    Tree head=NULL;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        head=insertBST(head,x);
    }
    inorder(head,1);
    return 0;
}
// 13
// 50 38 30 64 58 40 10 73 70 50 60 100 35

