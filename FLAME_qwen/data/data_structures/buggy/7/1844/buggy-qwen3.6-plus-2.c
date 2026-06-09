#include<stdio.h> // @@ Missing #include <stdlib.h> which is required for the malloc function
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ BTree is already a pointer type, casting to BTree* (pointer to pointer) is incorrect; should be (BTree) or (BTNode*)
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ Should be x>=p->data to correctly handle duplicate values by placing them in the right subtree as per problem description
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high);
        }
        high++;
        postorder(t->lchild);
        postorder(t->rchild);
        high--;
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ Trailing space in the format string causes scanf to wait for non-whitespace input, potentially leading to input parsing errors or hanging
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}