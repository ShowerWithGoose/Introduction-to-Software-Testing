#pragma ide diagnostic ignored "cert-err34-c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8

typedef struct NODE{
    int data;
    int height;
    struct NODE *left,*right;
}BTtree,*BTtreeptr,BST,*BSTptr;
BTtreeptr head;

int h;
BTtreeptr threading(BTtreeptr head);
BSTptr insert(BSTptr p,int item,int k);
void visit(BSTptr T);
int main() {
    int n;
    int item;
    int input[200]={0};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&input[i]);
    }
    int k=1;
    for (int i = 0; i < n; ++i) {
        head=insert(head,input[i],k);
    }
//13
//
//50 38 30 64 58 40 10 73 70 50 60 100 35
    visit(head);

    return 0;
}
BSTptr insert(BSTptr p,int item,int k){
    if(p==NULL){
        p=(BSTptr) malloc(sizeof(BST));
        p->data=item;
        p->height=k;
        p->left=p->right=NULL;
    }
    else if(item>=p->data){
        k++;
        p->right=insert(p->right,item,k);
    }
    else if(item<p->data){
        k++;
        p->left= insert(p->left,item,k);
    }
    return p;
}
void visit(BSTptr T){
    if(T->left!=NULL)
        visit(T->left);
    if(T->right!=NULL)
        visit(T->right);
    if(T->right==NULL&&T->left==NULL)
    printf("%d %d\n",T->data,T->height);
}
