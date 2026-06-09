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
            depth--; // @@ [This decrement has no effect because 'depth' is passed by value; the recursive calls use incremented depth, but the logic for leaf detection and height tracking is flawed. The height should be passed down unchanged to children, not conditionally incremented only for non-leaves.]
        }
        
        else{
            printf("%d %d\n", t->data, depth); // @@ [For a single-node tree, this prints depth=1 correctly, but due to the flawed increment logic above, in some cases depth may be incorrect. However, the main bug causing WA on single-node input is actually in main(), not here.]
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
    while(n--){ // @@ [This loop runs 'n' times after already reading one item, resulting in reading n+1 items total. For input "1\n5678", it reads 5678 first, then tries to read another integer (but there isn't one), leading to undefined behavior. Also, the inserted node from the second read is not assigned to root, so the tree may be incomplete or corrupted.]
        scanf("%d", &item);
        q = createBST(root, item); // @@ [The return value of createBST is assigned to 'q', not to 'root' or the appropriate child pointer. This means all insertions after the first are lost because the tree structure is not updated properly.]
    }
    printBST(root, 1);
    
    return 0;
    
    
}