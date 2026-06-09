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
        p->h = 1; // @@ [The height of the newly created node is not initialized. Although this specific line isn't the primary crash cause, uninitialized height propagates errors. However, the critical error is below.]
    } 
    else if(a<p->data){
        q=insert(p->left,a); // @@ [Recursive call should be on p->left, not p. Passing p causes infinite recursion and stack overflow because the condition a < p->data remains true for the same node.]
        p->left=q;
        q->parent=p;
        q->h=p->h+1;
}
    else if(a>p->data){
        q=insert(p->right,a); // @@ [Recursive call should be on p->right, not p. Passing p causes infinite recursion and stack overflow because the condition a > p->data remains true for the same node.]
        p->right=q;
        q->parent=p;
        q->h=p->h+1;
}
    else if (a == p->data) {
         // Handle duplicate values if necessary, typically right or left depending on spec. 
         // The problem says right child >= root. So duplicates go right.
         q=insert(p->right,a);
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
    root->h=1; // @@ [Runtime Error: root is NULL here. Dereferencing a NULL pointer causes a segmentation fault. Root should be initialized via insertion or allocated before accessing members.]
    for(i=0;i<N;i++){
        scanf("%d",&a);
        root=insert(root,a);
    }
    bianli(root);
    return 0;
}