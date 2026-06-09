#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE  1024

typedef int Datatype;
struct node {
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode,*BTNodeptr;

int cnt=0;

BTNodeptr insertBST(BTNodeptr p, Datatype item){
    if(p==NULL){
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->left=p->right=NULL;
    } 
    else if(item<p->data)
        p->left=insertBST(p->left,item);
    else if(item>p->data)
       p->right=insertBST(p->right,item);
    // @@ [The insertion logic ignores equal values (item == p->data), violating the problem's requirement that right child should be >= root. This causes duplicate values to be silently dropped, leading to incorrect tree structure.]
    
    return p;
}

void inorder(BTNodeptr t){
    if(t!=NULL){
        cnt++;
        if(t->left==NULL&&t->right==NULL){
            printf("%d %d\n",t->data,cnt);
        }
        inorder(t->left);
        inorder(t->right);
        cnt--;
       }
}
// @@ [The traversal function is named 'inorder' but actually performs a preorder traversal (visits node before children). However, the bigger issue is using a global/static-like variable 'cnt' to track height, which gets corrupted during backtracking in recursive calls because multiple branches interfere with each other's height counts.]

int main()
{
    int n,item,i;
    BTNodeptr root=NULL;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){ 
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    
    inorder(root);
     
    return 0;
}