#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
    int data;
    struct bst *left,*right;
}tree;
typedef tree *treenode;
int h=1;
treenode insert(treenode p,int data){
    if(p==NULL){
        p=(treenode)malloc(sizeof(tree));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
    }
    else if(data<p->data){
        p->left=insert(p->left,data);
    }
    else if(data>=p->data){
        p->right=insert(p->right,data);
    }
    return p;
}
void search(treenode p){
    if(p==NULL){
        return;
    }
    else{
        if(p->left==NULL&&p->right==NULL){
            printf("%d %d\n",p->data,h);
        
        }
        h++;
        search(p->left);
        search(p->right);
        h--;
    }
}
int main(){
    treenode root=NULL;
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&m);
        root=insert(root,m);
    }
    search(root);
}

