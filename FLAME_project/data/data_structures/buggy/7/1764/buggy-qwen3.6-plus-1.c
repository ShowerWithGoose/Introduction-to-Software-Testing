#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height;
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
int sreachBST(BTNodeptr p,BTNodeptr q) // @@ The logic for calculating height is fundamentally flawed. It uses a global variable 'height' which accumulates incorrectly across recursive calls and doesn't correctly track the depth from the root. Specifically, when the node is found (p->data==q->data), it returns the current accumulated height, but the accumulation logic (incrementing after recursive call or in specific branches) is inconsistent and incorrect for determining the depth of a node in a BST. For the root node, it should be 1, but the logic enters the else-if chain. If p==root and data matches, it goes to line 36, calls search on right (which might be null), increments height, then returns. This results in height 2 for the root if it has no right child, or other incorrect values. A correct approach would pass the current depth as a parameter or calculate it based on the path taken.
{
    height=1;
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q);
            height++;
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q);
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q);
            height++;
        }
    }
    return height;
    if(p==NULL)
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
        printf("%d %d\n",p->data,sreachBST(root,p));
    }
}