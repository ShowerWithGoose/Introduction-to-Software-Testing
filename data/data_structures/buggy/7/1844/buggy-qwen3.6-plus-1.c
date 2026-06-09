#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ Type mismatch: BTree is already a pointer type (BTNode*), so BTree* is a pointer to pointer. Should be (BTree)malloc(...). Also missing #include <stdlib.h> for malloc.
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ Logical error: The problem specifies right child >= root. This condition misses the equality case (x == p->data), preventing duplicate values from being inserted. Should be x >= p->data.
        
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
        scanf("%d ",&x); // @@ Trailing space in format string causes scanf to wait for additional non-whitespace input, which may lead to runtime errors or TLE. Should be "%d".
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}