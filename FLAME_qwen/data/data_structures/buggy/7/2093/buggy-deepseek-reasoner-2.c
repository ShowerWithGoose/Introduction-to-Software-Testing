#include<stdio.h>
typedef struct node{
    int date;
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE root;
BTREE insert(int item) { // @@ [function declared to return BTREE but no return statement, may cause warning/compilation error]
        BTREE p,q;
        int i=1;
        p=(BTREE)malloc(sizeof(BTNode)); // @@ [missing #include <stdlib.h> for malloc, causes compilation error]
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
                } else if (item>q->date) { // @@ [no handling for item == q->date, causes infinite loop on duplicate values]
                    if(q->rchild==NULL) {
                        q->lchild=p; // @@ [should assign to q->rchild instead of q->lchild to maintain BST property]
                        p->high=i;
                        break;
                    } else {
                       q=q->rchild;
                    }
                }
            }
        }
}
void visit(BTREE p) {
     if(p->lchild==NULL&&p->rchild==NULL) {
        printf("%d %d\n",p->date,p->high);
     }
}
void inorder(BTREE p) {
     inorder(p->lchild); // @@ [no base case; dereferences NULL pointer when p is NULL, causes runtime error]
     visit(p);
     inorder(p->rchild); // @@ [no base case; dereferences NULL pointer when p is NULL, causes runtime error]
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