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
    else if(p->num>=n) // @@ The problem states left child is less than root, right child is greater than or equal. This condition puts values equal to the root in the left subtree, which is incorrect. It should be p->num > n for left, and else (which covers >=) for right.
        p->left=insert(p->left,n);
    else if(p->num<n) // @@ This condition is redundant and logically inconsistent with the previous error. Since the first 'if' handles NULL, and the second 'else if' handles >= (incorrectly), this branch handles <. However, due to the logic error above, equal elements go left. The correct logic for "left < root" and "right >= root" is: if (n < p->num) go left; else go right.
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