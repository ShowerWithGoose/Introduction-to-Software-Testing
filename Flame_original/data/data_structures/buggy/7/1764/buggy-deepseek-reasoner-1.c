#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ Global variable used to track depth; recursive calls share this variable, causing incorrect depth calculation because each call modifies the same global, and increments are not properly scoped.
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q);
void inorder(BTNodeptr p);
void visit(BTNodeptr p);
int main()
{
    int n,i;
    scanf("%d",&n);
    int item;
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        root=insertBST(root,item);
    }
    inorder(root);
    return 0;
}
int sreachBST(BTNodeptr p,BTNodeptr q)
{
    height=1; // @@ Resetting height to 1 each call, but later recursion modifies the same global; this does not correctly compute the depth of the node because depth information is not passed along recursively.
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height; // @@ For a non-root node, returns height=1 immediately, ignoring the actual depth (number of edges from root). The depth should be accumulated from root.
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ If the node is root, this incorrectly searches in the right subtree instead of simply returning the root's depth (which should be 1). Also, the recursive call does nothing with the return value.
            height++; // @@ After the recursive call, height is incremented, but the recursive call already modified height, leading to double counting.
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ Recursive call without using the return value; height is global, so it gets modified inside the recursion, then incremented again here, causing incorrect accumulation.
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q);
            height++;
        }
    }
    return height; // @@ Returns the global height, which has been incorrectly modified by the recursive calls and does not represent the true depth of the target node.
    if(p==NULL) // @@ Unreachable code: this statement follows a return, so it will never be executed.
    return 0;
}
BTNodeptr insertBST(BTNodeptr p,int item)
{
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->left=NULL;
        p->right=NULL;
    }
    else if(item<p->data)
    {
        p->left=insertBST(p->left,item);
    }
    else if(item>p->data||item==p->data)
    {
        p->right=insertBST(p->right,item);
    }
    return p;
}
void inorder(BTNodeptr p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}
void visit(BTNodeptr p)
{
    if(p->left==NULL&&p->right==NULL)
    {
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ Calls sreachBST to compute depth, which is flawed as described above. This will produce incorrect heights for leaf nodes.
    }
}