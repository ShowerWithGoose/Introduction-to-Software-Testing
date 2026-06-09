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
            depth--; @@ [The decrement of 'depth' here has no effect because 'depth' is passed by value; the height calculation for leaf nodes becomes incorrect as internal nodes do not maintain their correct depth during traversal.]
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
    while(n--){ @@ [This loop runs 'n' times after already reading one item, resulting in reading 'n+1' items total instead of 'n'. It should run 'n-1' times or read all 'n' items in a consistent loop.]
        scanf("%d", &item);
        q = createBST(root, item); @@ [The returned root from createBST is ignored; insertion into BST may fail to update the tree correctly when inserting into an empty subtree that is not the global root. However, since 'root' is non-NULL after first insertion, this only affects subtrees. But more critically, the return value should be assigned to maintain correct structure, e.g., root = createBST(root, item) in a proper loop.]
    }
    printBST(root, 1);
    
    return 0;
    
    
}