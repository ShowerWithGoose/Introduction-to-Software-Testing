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
    else if(p->num>=n) // @@ [Condition for left subtree incorrectly uses >=; should use < or > to match problem spec: left child less than root, right child greater or equal. This causes duplicate (equal) values to go left instead of right, altering tree structure and missing leaf 87.]
        p->left=insert(p->left,n);
    else if(p->num<n) // @@ [This condition is redundant and inverted; should simply be else to handle all remaining cases (greater or equal). As written, it only handles strictly less, so equal values fall through? Actually since first condition uses >=, the second uses <, it's exhaustive but direction wrong. Should be: if (n < p->num) left; else right.]
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