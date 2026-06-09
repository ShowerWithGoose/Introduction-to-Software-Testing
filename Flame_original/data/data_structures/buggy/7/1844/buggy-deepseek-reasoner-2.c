#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ type mismatch: BTree is already a pointer, cast should be (BTree) not (BTree*); also missing #include<stdlib.h> for malloc
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ missing case for x == p->data: should go to right child per problem (right child >= root)
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high);
        }
        high++; // @@ height increment before recursion is incorrect; should pass level as parameter instead of using global variable
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ corresponding decrement, but still leads to incorrect heights
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ space in format may cause issues but not critical
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}