#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct c{
    int number;
    struct c *left;
    struct c *right;
    int depth;
}tree,*treep;

void build(treep *t,int num,int dep){
    if(*t==NULL)
    {
        *t=(treep)malloc(sizeof(tree));
        (*t)->left = (*t)->right = NULL;
        (*t)->number=num;
        (*t)->depth=dep;
    }
    else if((*t)->number<num)
    {
        build(&((*t)->right), num, dep + 1);
    }
    else if((*t)->number>num)
    {
        build(&((*t)->left), num, dep + 1);
    }
    else 
    {
        build(&((*t)->right), num, dep + 1); // @@ The problem states that values greater than or equal to the root go to the right child. The original code incorrectly sends equal values to the left child.
    }
}


void out(treep t){
    if (t == NULL){
        return;
    }
    out(t->left); // @@ To output leaf nodes in left-to-right order (in-order traversal for BST structure relative to position), we must traverse left first. The original code checked for leaf status before traversing, which is fine for identification, but the traversal order here was pre-order. While pre-order visits root-left-right, "left-to-right" for leaves in a BST usually implies an in-order traversal of the tree to visit nodes from smallest to largest spatially. Let's re-evaluate. Actually, standard "left to right" visual order corresponds to In-Order traversal. The original `out` function does Pre-Order (Check, Left, Right). If we change to In-Order (Left, Check, Right), we get sorted order. Let's look at the expected output: 12, 47, 62, 87, 100, 138, 162, 189. These are sorted. This confirms In-Order traversal is required.
    if(t->left==NULL&&t->right==NULL){
        printf("%d %d\n",t->number,t->depth);
    }
    out(t->right);
}


int main()
{
    int n,m;
    treep root=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        build(&root,m,1);
    }
    out(root);
    return 0;
}