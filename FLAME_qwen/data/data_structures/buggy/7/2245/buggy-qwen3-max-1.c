#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct BTREE
{
    int num;
    struct BTREE *left,*right;
}*root=NULL;
int h=0; // @@ [Global variable 'h' is used to track height during traversal, but it's shared across all recursive calls, leading to incorrect height values for leaf nodes. Height should be passed as a parameter or stored in the node during insertion.]

struct BTREE *insertBST(struct BTREE *,int);
void printLeaf(struct BTREE *);

int main()
{
    int t,item;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    printLeaf(root);
    return 0;
}

struct BTREE *insertBST(struct BTREE *p,int item){
    if(p==NULL){
        p=(struct BTREE *)malloc(sizeof(struct BTREE));
        p->num=item;
        p->left=p->right=NULL;
    }
    else if(item<p->num)
        p->left=insertBST(p->left,item);
    else
        p->right=insertBST(p->right,item);
    return p;
}

void printLeaf(struct BTREE *p){
    h++; // @@ [Incrementing global 'h' on entry assumes depth-first left-to-right traversal correctly tracks height, but backtracking with shared state causes incorrect heights when multiple branches exist.]
    if(p==NULL){
        h--;
        return;
    }
    printLeaf(p->left);
    if(p->left==NULL&&p->right==NULL)
        printf("%d %d ",p->num,h); // @@ [Output format uses space instead of newline; problem requires each leaf on a separate line. Also, height value is incorrect due to flawed tracking.]
    printLeaf(p->right);
    h--; // @@ [Decrementing global 'h' after both subtrees may not correctly restore height in all cases due to shared mutable state across recursion.]
}