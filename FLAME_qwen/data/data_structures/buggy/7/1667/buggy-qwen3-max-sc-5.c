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
    // @@ [The insertion logic does not handle the case where `item == p->data`. According to the problem, right child should be used for values >= root, but this code skips insertion when equal, causing missing nodes.]
    
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
// @@ [The traversal is not in-order; it's a pre-order traversal (visit, then left, then right). However, the function name `inorder` is misleading but not the core issue. The real problem is that the height tracking using a global/static-like variable `cnt` is incorrect for recursive tree traversals because it doesn't represent the actual depth of the current node—it gets corrupted by backtracking from different branches.]

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