#include<stdio.h>
typedef struct node{
    int date; // @@ [should be 'data' to match problem semantics, but not a compilation error; however, missing stdlib.h causes malloc undefined]
    int high;
    struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE root;
BTREE insert(int item) {
        BTREE p,q;
        int i=1;
        p=(BTREE)malloc(sizeof(BTNode)); // @@ [missing #include <stdlib.h>, so malloc is undeclared -> Compilation Error]
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
                        q->lchild=p; // @@ [should assign to q->rchild, not q->lchild; logic error but not compilation]
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
     inorder(p->lchild); // @@ [missing null check before recursion; will cause segmentation fault when p is NULL, but not compilation error]
     visit(p);
     inorder(p->rchild); // @@ [same as above]
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