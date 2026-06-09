#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: BTree is already a pointer type (BTNode*), so casting malloc to (BTree *) results in a double pointer type (BTNode**), causing a type mismatch. Should be (BTree) or no cast in C.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion logic error: problem requires right child for values >= root, but this only inserts right when x > root->data, ignoring equal values. Equal values should go to the right subtree per problem description.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Incorrect height tracking: 'high' is a global variable modified during traversal, which does not correctly represent the current node's depth. Height should be passed as a parameter like in the reference program.]
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
        scanf("%d ",&x); // @@ [Input format issue: trailing space in format string may cause unexpected behavior, though often tolerated. More critically, missing #include <stdlib.h> for malloc causes compilation error.]
    }
    postorder(root);


    return 0;
}