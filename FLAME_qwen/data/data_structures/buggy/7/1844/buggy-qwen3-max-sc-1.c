#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height is incorrect because it doesn't represent the actual depth of each node during traversal; height should be passed as a parameter.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: (BTree *) should be (BTNode *) or just (struct BTNode *); BTree is already a pointer type, so casting to BTree* results in double pointer.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [BST insertion should handle duplicates by inserting them to the right (>=), but this code only inserts strictly greater values to the right, violating the problem's requirement that right child is >= root.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Uses global 'high' which does not reflect the actual height of the current leaf node due to flawed increment/decrement logic and shared state across recursive calls.]
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
        scanf("%d ",&x); // @@ [Trailing space in format string may cause input issues, especially at the end of input; better to use "%d" without space.]
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}