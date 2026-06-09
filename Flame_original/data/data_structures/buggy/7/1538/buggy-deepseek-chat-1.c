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
        search(p->left,height+1); // @@ [Potential segmentation fault: if p->left is NULL, the function will try to access p->left->left and p->left->right in the next recursive call, causing undefined behavior. The else branch assumes both children exist, but a node may have only one child.]
        search(p->right,height+1); // @@ [Same issue as above: if p->right is NULL, accessing it in the recursive call will cause a segmentation fault.]
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