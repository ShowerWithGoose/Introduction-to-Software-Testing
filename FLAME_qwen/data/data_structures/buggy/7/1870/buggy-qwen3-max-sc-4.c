#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [The 'depth' variable is global and shared across recursive calls, but it's not correctly tracking the depth of each node during tree construction or traversal. It starts at 0 and is modified during traversal, but leaf nodes will all print the same (incorrect) depth because the depth isn't stored per node.]

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
            printf("%d %d\n",T->data,depth); // @@ [The 'depth' here is a global variable that doesn't represent the actual depth of the current node. The depth should be passed as a parameter or stored in the node during insertion.]
        }
        
        depth++; // @@ [Incrementing depth before recursing left affects the depth for both left and right subtrees incorrectly due to shared global state. Also, depth starts at 0, so root would be printed with depth 0 if it were a leaf, but problem states root height is 1.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [This decrement assumes symmetric recursion, but since depth is global, interleaved recursive calls corrupt the depth value for other branches.]
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
    preorder(root); // @@ [The 'depth' global variable is never initialized to 1 (as required by problem: root height = 1), so even if logic were correct, output heights would be off by one.]
    return 0;
}