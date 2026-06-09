#include<stdio.h>
typedef struct node{
    int date;
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE root;
BTREE insert(int item) {
        BTREE p,q;
        int i=1;
        p=(BTREE)malloc(sizeof(BTNode)); // @@ Missing #include <stdlib.h> for malloc
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
                        q->lchild=p; // @@ Should be q->rchild=p; incorrectly assigns to left child
                        p->high=i;
                        break;
                    } else {
                       q=q->rchild;
                    }
                }
            }
        }
} // @@ Missing return statement; function declared to return BTREE but returns nothing
void visit(BTREE p) {
     if(p->lchild==NULL&&p->rchild==NULL) {
        printf("%d %d\n",p->date,p->high);
     }
}
void inorder(BTREE p) {
     inorder(p->lchild); // @@ No base case; will cause infinite recursion when p is NULL
     visit(p);
     inorder(p->rchild); // @@ No base case; will cause infinite recursion when p is NULL
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