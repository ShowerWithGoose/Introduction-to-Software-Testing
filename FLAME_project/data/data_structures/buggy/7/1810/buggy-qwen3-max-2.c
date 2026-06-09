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
            depth--; // @@ [This decrement has no effect because 'depth' is passed by value; the height calculation logic is flawed. The root's height should be 1, but internal nodes incorrectly increment depth before recursing, causing leaf heights to be off by one.]
        }
        
        else{
            printf("%d %d\n", t->data, depth); // @@ [Due to incorrect depth handling above, leaf nodes report wrong height. For a single-node tree, this prints height 2 instead of 1.]
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
    while(n--){ // @@ [This loop runs 'n' times after already reading the first item, resulting in reading n+1 items total. It should run n-1 times or read all n items in a single loop.]
        scanf("%d", &item);
        q = createBST(root, item); // @@ [Return value of createBST is assigned to 'q' but never used; the tree rooted at 'root' is modified via recursion, but this assignment is redundant and misleading. However, the real issue is the extra input read due to loop count mismatch.]
    }
    printBST(root, 1);
    
    return 0;
    
    
}