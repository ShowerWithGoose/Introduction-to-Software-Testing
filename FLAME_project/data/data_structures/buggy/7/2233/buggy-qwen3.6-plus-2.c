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
    else if(p->num < n){ // @@ The problem states that right child values are greater than or equal to the root. This condition strictly checks for 'less than', meaning equal values are not handled by this branch nor the previous one, effectively ignoring duplicate insertions or causing logic errors if duplicates exist. It should be 'else' to handle >= cases as right children.
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