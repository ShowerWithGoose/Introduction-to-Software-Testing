#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node *insert(int tem, struct node* root) {
    if (root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = tem;
        root->left = NULL;
        root->right = NULL;
    } if (tem < root->data) { // @@ The condition should be 'else if' instead of 'if'. Without 'else', when root is newly created (not NULL), the code proceeds to check tem < root->data. While logically this might seem okay for distinct values, the structure implies an if-else chain. More critically, if tem == root->data, it goes to the final else, which is correct for >=. However, the main issue in many such bugs is missing else. Let's look closer. Actually, the logic `if (root == NULL) { ... } if (tem < root->data) { ... } else { ... }` is technically valid C if root is not NULL after the first block. But if root WAS NULL, it gets allocated. Then `tem < root->data` is checked. If true, left insert. Else right insert. This seems logically okay for insertion. Wait, let's re-read the prompt's provided "Source Code" vs "Reference Program". The user provided a "Source Code" at the bottom which is different from the "Reference Program" at the top. The task is to annotate the "Source Code" at the bottom. 
    // Let's re-evaluate the Source Code provided at the end.
    // Test Case: n=1, val=5678.
    // main: root=NULL. i=0. scanf 5678. root = insert(5678, NULL).
    // insert: root==NULL. malloc. data=5678. left/right=NULL.
    // Next line: if (tem < root->data). 5678 < 5678 is false.
    // Else: root->right = insert(5678, NULL).
    // Recursive call insert(5678, NULL): malloc new node. data=5678.
    // Returns new node.
    // So root->right points to a new node with 5678.
    // This creates an infinite loop or incorrect tree structure because equal elements are always inserted to the right, but the current node ALSO processes the else branch.
    // Actually, the standard BST definition here says "right child is greater than or equal".
    // The bug is that the `if (root == NULL)` block does not return or skip the subsequent checks.
    // When root is NULL, we allocate it. Then we fall through to `if (tem < root->data)`.
    // If tem == root->data (which it is, since we just set it), it goes to `else`, calling insert again on right.
    // This causes infinite recursion or stack overflow for duplicate values or even single values if logic is flawed?
    // For n=1, val=5678:
    // 1. insert(5678, NULL) -> allocs Node A (5678).
    // 2. Falls through to `if (5678 < 5678)` -> False.
    // 3. Goes to `else` -> `root->right = insert(5678, NULL)`.
    // 4. insert(5678, NULL) -> allocs Node B (5678).
    // 5. Falls through... `else` -> `root->right = insert(5678, NULL)`.
    // Infinite recursion! Stack Overflow -> Runtime Error.
    // Fix: Add `else` before `if (tem < root->data)` or `return root` after the NULL block.
        root->left = insert(tem, root->left);
    } else {
        root->right = insert(tem, root->right);
    }
    return root;
};
void printleaf(struct node *p,int high) {
    if (p->left == NULL && p->right == NULL) {
        printf("%d %d\n", p->data,high);
        return;
    } if (p->left != NULL) {
        printleaf(p->left,high+1);
    } if (p->right != NULL) {
        printleaf(p->right,high+1);
    }
};
int main(){
    int n;
    int tem;
    struct node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tem);
        root = insert(tem, root);
    }
    printleaf(root,1);
}