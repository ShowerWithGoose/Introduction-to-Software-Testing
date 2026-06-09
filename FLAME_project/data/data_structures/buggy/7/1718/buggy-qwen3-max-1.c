#include <stdio.h>
#include <stdlib.h>
struct tree{
    int num;
    struct tree *lchild;
    struct tree *rchild;
    int level;
};
typedef struct tree *Tree;
void pout(Tree t){
    if(t->lchild!=NULL||t->rchild!=NULL){
        pout(t->lchild);
        pout(t->rchild);
    }else{
        printf("%d %d\n",t->num,t->level);
    }
}
int main()
{
    Tree t=(Tree)malloc(sizeof(struct tree));
    t->level=1;
    t->lchild=NULL;
    t->rchild=NULL;
    int n=0;
    scanf("%d",&n);
    int tmp;
    scanf("%d",&t->num); // @@ [If n is 0, this reads an extra value; but more critically, if n==0, the program still allocates and uses t, leading to undefined behavior. However, the test case has n=10, so this isn't the main issue. The real problem is that when n==0, the code breaks, but the given test case has n=10. The actual critical error is below.]
    for(int i=0;i<n-1;i++){
        scanf("%d",&tmp);
        Tree p=t;
        Tree q=t;
        int le=1;
        while(p!=NULL){
            if(tmp>=p->num){
                q=p;
                p=p->rchild;
                le++;
            }else{
                q=p;
                p=p->lchild;
                le++;
            }
        }
        if(tmp>=q->num){
            q->rchild=(Tree)malloc(sizeof(struct tree));
            q->rchild->num=tmp;
            q->rchild->lchild=NULL;
            q->rchild->rchild=NULL;
            q->rchild->level=le;
        }else{
            q->lchild=(Tree)malloc(sizeof(struct tree));
            q->lchild->num=tmp;
            q->lchild->lchild=NULL;
            q->lchild->rchild=NULL;
            q->lchild->level=le;
        }
    }
    pout(t); // @@ [The traversal function pout does not handle NULL input. If the tree is empty (n=0), t would be uninitialized in logic, but in this code t is always allocated. However, more importantly, the traversal order is not left-to-right in-order; it's a custom traversal that goes left then right only if the node is non-leaf, but it doesn't guarantee left-to-right leaf order as required. Actually, the traversal is correct for left-to-right leaves because it recurses left first then right. The real issue is that when n=0, the initial node is still created, but the test case has n=10. The actual bug is that the height (level) calculation is off by one because le starts at 1 and increments before assigning, but the root is level 1, and its children should be level 2. However, in the loop, when inserting the first child, le becomes 2, which is correct. But wait: in the while loop, le is incremented for each step down, starting from 1. For root, level=1. When going to a child, le becomes 2, which is correct. So why the output is wrong? Let's check the test case.

    // The expected output has leaf heights: 6,6,5,4,3.
    // The buggy program outputs nothing (runtime error). Why?

    // Critical error: if n == 0, the program reads t->num anyway -> crash. But test case n=10.

    // Another possibility: if n==1, the for loop runs 0 times, and pout is called on a leaf -> correct.

    // But in the given test case, n=10, so the for loop runs 9 times.

    // However, there's a more subtle issue: the variable 'le' is initialized to 1, and then inside the while loop, every time we move to a child, we increment le. But when p becomes NULL, we have taken one step too far. For example, starting at root (level 1), if we go to left child, then p = root->lchild, and le becomes 2. Then if that child is NULL, we break, and assign the new node at level le=2, which is correct.

    // So level assignment seems correct.

    // Then why runtime error? Because when n=0, the program still does scanf("%d",&t->num) -> reads from input even if no numbers are supposed to be there. But the test case has n=10, so that's not it.

    // Wait: what if n=0? The problem says "read n integers", so if n=0, there are no integers. But the code reads one integer unconditionally after reading n. So if n=0, it tries to read an integer that doesn't exist -> runtime error (e.g., segmentation fault or invalid read). However, the test case input has n=10, so that shouldn't be the issue for this specific test.

    // But the problem says the program failed on the given test case (n=10). So why runtime error on n=10?

    // Look at pout(): it assumes t is not NULL. But what if during insertion, something goes wrong? Unlikely.

    // Another possibility: the pout function does not check if t is NULL before accessing t->lchild etc. So if the tree had a NULL node passed to pout, it would crash. But in main, t is always allocated, and all inserted nodes are allocated. So pout is only called on non-NULL t.

    // However, in pout, when recursing, it calls pout(t->lchild) even if t->lchild is NULL. Then inside pout, it accesses t->lchild (which is NULL) -> dereferencing NULL pointer -> runtime error.

    // YES! That's the bug.

    // In pout(Tree t), the first line is:
    //   if(t->lchild!=NULL||t->rchild!=NULL)
    // But if t is NULL, then t->lchild is invalid.

    // However, in the current code, is t ever NULL when pout is called?
    // In main, t is allocated, so first call is safe.
    // But when recursing: pout(t->lchild) is called even if t->lchild is NULL.
    // Then in the recursive call, t is NULL, and the first thing is t->lchild -> crash.

    // Therefore, pout must check if t is NULL at the beginning.

    // The reference program's perorder function does: if(t!=NULL){ ... }

    // So the error is in pout: missing NULL check at start.
}
    return 0;
}