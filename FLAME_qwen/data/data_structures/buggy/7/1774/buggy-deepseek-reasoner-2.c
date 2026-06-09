#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h> 
 struct tree
{
    int n;
    struct tree* pl;
    struct tree* pr;
};
 typedef struct tree* TREE;
 typedef struct tree Tree;
TREE root;
TREE tree_add(TREE root, int k);
void tree_visit(TREE root, int level);

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int m = 0;
        scanf("%d", &m);
        root = tree_add(root, m);
    }
    tree_visit(root, 1);
    return 0;
}

//===================define====================
TREE tree_add(TREE root, int k)
{
    if (root == NULL)
    {
        TREE q = (TREE)malloc(sizeof(Tree));
        q->n = k;
        q->pl = NULL;
        q->pr = NULL;
        return q;
    }
    if (k < root->n)
    {
        root->pl = tree_add(root->pl, k);
    }
    else
    {
        root->pr = tree_add(root->pr, k);
    }
    //return root; // @@ This line is commented out, causing the function to not return a value when root is not NULL. This leads to undefined behavior and a compilation error (if warnings are treated as errors). It should be uncommented to return the root.
}

void tree_visit(TREE root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->pl == NULL && root->pr == NULL)
    {
        printf("%d %d\n", root->n, level);
        return;
    }
    tree_visit(root->pl, level + 1);
    tree_visit(root->pr, level + 1);
}

------ // @@ This line is not valid C syntax. It will cause a compilation error. It should be removed.