#include <stdio.h>
#include <stdlib.h>
#define Datatype int
struct node{
    Datatype data;
    struct node *lchild, *rchild;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

BTNodeptr createBST(BTNodeptr t, Datatype item){
    if(t == NULL){
        t = (BTNodeptr)malloc(sizeof(BTNode));
        t->data = item;
        t->lchild = NULL;
        t->rchild = NULL;
    }
    else if(item < t->data)
        t->lchild = createBST(t->lchild, item);
    else
        t->rchild = createBST(t->rchild, item);
        
    return t;
}
void printBST(BTNodeptr t, int depth){
    if(t != NULL){
        if(t->lchild != NULL || t->rchild != NULL){
            depth++;
            printBST(t->lchild, depth);
            printBST(t->rchild, depth);
            depth--;
        }
        
        else{
            printf("%d %d\n", t->data, depth);
        }
    }
}
int main()
{
    int n, item;
    scanf("%d", &n);
    BTNodeptr root = NULL,q;
    scanf("%d", &item); // @@ Reads an extra integer before the loop, causing the program to process n+1 items instead of n
    root = createBST(root, item); // @@ Handles the extra read; should be removed or integrated into the loop
    while(n--){ // @@ Loop runs n times, but combined with the previous read, it processes n+1 items total
        scanf("%d", &item);
        q = createBST(root, item); // @@ Should update root pointer (root = createBST(...)) for correctness, though the primary issue is the off-by-one read count
    }
    printBST(root, 1);
    
    return 0;
    
    
}