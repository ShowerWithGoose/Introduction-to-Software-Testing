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
        build(&((*t)->left), num, dep + 1); // @@ [Error: When num equals the current node's value, the problem requires the right child to be greater than or equal to the root, so equal values should go to the right subtree, not the left. This causes the node with value 100 to be placed incorrectly, leading to the missing leaf 87 and the wrong depth for 100.]
    }
}


void out(treep t){
    if (t == NULL){
        return;
    }
    if(t->left==NULL&&t->right==NULL){
        printf("%d %d\n",t->number,t->depth);
    }
    out(t->left);
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