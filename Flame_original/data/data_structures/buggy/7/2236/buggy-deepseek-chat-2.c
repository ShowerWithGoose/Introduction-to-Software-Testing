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
    } if (tem < root->data) { // @@ Missing else before if; when root is not NULL, this if is always executed, but if root was just created (NULL case), root->data is set, but then this if checks tem < root->data, which may cause incorrect insertion logic. Should be "else if (tem < root->data)".
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
    } if (p->left != NULL) { // @@ Missing else; this if is separate from the previous if, so after printing a leaf and returning, the function does not continue, but if p is not a leaf, both left and right checks are correct. However, the structure is fine functionally, but the missing else is not an error here because of the return. The real issue is in insert function.
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