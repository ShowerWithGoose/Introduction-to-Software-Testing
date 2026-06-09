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
        p->left=p->right=p->parent=NULL;
    } 
    else if(a<p->data){
        q=insert(p,a); // @@ [Error: Should be insert(p->left, a) instead of insert(p, a); this causes infinite recursion because p is never NULL]
        p->left=q;
        q->parent=p;
        q->h=p->h+1;
}
    else if(a>p->data){
        q=insert(p,a); // @@ [Error: Should be insert(p->right, a) instead of insert(p, a); same infinite recursion issue]
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
    }
}
int main(){
    int i,N,a;
    scanf("%d",&N);
    btnodeptr root=NULL;
    root->h=1; // @@ [Error: Dereferencing NULL pointer; root is NULL, so root->h causes undefined behavior]
    for(i=0;i<N;i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    bianli(root);
    return 0;
}