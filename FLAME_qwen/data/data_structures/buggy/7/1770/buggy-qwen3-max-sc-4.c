#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int num;
    struct node *left, *right;
} Node, *Nodeptr;

Nodeptr insert(Nodeptr p, int num) {
    if(p==NULL) {
        p=(Nodeptr)malloc(sizeof(Node));
        p->num=num;
        p->left=p->right=NULL;
    } else if(num<p->num) {
        p->left=insert(p->left,num);
    } else {
        p->right=insert(p->right,num);
    }
    return p;
}

void search(Nodeptr p, int num) {
    if(p->left!=NULL || p->right!=NULL) {
        search(p->left,num+1); // @@ [If p->left is NULL, calling search with NULL leads to dereferencing NULL in the next recursive call, causing undefined behavior or crash.]
        search(p->right,num+1); // @@ [If p->right is NULL, same issue as above. The condition checks if either child exists, but then unconditionally recurses on both children without checking if they are NULL.]
    } else {
        printf("%d %d\n", p->num, num);
    }
}

int main() {
    int n, i, num;
    Nodeptr root=NULL;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &num);
        root=insert(root, num);
    }
    search(root,1); // @@ [If the tree is empty (n == 0), root is NULL, and passing NULL to search will cause a segmentation fault when accessing p->left or p->right.]
    return 0;
}