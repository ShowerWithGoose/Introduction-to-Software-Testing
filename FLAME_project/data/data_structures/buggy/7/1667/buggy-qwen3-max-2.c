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
    // @@ [The insertion logic is incorrect: it ignores duplicate values (item == p->data). According to the problem, right child should be >= root, so duplicates should go to the right. This causes missing nodes like the second 100.]
    
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
// @@ [The traversal is not a true in-order traversal; it prints leaf nodes during pre-order (before recursing), but more critically, the height tracking is flawed because cnt is incremented once per node entry and decremented once per exit, but both children are traversed at the same cnt level. However, the main issue causing the missing '100' leaf is the insertion bug above.]

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