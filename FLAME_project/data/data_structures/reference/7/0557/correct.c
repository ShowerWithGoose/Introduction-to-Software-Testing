#include <stdio.h>
#include <stdlib.h>
typedef struct BiTnode{
    int data;
    struct BiTnode *Lcd, *Rcd;
    int high;
} BiTnode, *BiTree;

BiTree createTree(BiTree t, int e, int depth);
void visit(BiTree t);
void inorder(BiTree t);
int n, i = 0, num, depth = 1;

int main() {
    BiTree root = NULL;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &num);
        root = createTree(root, num, depth);
    }
    inorder(root);
    return 0;
}

BiTree createTree(BiTree t, int e, int depth){
    if (t == NULL) {
        t = (BiTree)malloc(sizeof(BiTnode));
        t->data = e;
        t->Lcd = t->Rcd = NULL;
        t->high = depth;
    }else{
        if (e < t->data) {
            t->Lcd = createTree(t->Lcd, e, depth+1);
        }else{
            t->Rcd = createTree(t->Rcd, e, depth+1);
        }
    }
    return t;
}

void visit(BiTree t){
    printf("%d %d\n", t->data, t->high);
}

void inorder(BiTree t){
    if (t == NULL) {
        return;
    }
    inorder(t->Lcd);
    if (t->Lcd == NULL && t->Rcd == NULL) {
        visit(t);
    }
    inorder(t->Rcd);
}
/*
 50 38 30 64 58 40 10 73 70 50 60 100 35
 */



