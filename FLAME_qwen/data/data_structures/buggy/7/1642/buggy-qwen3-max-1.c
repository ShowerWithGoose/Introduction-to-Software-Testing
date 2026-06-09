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
        build(&((*t)->left), num, dep + 1); @@ [When the value equals the current node's value, it should go to the right subtree per problem statement ("right child is greater than or equal"), but this code incorrectly inserts it into the left subtree.]
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