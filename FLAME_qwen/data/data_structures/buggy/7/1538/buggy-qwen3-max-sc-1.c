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
        if(p->left != NULL) search(p->left,height+1); // @@ [When p->left is NULL, calling search(p->left, height+1) leads to dereferencing a null pointer, causing runtime error (segmentation fault). Similarly for p->right.]
        if(p->right != NULL) search(p->right,height+1); // @@ [Same issue: passing NULL to search and then accessing p->left/p->right in the next call causes undefined behavior.]
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
    if(root != NULL) search(root,h); // @@ [If the input n is 0, root remains NULL, and calling search(root, h) would dereference a null pointer. However, the problem states that n integers are read, so n >= 1 likely. But the immediate crash comes from the recursive calls on NULL children.]
}