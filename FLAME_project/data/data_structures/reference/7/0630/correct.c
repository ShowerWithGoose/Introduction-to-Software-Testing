#include<stdio.h>
#include<stdlib.h>

typedef struct main {
    int num;
    struct main *right, *left;
    int high;
}tree;

tree *first, *p, *q;

void inorder(tree *t);
void VISIT(tree *t);

int main() {
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        q = malloc(sizeof(tree));
        scanf("%d", &q->num);
        q->left = NULL;
        q->right = NULL;
        q->high = 1;
        if(first == NULL) {
            first = p = q;
        } else {
            p = first;
            while(1) {
                if(q->num >= p->num) {
                    if(p->right == NULL) {
                        p->right = q;
                        q->high = p->high + 1;
                        break;
                    }
                    p = p->right;
                } else {
                    if(p->left == NULL) {
                        p->left = q;
                        q->high = p->high + 1;
                        break;
                    }
                    p = p->left;
                }
            }
        }
    }
    inorder(first);
    return 0;
}

void inorder(tree *t) {
    if(t != NULL) {
        inorder(t->left);
        VISIT(t);
        inorder(t->right);
    }
    return;
}

void VISIT(tree *t) {
    if(t->right == NULL && t->left == NULL) {
        printf("%d %d\n", t->num, t->high);
    }
    return;
}
