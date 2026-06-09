#include<stdio.h> // @@ missing #include <stdlib.h> for malloc
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ wrong cast; should be (BTree)malloc(...)
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ should be >= to match problem 'right child >= root'
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high);
        }
        high++; // @@ logical error: global high does not properly track depth; should pass level parameter
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ logical error: corresponding decrement
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ trailing space in scanf may cause input issues
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}