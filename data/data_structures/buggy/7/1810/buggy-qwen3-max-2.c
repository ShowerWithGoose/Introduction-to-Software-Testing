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
            depth--; @@ [The decrement of 'depth' here has no effect because 'depth' is passed by value; the updated depth in recursive calls does not affect the caller's depth. Also, leaf nodes are only printed when both children are NULL, but internal nodes should not alter depth this way. The logic for tracking height is flawed.]
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
    while(n--){ @@ [This loop runs 'n' times after already reading one item, so total items read = n+1, which is incorrect. It should read exactly 'n' items.]
        scanf("%d", &item);
        q = createBST(root, item); @@ [Return value of createBST is assigned to 'q', but 'root' is never updated for subsequent insertions. Thus, only the first element becomes root, and rest are lost or inserted into a subtree that isn't linked back to root due to pass-by-value in recursion.]
    }
    printBST(root, 1);
    
    return 0;
    
    
}