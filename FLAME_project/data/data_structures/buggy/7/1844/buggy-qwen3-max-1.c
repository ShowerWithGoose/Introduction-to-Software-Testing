#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height during traversal is incorrect because it doesn't represent the actual depth of each node; it gets modified during recursive calls and doesn't reset per path.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: should be (BTree)malloc(...), not (BTree *). This may cause undefined behavior or compilation issues on some systems.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [Fails to insert duplicate values (like the second 100 in input). According to problem, right child should include values >= root, but this skips equal values entirely.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Printing global 'high' which does not correctly reflect the current node's height due to flawed tracking mechanism.]
        }
        high++; // @@ [Incrementing global 'high' before recursing assumes all paths share same depth counter, which corrupts height calculation for different branches.]
        postorder(t->lchild);
        postorder(t->rchild);
        high--; // @@ [Decrementing global 'high' after recursion still doesn't fix the fundamental flaw of using a single global variable for depth across multiple recursive paths.]
    }
}

int main(){
    int n,x;
    BTree root=NULL;       
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d ",&x);
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}