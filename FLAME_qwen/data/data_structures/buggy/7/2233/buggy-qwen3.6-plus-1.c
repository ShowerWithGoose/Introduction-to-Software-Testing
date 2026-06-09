#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a)>(b)? a : b)
struct trees{
    int num;
    int du;
    struct trees *left,*right;
}*tree;
int x=1;
struct trees* inp(struct trees* p,int n){
    if (p==NULL) {
        p=(struct trees* )malloc(sizeof(struct trees));
        p->num=n;
        p->left=p->right=NULL;
    }
    else if(p->num > n){
        p->left=inp(p->left,n);
    }
    else if(p->num < n){ // @@ The condition misses the case when p->num == n. According to the problem, right child >= root, so equal values should be inserted into the right subtree. Change to `else` or `else if(p->num <= n)`.
        p->right=inp(p->right,n);
    }
    return p;
}
void out(struct trees* p,int n){
    if (p==NULL) {
        return;
    }
    if ((p->left)==NULL&&(p->right)==NULL) {
        printf("%d %d\n",p->num,n);
        return;
    }
    else{
            out(p->left,n+1);
            out(p->right,n+1);
        }
}
int main() {

    int n,num;
    tree=NULL;
    scanf("%d",&num);
    for (int i = 0; i <num ; i++) {
        scanf("%d",&n);
        tree=inp(tree,n);
    }
    out(tree,1);
    return 0;
}