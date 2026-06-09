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
        search(p->left,num+1); // @@ [Passing NULL pointer to recursive call when p->left is NULL, leading to dereference of NULL in next call]
        search(p->right,num+1); // @@ [Passing NULL pointer to recursive call when p->right is NULL, leading to dereference of NULL in next call]
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
    search(root,1); // @@ [If root is NULL (n=0), this passes NULL to search, which immediately dereferences it]
    return 0;
}