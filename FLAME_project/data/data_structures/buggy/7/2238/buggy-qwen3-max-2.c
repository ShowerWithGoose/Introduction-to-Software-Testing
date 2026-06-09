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
    else if(x==NULL) return 0; // @@ [The check for NULL should come before accessing x->left and x->right to avoid dereferencing a null pointer, which causes a runtime error.]
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