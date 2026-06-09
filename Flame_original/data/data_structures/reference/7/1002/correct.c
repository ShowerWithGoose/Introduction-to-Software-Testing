#include <stdio.h>
#include<stdlib.h>
struct tree{
    struct tree* left;
    int data;
    int height;
    struct tree* right;
};
typedef struct tree node;
typedef struct tree* nodep;
nodep insertbst(nodep p,int data,int h){
    h++;
    if(p==NULL){
        p=(nodep)malloc(sizeof(nodep));
        p->data=data;
        p->left=p->right=NULL;
        p->height=h;
    }
    else if(data<p->data)
        p->left=insertbst(p->left,data,h);
    else if(data>=p->data)
        p->right=insertbst(p->right,data,h);
    return p;
}

void op(nodep p){
    if(p){
        if (p->left == NULL && p->right == NULL) {
            printf("%d %d\n", p->data, p->height);
        }
        op(p->left);
        op(p->right);
    }
}
int main() {
    int n;
    int data;
    scanf("%d",&n);
    nodep root=NULL;
    while(n--){
        scanf("%d",&data);
        root= insertbst(root,data,0);
    }
    op(root);
    return 0;
}

