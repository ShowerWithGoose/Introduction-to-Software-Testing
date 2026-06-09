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
        search(p->left,num+1); // @@ [If p->left is NULL, calling search(p->left, num+1) will pass NULL to the next recursive call, which then tries to access p->left or p->right on a NULL pointer, causing a segmentation fault. The condition should check for non-NULL before recursing.]
        search(p->right,num+1); // @@ [Same issue: if p->right is NULL, this call passes NULL into search, leading to dereferencing a NULL pointer in the next call.]
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
    search(root,1); // @@ [If the input n is 0, root remains NULL, and calling search(root,1) will pass NULL to search, which immediately tries to access p->left and p->right, causing a segmentation fault. The program should handle empty tree case.]
    return 0;
}