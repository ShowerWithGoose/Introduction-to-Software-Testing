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
    } else if(num>root->num) { // @@ The problem requires that values greater than or equal to the root go to the right, but this condition excludes equal values, causing them to be ignored.
        root->right=insert(root->right,num);
    }
    return root;
}
int i=1;
void print(bst root)
{
    if(root==NULL) {
        return 0; // @@ Return type is void, but this line returns an integer 0, causing a compilation error.
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