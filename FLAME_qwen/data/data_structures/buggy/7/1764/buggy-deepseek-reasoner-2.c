#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ Error: Global variable used without proper isolation; recursive calls modify the same variable, causing incorrect depth calculation.
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
    height=1; // @@ Error: Resetting global height at every call; recursive calls will overwrite each other, leading to unpredictable depth values.
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ Error: Recursive call without returning its result; also, this branch is meant for the root but incorrectly traverses right subtree, causing infinite recursion or wrong depth.
            height++; // @@ Error: Increment after recursion is misplaced; the depth of root should be 1, not incremented after a futile recursive call.
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ Error: Recursive call without returning its result; the function ignores the returned depth from recursion.
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ Error: Same issue, recursive call result not returned.
            height++;
        }
    }
    return height; // @@ Error: Returns the global height that has been improperly modified; also, if p is NULL, it incorrectly returns 1.
    if(p==NULL) // @@ Error: Unreachable code; the previous return statement makes this dead code.
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
    else if(item>p->data||item==p->data) // @@ Error: Redundant condition; can be simplified to else. Also, this branch puts all equal values to the right, which matches the requirement, but no logical error.
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ Error: Uses flawed sreachBST to compute depth; the depth values will be incorrect.
    }
}