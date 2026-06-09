#include<stdio.h> // @@ Missing #include <stdlib.h> for malloc function
typedef struct node{
    int date;
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE root;
BTREE insert(int item) {
        BTREE p,q;
        int i=1;
        p=(BTREE)malloc(sizeof(BTNode)); // @@ malloc requires stdlib.h which is not included
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
                        q->lchild=p; // @@ Logical error: should be q->rchild=p when item > q->date
                        p->high=i;
                        break;
                    } else {
                       q=q->rchild;
                    }
                }
            }
        }
} // @@ Missing return statement for function insert which returns BTREE
void visit(BTREE p) {
     if(p->lchild==NULL&&p->rchild==NULL) {
        printf("%d %d\n",p->date,p->high);
     }
}
void inorder(BTREE p) {
     inorder(p->lchild); // @@ Missing base case check if(p==NULL) return; at the beginning of inorder function
     visit(p);
     inorder(p->rchild);
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