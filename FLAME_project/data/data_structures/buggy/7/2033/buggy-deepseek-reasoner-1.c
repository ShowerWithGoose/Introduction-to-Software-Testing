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
    else if(p->num>=n) // @@ This condition is reversed. According to problem, left child should have values less than root, so this should be (p->num > n) to send values less than p->num to left. The current condition sends values greater or equal to left, causing incorrect tree structure.
        p->left=insert(p->left,n);
    else if(p->num<n) // @@ This condition is also incorrect. It should be an else (or else if(p->num <= n)) because right child should have values greater or equal. As written, values less than p->num are sent to right, which is wrong.
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