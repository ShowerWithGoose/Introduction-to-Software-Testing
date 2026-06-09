#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: BTree is already a pointer type (BTNode*), so casting malloc to (BTree *) results in a double pointer (BTNode**). Should be (BTree) or no cast. Also, missing #include <stdlib.h> for malloc, causing compilation error.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion logic error: problem requires right child for values >= root, but this only inserts right when x > root->data, ignoring equality. This causes equal values to be ignored (not inserted), violating BST construction rule. However, since the error type is Compilation Error, this semantic issue is secondary to the missing header and incorrect cast.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Incorrect height tracking: 'high' is a global variable modified during traversal, which does not correctly represent the current node's depth. Height should be passed as a parameter like in the reference program. But again, primary issue is compilation.]
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
        scanf("%d ",&x); // @@ [Trailing space in format string may cause input issues, but not a compilation error. Main compilation errors are missing stdlib.h and incorrect malloc cast.]
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}