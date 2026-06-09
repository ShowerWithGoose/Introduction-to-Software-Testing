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
    scanf("%d", &item);
    root = createBST(root, item);
    while(n--){ // @@ Error: The loop reads n+1 items total (one before loop and n inside), but only n items should be read. Also, the first item is read separately, then n-1 more items are read inside the loop, causing incorrect input handling.
        scanf("%d", &item);
        q = createBST(root, item); // @@ Error: The second and subsequent calls to createBST pass 'root' as the first argument instead of the subtree root, so the tree is not built correctly; it should be 'q = createBST(root, item);' but the function expects the root of the subtree to insert into, not the global root.
    }
    printBST(root, 1);
    
    return 0;
    
    
}