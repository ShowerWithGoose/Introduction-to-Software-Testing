#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct node {
    int num;
    int h;
    struct node *left,*right;
} node;
typedef struct node *bst;
bst insert(bst root,int num) {
    if(root==NULL) {
        root=(node*)malloc(sizeof(node));
        root->num=num;
        root->left=root->right=NULL;
    } else if(num<root->num) {
        root->left=insert(root->left,num);
    } else if(num>root->num) { // @@ [Error: This condition uses '>' instead of '>='. According to the problem, right child should be greater than or equal to the root, so equal values should go to the right subtree. Using '>' causes equal values to not be inserted, leading to missing leaf nodes like 100.]
        root->right=insert(root->right,num);
    }
    return root;
}
int i=1;
void print(bst root)
{
    if(root==NULL) {
        return 0; // @@ [Error: This function is declared as void but returns an integer 0. This is a type mismatch and will cause undefined behavior. It should be just 'return;' without a value.]
    } else {
        if(root->left==NULL&&root->right==NULL) {
            printf("%d %d\n",root->num,i);
        }
        i++;
        print(root->left);
        print(root->right);
        i--;
    }
}

int main() {
    int n;
    bst root=NULL;
    scanf("%d",&n);
    int num;
    for(int i=0; i<n; i++) {
        scanf("%d",&num);
        root=insert(root,num);
    }
    print(root);
    return 0;
}