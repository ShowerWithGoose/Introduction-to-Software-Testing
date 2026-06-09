#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height is incorrect because it doesn't represent the actual depth of each node during traversal; height should be passed as a parameter.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: 'BTree' is already a pointer type (BTNode*), so casting malloc to 'BTree*' results in BTNode**, which is wrong. Should be (BTree) or (BTNode*).]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion should handle 'x >= p->data' for right subtree per problem description, but this only inserts when 'x > p->data', causing equal values to be ignored.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Printing global 'high' instead of the actual height of the current leaf node. The height should be tracked via recursion parameter, not a global variable.]
        }
        high++; // @@ [Incrementing global 'high' before recursing left breaks height tracking; also, this approach cannot correctly manage depth across different branches.]
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ [Decrementing global 'high' after recursion is error-prone and does not correctly reflect node height in a tree with multiple branches.]
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ [The space after '%d' in scanf can cause issues by consuming extra whitespace unnecessarily; though often harmless, it's not needed and may lead to unexpected behavior in some cases.]
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}