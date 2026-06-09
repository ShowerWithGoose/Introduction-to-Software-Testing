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
        perorder(t->left,h+1); // @@ [Function name 'perorder' is misspelled; should be 'preorder' to match typical naming and avoid confusion, but more critically, this causes no compilation error by itself. However, the real issue is in the BST insertion logic: the condition for left/right insertion is reversed relative to the problem statement. The problem says: left child < root, right child >= root. But here, when p->num >= n, it goes left — which means equal values go left, contradicting the requirement that right child is >= root. This leads to incorrect tree structure, hence wrong leaf output.]
        perorder(t->right,h+1); // @@ [Same as above: the insertion logic places equal values to the left, but problem requires them on the right. This causes incorrect BST construction, leading to wrong leaf nodes and heights in traversal.]
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