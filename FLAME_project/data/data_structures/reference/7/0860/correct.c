#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct bintree{
    int num;
    struct bintree *left,*right;
}BTNode;
BTNode *insert(BTNode *root,int n){
    BTNode *p=root;
    if(p==NULL){
        p=(BTNode*)malloc(sizeof(BTNode));
        p->num=n;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
        if(n<p->num){
            p->left=insert(p->left,n);
        }
        else if(n>=p->num) {
            p->right = insert(p->right, n);
        }
        return p;
}
void print(BTNode *root,int layer){
    BTNode * p=root;
    if(p->left==NULL&&p->right==NULL){
        printf("%d %d\n",p->num,layer);
    }
    if(p->left)
    print(p->left,layer+1);
    if(p->right)
    print(p->right,layer+1);
}
int main() {
        int n,i,num;
        BTNode * root=NULL;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&num);
            root=insert(root,num);
        }
        print(root,1);
}

