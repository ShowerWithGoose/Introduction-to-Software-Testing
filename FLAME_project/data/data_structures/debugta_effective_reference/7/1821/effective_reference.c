#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct tree
{
    int a;
    int m;
    struct tree *left;
    struct tree *right;
};
typedef struct tree Tree;
typedef struct tree *Treeptr;
void Visit(Treeptr t)
{
    printf("%d %d\n",t->a,t->m);
}
void Traverse(Treeptr t)
{
    if(t != NULL)
    {
        Traverse(t->left);
        if(t->left == NULL && t->right == NULL)
            Visit(t);
        Traverse(t->right);
    }
}
Treeptr insert(Treeptr t,int a,int m)
{
    if(t == NULL)
    {
        t = (Treeptr)malloc(sizeof(Tree));
        t->a = a;
        t->m = m;
        t->left = t->right = NULL;

    }
    else if(a < t->a)
        t->left = insert(t->left,a,m+1);
    else if(a >= t->a)
        t->right = insert(t->right,a,m+1);
    return t;
}
int main()
{
    int n,i;
    int a;
    Treeptr root = NULL;
    scanf("%d",&n);
    for(i = 0; i< n; i++)
    {
        scanf("%d",&a);
        //printf("test == %d\n",data);
        root = insert(root,a,1);

    }
    Traverse(root);
    return 0;

}



