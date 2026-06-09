#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree *left,*right;
};
struct tree *head;
void insert(int m,struct tree *x){
    struct tree *q;
    q=(struct tree *)malloc(sizeof(struct tree));
    q->data=m;
    q->left=q->right=NULL;
    if(m<x->data){
        if(x->left==NULL)
        x->left=q;
        else
        insert(m,x->left);
    }
    else{
        if(x->right==NULL)
        x->right=q;
        else
        insert(m,x->right);
    }
}
void pr(struct tree *x,int h){
    if(x->left==NULL&&x->right==NULL)
    printf("%d %d\n",x->data,h);
    else if(x==NULL) return 0; // @@ [The condition `x == NULL` is checked after dereferencing `x->left` and `x->right`, which causes undefined behavior when `x` is NULL. This leads to a runtime error (likely segmentation fault), not a compilation error, but the test environment reported a compilation error possibly due to missing return type handling. Also, `return 0` is invalid in a void function.]
    else{
        pr(x->left,h+1);
        pr(x->right,h+1);
    }
}
int main()
{
    int n,m;    
    scanf("%d",&n);
    scanf("%d",&m);
    n--;
    head=(struct tree *)malloc(sizeof(struct tree));
    head->data=m;
    head->left=head->right=NULL;
    while(n--){
        scanf("%d",&m);
        insert(m,head);
    }
    pr(head,1);
     return 0;
}