#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1024

typedef struct NODE{
    int num;
    struct NODE *left,*right;
}node;
node *root,*p;

//构建二叉查找树
node *insert(node *p,int n){
    if(p==NULL){
        p=(node *)malloc(sizeof(node));
        p->num=n;
        p->left=NULL; 
        p->right=NULL;
    }
    else if(p->num>=n)
        p->left=insert(p->left,n);
    else if(p->num<n)
        p->right=insert(p->right,n);
        
    return p;  
}

//前序遍历
void perorder(node *t,int h)
{
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->num,h);
        perorder(t->left,h+1); // @@ [Function name 'perorder' is misspelled; should be 'preorder' to match common naming and avoid confusion, but more critically, this causes no compilation error by itself. However, the real issue is in the BST insertion logic: the condition for left/right insertion is reversed relative to the problem statement. The problem says: left child < root, right child >= root. But here, when p->num >= n, it goes left — which means equal values go left, violating the spec which requires them to go right. This logic error affects tree structure but not compilation. However, the reported error is "Compilation Error" with message "gcc: not found", which is a system/environment issue, not code-related. But since the task asks to find errors in the program that cause failure on given test cases, and the output mismatch is due to traversal order and insertion logic, the critical bug is in the insertion condition. Yet the immediate cause of wrong output is that the traversal is preorder, but the problem requires leaf nodes "from left to right", which corresponds to inorder traversal, not preorder. So using preorder traversal visits root before children, which does not guarantee left-to-right leaf order in terms of in-order position. For example, a root with only a right child would print the root (if leaf) before any left subtree leaves, but if there's a deeper left leaf, preorder might visit it first — however, in a BST built with correct insertion, preorder does not yield left-to-right leaf order as defined by in-order sequence. The problem says "from left to right", meaning in the visual left-to-right layout of the tree, which corresponds to in-order traversal. Therefore, using preorder is incorrect.]
        perorder(t->right,h+1); // @@ [Same as above: traversal should be inorder to get left-to-right leaf order. Preorder does not guarantee that.]
    }
}

int main()
{
    int n,num;
    int ans=1;
    root=p=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        root=insert(root,num); 
    }
    perorder(root,ans);
    
    return 0;
}