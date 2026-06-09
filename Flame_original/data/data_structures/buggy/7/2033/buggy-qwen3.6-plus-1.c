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
    else if(p->num>=n) @@ Logical error: Condition for left child insertion is reversed. According to the problem, left child values must be strictly less than the root, so it should be `n < p->num`.
        p->left=insert(p->left,n);
    else if(p->num<n) @@ Logical error: Condition for right child insertion is reversed. According to the problem, right child values must be greater than or equal to the root, so it should be `n >= p->num` or simply `else`.
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
    for(int i=0;i<n;i++){ @@ Potential compilation error in C89: Declaring loop variable `i` inside the `for` statement is not supported. Declare `int i;` before the loop or ensure C99 standard is used.
        scanf("%d",&num);
        root=insert(root,num); 
    }
    perorder(root,ans);
    
    return 0;
}