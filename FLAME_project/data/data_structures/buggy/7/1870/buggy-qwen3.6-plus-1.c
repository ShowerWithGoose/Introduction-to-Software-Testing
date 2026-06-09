#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ The global variable 'depth' is uninitialized (defaults to 0). It should be initialized to 1 because the problem states the height of the root node is 1. Additionally, using a global variable for depth in a recursive traversal that modifies it can be error-prone if not managed correctly, but the primary issue here is the initial value.

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
            printf("%d %d\n",T->data,depth);
        }
        
        depth++;
        preorder(T->left);
        preorder(T->right);
        depth--;
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
    preorder(root);
    return 0;
}