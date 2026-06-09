#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int data;
    int h;
    struct node *left,*right,*parent;
};
typedef struct node btnode;
typedef struct node *btnodeptr;
btnodeptr q;
btnodeptr insert(btnodeptr p,int a){
    if(p==NULL){
        p=(btnodeptr)malloc(sizeof(btnode));
        p->data=a;
        p->left=p->right=p->parent=NULL; // @@ Missing initialization of p->h; should set p->h = 1 (if root) or rely on parent, but here new node's height is not set.
    } 
    else if(a<p->data){
        q=insert(p,a); // @@ Error: recursive call with p instead of p->left; causes infinite recursion.
        p->left=q;
        q->parent=p;
        q->h=p->h+1;
}
    else if(a>p->data){ // @@ Error: missing case for a == p->data; should be else (or else if(a>=p->data)) to satisfy "right child >= root".
        q=insert(p,a); // @@ Error: same recursive call issue; should be p->right.
        p->right=q;
        q->parent=p;
        q->h=p->h+1;
}
    return p;
}
void bianli(btnodeptr t){
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,t->h);
        bianli(t->left);
        bianli(t->right);
        // @@ Error: traversal order is pre-order (root, left, right). To output leaf nodes from left to right (sorted order), should use in-order: left, root, right.
    }
}
int main(){
    int i,N,a;
    scanf("%d",&N);
    btnodeptr root=NULL;
    root->h=1; // @@ Error: dereferencing NULL pointer; root is NULL, causing undefined behavior.
    for(i=0;i<N;i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    bianli(root);
    return 0;
}