#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height is incorrect because it doesn't represent the actual depth of each node during traversal; height should be passed as a parameter like in the reference program]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: (BTree *) should be (BTNode *); BTree is already a pointer type (i.e., BTNode*), so casting to BTree* results in BTNode** which is wrong]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion should allow duplicates on the right (>=), but this uses only >, so equal values are ignored and not inserted]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Uses global 'high' which does not reflect the true height/level of the current node; height must be tracked per call stack, not globally]
        }
        high++; // @@ [Incrementing global 'high' before recursing distorts the level tracking; also, this approach fails for complex tree structures due to shared state]
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ [Decrementing global 'high' after recursion assumes symmetric traversal, but global state causes incorrect height values for different branches]
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ [Trailing space in format string may cause input issues, though often tolerated; better to use "%d" without trailing space]
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}