#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1; // @@ [Using a global variable 'high' to track height during traversal is incorrect because it doesn't represent the actual depth of the current node in the recursive call stack.]
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Incorrect cast: should be (BTree) not (BTree *), since BTree is already a pointer type (typedef ... *BTree). This may cause compilation warnings or undefined behavior.]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [Fails to handle equal values as per problem: "right child is greater than or equal". Equal values are ignored, so duplicate 100 is not inserted, causing missing leaf node.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high); // @@ [Uses global 'high' which does not correctly reflect the height of the current leaf node due to flawed increment/decrement logic and shared state across recursion branches.]
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
        scanf("%d ",&x);
        root=insert(root,x);
    }
    postorder(root);


    return 0;
}