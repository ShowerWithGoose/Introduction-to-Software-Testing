#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [Global variable 'depth' is not properly initialized or updated during tree construction; it is modified during traversal but does not reflect actual node depth]

BTNodeptr createTree(BTNodeptr T,int a)
{
    BTNodeptr p;
    if(T==NULL)
    {
        T=(BTNodeptr)malloc(sizeof(BTNode));
        T->data=a;
        T->left=T->right=NULL;
    }
    else if(a<T->data)
    {
        T->left=createTree(T->left,a);
    }
    else if(a>=T->data)
    {
        T->right=createTree(T->right,a);
    }
    
    return T;
}

void preorder(BTNodeptr T)
{
    if(T==NULL)
    return;
    else
    {
        if(T->left==NULL&&T->right==NULL)
        {
            printf("%d %d\n",T->data,depth); // @@ [Using global 'depth' which does not represent the actual depth of current node; depth should be passed as parameter or stored in node]
        }
        
        depth++; // @@ [Incrementing global 'depth' before traversing children leads to incorrect depth values for leaf nodes]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [Decrementing after traversal may not correctly restore depth due to shared global state across recursive calls]
    }
}

int main()
{
    int n,a;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=createTree(root,a);
    }
    depth = 1; // @@ [Missing initialization of 'depth' before traversal; without this, depth starts at 0 or garbage value]
    preorder(root);
    return 0;
}