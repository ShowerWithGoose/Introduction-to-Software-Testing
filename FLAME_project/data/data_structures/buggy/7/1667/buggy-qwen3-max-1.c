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
    // @@ [The insertion logic does not handle duplicate values correctly. According to the problem, right child should be >= root, but this code only inserts if item > p->data, so duplicates (like the second 100) are ignored and not inserted into the tree.]
    
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
// @@ [The traversal is not a true in-order traversal; it visits root, then left, then right (pre-order). However, the bigger issue is that the height tracking using global 'cnt' is incorrect because it increments before checking children and decrements after both recursive calls, which doesn't reflect actual depth during leaf visitation. But the main cause of missing '100' is the insertion bug.]

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