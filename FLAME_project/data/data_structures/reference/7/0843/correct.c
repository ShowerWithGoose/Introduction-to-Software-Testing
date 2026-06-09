#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst *left,*right;
    int height;//题目要求输出深度，构造二叉查找树无需记录深度；
};
struct bst *root;
struct bst *insertBst(struct bst *p,int item,int l){//一般二叉查找树无需输入l
    if(p==NULL){
    	p=(struct bst *)malloc(sizeof(struct bst));
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        p->height=l;
    }else if(item<p->data){
        p->left=insertBst(p->left,item,l+1);
    }else if(item>p->data){
        p->right=insertBst(p->right,item,l+1);
    }else if(item==p->data){
        p->right=insertBst(p->right,item,l+1);
    }
    return p;
}
void print(struct bst *p){
    if(p!=NULL){
        if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->data,p->height);
        print(p->left);
        print(p->right);
    }
}
int main(){
    int n,i,item;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&item);
        root=insertBst(root,item,1);
    }
    print(root);
    return 0;
}
