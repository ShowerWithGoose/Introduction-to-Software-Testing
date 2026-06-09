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
            depth++; // @@ The depth increment is conditional on having children, but more importantly, the logic for leaf detection and printing is flawed relative to the traversal. However, the primary issue causing the specific test case failure (root being a leaf) is that the root's depth is passed as 1. If the root is a leaf, it goes to the else block and prints depth 1. Wait, let's re-read the buggy output. Buggy Output: 5678 2. Expected: 5678 1. 
            // Let's trace the code with input "1 5678".
            // n=1. scanf("%d", &item) reads 5678. root = createBST(NULL, 5678). Root created.
            // while(n--) -> n becomes 0. Loop condition fails? No, post-decrement. n was 1. Condition checks 1 (true), then n becomes 0.
            // Inside loop: scanf("%d", &item). This waits for another integer! 
            // The problem says: First read n, then read n integers.
            // The code reads one integer before the loop, then enters a loop that runs n times, reading an integer each time.
            // So for n=1, it reads 1 integer before loop, then tries to read another inside the loop.
            // This is a logic error in input reading. It reads n+1 integers effectively if the loop runs n times after reading one.
            // Actually, let's look at the loop: `while(n--)`. If initial n=1.
            // Iteration 1: n evaluates to 1 (true), n becomes 0. Reads item. Inserts.
            // Iteration 2: n evaluates to 0 (false). Stops.
            // So it reads 1 item before loop, and 1 item inside loop. Total 2 items.
            // But input only has 1 item "5678".
            // The first `scanf` reads 5678. Root is 5678.
            // The `while` loop executes once. It calls `scanf` again. Since there is no more input, this might hang or read garbage/EOF.
            // If it reads garbage, the tree changes.
            // However, the error type is Wrong Answer, not Runtime Error or Timeout.
            // Let's look at the `printBST` function logic again.
            // If the tree construction was correct (just 5678), root is leaf.
            // printBST(root, 1). t!=NULL. lchild==NULL, rchild==NULL.
            // Condition `if(t->lchild != NULL || t->rchild != NULL)` is False.
            // Goes to `else`. Prints `5678 1`.
            // So if the tree was just the root, the output would be correct.
            // The fact that the output is `5678 2` suggests that the node printed is at depth 2.
            // This implies the tree structure is different or the depth calculation is wrong.
            
            // Let's re-evaluate the input reading.
            // Input: "1\n5678"
            // `scanf("%d", &n)` -> n=1.
            // `scanf("%d", &item)` -> item=5678. Root created with 5678.
            // `while(n--)` -> n becomes 0. Loop body executes.
            // `scanf("%d", &item)` -> Tries to read next int. Input stream is empty.
            // In many competitive programming environments, if scanf fails, item remains unchanged or becomes undefined.
            // If item remains 5678, `createBST(root, 5678)` is called.
            // 5678 >= 5678, so it goes to right child.
            // Right child of root becomes a new node with 5678.
            // Now tree has Root(5678) -> Right(5678).
            // Root is not a leaf. Right node is a leaf.
            // printBST(root, 1).
            // Root has right child. Condition true. depth becomes 2.
            // Recurse left (NULL). Recurse right (Node 5678, depth 2).
            // At Node 5678 (right child): lchild NULL, rchild NULL.
            // Condition false. Else block. Prints `5678 2`.
            // This matches the buggy output!
            
            // So the error is in the input reading logic. It reads one extra integer or misinterprets the count.
            // The standard way is to loop n times to read n integers.
            // The code reads 1 before loop, then n times in loop. Total n+1 reads.
            // It should only read n times total.
            
            // Where to mark the error?
            // The line `scanf("%d", &item);` before the loop is suspicious if the loop is intended to read all n items.
            // Or the loop structure is wrong.
            // Usually: `for(i=0; i<n; i++) { scanf...; insert...; }`
            // Here: `scanf` before, then `while(n--)` with `scanf` inside.
            // This effectively reads n+1 items.
            
            // To fix, we should remove the pre-loop scanf or adjust the loop.
            // Given the constraint to annotate existing lines:
            // The line `scanf("%d", &item);` before the loop causes the first item to be consumed separately,
            // and then the loop tries to read n more items.
            // If we assume the intention was to read n items, the pre-loop scanf is incorrect in combination with the loop running n times.
            
            // Let's look at the lines:
            // Line 36: `scanf("%d", &item);`
            // Line 37: `root = createBST(root, item);`
            // Line 38: `while(n--){`
            // Line 39: `scanf("%d", &item);`
            // Line 40: `q = createBST(root, item);`
            
            // If n=1, we want to read 1 item.
            // Current code reads item 1 (pre-loop), inserts. Then loop runs 1 time, reads item 2 (garbage/EOF), inserts.
            // Correct code should read 1 item total.
            
            // The error is logically in the sequence of reading.
            // Marking the pre-loop scanf as erroneous because it leads to over-reading when combined with the loop.
            // Or marking the loop condition.
            
            // However, often students write:
            // scanf first item.
            // then loop n-1 times.
            // Here loop is `while(n--)`. If n=1, it runs 1 time.
            // If it was `while(--n)`, it would run 0 times for n=1. That would be correct for "read first, then read remaining n-1".
            // So changing `while(n--)` to `while(--n)` would fix the count.
            // Let's check `while(--n)`.
            // n=1. --n makes n=0. Condition 0 (false). Loop doesn't run.
            // Only pre-loop scanf executes. Reads 5678. Tree has only root.
            // Output: 5678 1. Correct.
            
            // So the error is in the loop condition `while(n--)`. It should be `while(--n)` or the loop should be `for(i=1; i<n; i++)`.
            // Given the code structure, `while(n--)` is the likely culprit for off-by-one in iteration count relative to the pre-read.
            
            // Let's annotate the loop line.
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
    while(n--){ // @@ The loop runs n times after reading one element outside, resulting in n+1 elements being read. It should run n-1 times (e.g., while(--n)) to correctly read the remaining n-1 elements.
        scanf("%d", &item);
        q = createBST(root, item);
    }
    printBST(root, 1);
    
    return 0;
    
    
}