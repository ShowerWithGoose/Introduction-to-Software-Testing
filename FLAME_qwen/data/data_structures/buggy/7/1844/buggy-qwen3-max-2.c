#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height is incorrect because it doesn't represent the actual depth of each node during traversal; height should be passed as a parameter.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: (BTree *) should be (BTNode *) or just (struct BTNode *); BTree is already a pointer type, so casting to BTree* makes it a double pointer.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion should handle x >= p->data for right subtree per problem description, but this only inserts when x > p->data, violating the spec.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Uses global 'high' which does not reflect the true height/depth of the current node in the tree.]
        }
        high++; // @@ [Modifying global 'high' here disrupts correct height tracking during recursive traversal.]
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ [Global variable manipulation leads to incorrect height values for leaf nodes.]
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x); // @@ [Trailing space in format string may cause input issues, though often tolerated; better to use "%d" without space.]
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}