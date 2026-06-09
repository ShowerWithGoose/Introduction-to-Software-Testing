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
        search(p->left,height+1); // @@ [If p->left is NULL, calling search on it will cause a segmentation fault (dereferencing NULL pointer).]
        search(p->right,height+1); // @@ [If p->right is NULL, calling search on it will cause a segmentation fault (dereferencing NULL pointer).]
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
    search(root,h); // @@ [If the input n is 0, root will be NULL and passing it to search will cause a segmentation fault. However, in this test case n=10, so the immediate issue is within the search function when recursing on NULL children.]
}