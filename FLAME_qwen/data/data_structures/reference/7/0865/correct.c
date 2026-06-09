#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct treenode{
    int val,height;
    struct treenode* left;
    struct treenode* right;
};
struct treenode *root=NULL;
void buildtree(struct treenode **t,int recn,int h);
void prn(struct treenode *t);
int main(){
    int n,i,recn;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&recn);
        buildtree(&root,recn,1);
    }
    prn(root);
    return 0;
}

void buildtree(struct treenode **t,int recn,int h){
    if(*t==NULL){
        *t=(struct treenode *)malloc(sizeof(struct treenode *));
        (*t)->left=NULL;(*t)->right=NULL;
        (*t)->val=recn;
        (*t)->height=h;
    }
    else if((*t)->val>recn)
        buildtree(&(*t)->left,recn,h+1);
    else
        buildtree(&(*t)->right,recn,h+1);
}

void prn(struct treenode *t){
    if(t!=NULL){
        prn(t->left);
        prn(t->right);
        if(t->left==NULL&&t->right==NULL)
            printf("%d %d\n",t->val,t->height);
    }
}
