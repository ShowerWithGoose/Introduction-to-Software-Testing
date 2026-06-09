#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height is incorrect because it doesn't reflect the actual depth of each node during traversal; height should be passed as a parameter.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: (BTree *) should be (BTNode *) or simply omitted; BTree is already a pointer type (BTNode*), so casting to BTree* makes it BTNode**, which is wrong.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [Does not handle the case where x == p->data; according to problem, right child should include values >= root, but this skips equal values, causing them to be ignored.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Uses global 'high' which does not represent the correct height of the current leaf node due to flawed traversal logic.]
        }
        high++; // @@ [Incrementing global 'high' before recursing left messes up height tracking for right subtree and other branches.]
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ [Global variable modification during recursion leads to incorrect height values for leaf nodes.]
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