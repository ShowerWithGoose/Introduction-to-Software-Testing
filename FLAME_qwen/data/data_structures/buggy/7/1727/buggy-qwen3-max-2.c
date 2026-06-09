#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
    int data;
    struct tree *left,*right;
}tree;

tree* creat(int num){
    tree *bst=(tree*)malloc(sizeof(tree));
    bst->left=bst->right=NULL;
    bst->data=num;
    return bst;
}
void insert(tree *bst,int num){
    if(bst->data>num){
        if(bst->left==NULL)
        bst->left=creat(num);
        else{
            insert(bst->left,num);
        }
        
    }
    else{
        if(bst->right==NULL)
        bst->right=creat(num);
        else{
            insert(bst->right,num);
        }
    }
    return ;
}

void leaf(tree *bst,int h){
    if(bst->left==NULL||bst->right==NULL){ @@ [This condition incorrectly identifies nodes with only one child as leaf nodes. A leaf node must have both left and right children NULL.]
        printf("%d %d \n",bst->data,h);
        return;
    }
    else{
        if(bst->left!=NULL){
            leaf(bst->left,h+1);
        }
        if(bst->right!=NULL)
        leaf(bst->right,h+1);
        }
}
int main(){
    int n;
    scanf("%d",&n);
    tree *bst=(tree*)malloc(sizeof(tree)); @@ [This malloc is unnecessary and immediately overwritten by the next line, causing a memory leak.]
    int num;
    scanf("%d",&num);
    bst=creat(num);
    for(int i=1;i<n;i++){
        
        scanf("%d",&num);
        insert(bst,num);
    }
    int h=1;
    leaf(bst,h);
    return 0;
}