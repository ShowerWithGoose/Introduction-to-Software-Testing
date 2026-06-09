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
    if(p==NULL) return; // @@ The function does not check if p is NULL before accessing its members. If a node has only one child (e.g., only left), the recursive call search(p->right, num+1) will pass NULL. Inside the next call, accessing p->left or p->right on a NULL pointer causes a Runtime Error (Segmentation Fault).
    if(p->left!=NULL || p->right!=NULL) {
        search(p->left,num+1);
        search(p->right,num+1);
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
    search(root,1);
    return 0;
}