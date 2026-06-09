//树叶节点遍历（树-基础题）

#include <stdio.h>
#include <stdlib.h>

typedef struct  node 
{
    int data;
    int high;
    struct node *left,*right;
}tree;
tree *first;
  
tree *start(tree *root,int temp,int len){
    if(root==NULL){
        root=(tree *)malloc(sizeof(tree));
        root->data=temp;
        root->left=root->right=NULL;
        len++;
        root->high=len;
    }
    else if(temp>=root->data){
        len++;
         root->right = start(root->right, temp, len);
    }        
    else if(temp<root->data){
        len++;
         root->left = start(root->left, temp, len);
    }

    return root;
}
 void prt(tree *root){
    if(root){
        if(root->left==NULL&&root->right==NULL){
            printf("%d %d\n", root->data, root->high);
        }
    prt(root->left);
    prt(root->right);        
    }

}

int main (){
  tree *root=NULL;
    int n,temp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        int len=0;
        root=start(root,temp,len);
    }

  prt(root);

system("pause");
return 0;
}

