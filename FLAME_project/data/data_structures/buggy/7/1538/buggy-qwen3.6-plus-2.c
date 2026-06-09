#include<stdio.h>
#include<stdlib.h>
typedef struct bst
{
    int data;
    struct bst *left,*right;
}tree;
typedef tree *treenode;
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
void search(treenode p,int height){
    if(p->left==NULL&&p->right==NULL){
        printf("%d %d\n",p->data,height);
    }
    else{
        if(p->left!=NULL) // @@ [The original code calls search(p->left, ...) unconditionally. If p->left is NULL but p->right is not (or vice versa), passing NULL to search causes a segmentation fault (Runtime Error) when accessing p->left or p->data inside the recursive call.]
        search(p->left,height+1);
        if(p->right!=NULL) // @@ [The original code calls search(p->right, ...) unconditionally. If p->right is NULL, passing NULL to search causes a segmentation fault (Runtime Error).]
        search(p->right,height+1);
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
    int h=1;
    search(root,h);
}