#include<stdio.h> // @@ Missing #include<stdlib.h> for malloc() function, causing implicit declaration.
typedef struct node{
    int date;
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE root;
BTREE insert(int item) { // @@ Return type should be void; no return statement leads to undefined behavior.
        BTREE p,q;
        int i=1;
        p=(BTREE)malloc(sizeof(BTNode)); // @@ malloc() not declared due to missing stdlib.h, compilation error.
        p->date=item;
        p->lchild=NULL;
        p->rchild=NULL;
        if (root==NULL) {
            root=p;
            root->high=i;
        } else {
            q=root;
            while(1) {
                i++;
                if(item<q->date) {
                    if(q->lchild==NULL) {
                        q->lchild=p;
                        p->high=i;
                        break;
                    } else {
                        q=q->lchild;
                    }
                } else if (item>q->date) {
                    if(q->rchild==NULL) {
                        q->lchild=p; // @@ Should assign to q->rchild instead of q->lchild (logical error).
                        p->high=i;
                        break;
                    } else {
                       q=q->rchild;
                    }
                } // @@ Missing case for item == q->date; leads to infinite loop when duplicate values appear.
            }
        }
}
void visit(BTREE p) {
     if(p->lchild==NULL&&p->rchild==NULL) { // @@ No check if p is NULL; will crash when called on NULL.
        printf("%d %d\n",p->date,p->high);
     }
}
void inorder(BTREE p) { // @@ Missing base case (if(p==NULL) return); causes infinite recursion and segmentation fault.
     inorder(p->lchild); // @@ Recursive call without NULL check, will crash when p becomes NULL.
     visit(p);
     inorder(p->rchild); // @@ Same issue.
}
int main() {
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&t);
        insert(t);
    }
    inorder(root);
    return 0;
}