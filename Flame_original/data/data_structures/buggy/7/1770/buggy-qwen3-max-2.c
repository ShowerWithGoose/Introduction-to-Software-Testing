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
        search(p->left,num+1); // @@ [If p->left is NULL, calling search(p->left, num+1) will dereference a NULL pointer, causing a runtime crash. Similarly for p->right. The condition should check each child before recursing.]
        search(p->right,num+1); // @@ [Same issue: if p->right is NULL, this call will crash. Recursion should only happen on non-NULL children.]
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
    search(root,1); // @@ [If the input n is 0, root will be NULL, and calling search(root,1) will immediately dereference a NULL pointer in the first line of search(), causing a crash. The program must handle empty tree case.]
    return 0;
}