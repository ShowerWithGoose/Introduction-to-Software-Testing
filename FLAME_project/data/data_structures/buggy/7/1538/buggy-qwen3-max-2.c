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
        search(p->left,height+1); // @@ [Passing NULL pointer to recursive call when p->left is NULL, leading to dereferencing NULL in next call]
        search(p->right,height+1); // @@ [Passing NULL pointer to recursive call when p->right is NULL, leading to dereferencing NULL in next call]
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
    search(root,h); // @@ [If root is NULL (n=0), this would pass NULL to search, but test case has n=10 so root is not NULL. However, the real issue is in search function when it recursively calls on NULL children]
}