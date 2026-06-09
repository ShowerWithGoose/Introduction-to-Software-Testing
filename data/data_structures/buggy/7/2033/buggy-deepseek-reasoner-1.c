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
    else if(p->num>=n) // @@ [Error: Condition should be n < p->num for left child. Current logic sends equal values to left, but spec requires right child for >=. This violates BST definition.]
        p->left=insert(p->left,n);
    else if(p->num<n) // @@ [Error: This else-if is logically redundant; should be simple else (without condition) for right child. The condition p->num < n is always true here, but the logic is incorrect because equal values already went left.]
        p->right=insert(p->right,n);
        
    return p;  
}

//前序遍历
void perorder(node *t,int h)
{
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->num,h);
        perorder(t->left,h+1);
        perorder(t->right,h+1);
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