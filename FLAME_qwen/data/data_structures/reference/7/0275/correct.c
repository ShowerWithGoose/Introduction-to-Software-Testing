#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

TreeNode *initTreeNode(int val){
    TreeNode *p=malloc(sizeof(TreeNode));
    p->left=NULL;
    p->right=NULL;
    p->val=val;
    return p;
}

void addToTree(TreeNode **head,int val){
    if(*head==NULL){
        *head=initTreeNode(val);
        return;
    }
    if(val<(*head)->val)addToTree(&((*head)->left), val);
    else addToTree(&((*head)->right),val);
    return;
}

void breadthFirstSearch(TreeNode *head,int deep){
    if(!head)return;
    if(head->left==NULL && head->right==NULL){
        printf("%d %d\n",head->val,deep);
    }
    breadthFirstSearch(head->left, deep+1);
    breadthFirstSearch(head->right, deep+1);
    return;
}

int main(){
    TreeNode *head=NULL;
    int n;
    scanf("%d",&n);
    int num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        addToTree(&head,num);
    }
    breadthFirstSearch(head,1);
    return 0;
}

