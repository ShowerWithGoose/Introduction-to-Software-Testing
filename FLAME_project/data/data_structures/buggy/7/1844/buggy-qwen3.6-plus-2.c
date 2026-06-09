#include<stdio.h>
typedef struct BTNode{
    int data;
    
    struct BTNode *lchild,*rchild;
}BTNode,*BTree;
int high=1;
BTree insert(BTree p,int x){
    if(p==NULL){
        p=(BTree *)malloc(sizeof(BTNode)); // @@ [Type casting error: (BTree *) is a pointer to a pointer, should be (BTree) or (BTNode *)]
        p->data=x;
        
        
        p->lchild=p->rchild=NULL;        
    }
    else if(x<p->data){
        
        p->lchild=insert(p->lchild,x);
    }
    else if(x>p->data){ // @@ [Logical error: The problem states right child is >= root. This condition skips equal values, causing them to be lost instead of inserted into the right subtree.]
        
        p->rchild=insert(p->rchild,x);
    }
    return p;
}

void postorder(BTree t){ // @@ [Logical error: The function name and structure suggest post-order, but leaf output order in BST requires in-order traversal (Left-Root-Right) to get left-to-right order. Post-order visits children before parent, but more importantly, the global 'high' variable management is flawed for calculating height relative to root if not handled as depth from root. However, the primary issue for "Wrong Answer" on missing nodes is the insertion logic above. The traversal order here is actually Pre-order logic (Process, Left, Right) despite the name, because it prints before recursing. Wait, looking closely: it prints if leaf, then increments high, then goes left, then right, then decrements. This is a Pre-order traversal with depth tracking. The name is misleading but the logic for traversal order (Left to Right leaves) is correct for Pre-order/In-order regarding leaf sequence in BST? No, In-order is standard for sorted output. Pre-order visits root first. For leaves, In-order and Pre-order might differ in sequence? No, leaves are visited in increasing order in In-order. In Pre-order, a leaf in the left subtree is visited before a leaf in the right subtree. So Pre-order also yields left-to-right spatial order. The main error remains the insertion.]
    if(t!=NULL){
        if(t->lchild==NULL&&t->rchild==NULL){
            printf("%d %d\n",t->data,high);
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