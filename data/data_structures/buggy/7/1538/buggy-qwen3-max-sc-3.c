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
        if(p->left != NULL) search(p->left,height+1); // @@ [Calling search on NULL pointer when p->left is NULL leads to segmentation fault]
        if(p->right != NULL) search(p->right,height+1); // @@ [Calling search on NULL pointer when p->right is NULL leads to segmentation fault]
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
    if(root != NULL) search(root,h); // @@ [Calling search with NULL root when input n is 0 leads to segmentation fault]
}