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
            depth--; // @@ [This decrement has no effect because 'depth' is passed by value; the height tracking logic is flawed. The height of leaf nodes is not correctly computed since recursive calls don't propagate updated depth back.]
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
    scanf("%d", &item);
    root = createBST(root, item);
    while(n--){ // @@ [The loop runs 'n' times after already reading one item, resulting in reading n+1 items total instead of n. This causes incorrect input consumption and potential undefined behavior.]
        scanf("%d", &item);
        q = createBST(root, item); // @@ [The return value of createBST is assigned to 'q', but 'root' is never updated for subsequent insertions. Thus, only the first element is inserted into the tree; all others are lost because 'root' remains unchanged.]
    }
    printBST(root, 1);
    
    return 0;
    
    
}