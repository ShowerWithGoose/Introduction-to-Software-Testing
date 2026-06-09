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
int sreachBST(BTNodeptr p,BTNodeptr q)
{
    height=1; // @@ [The global variable is reset to 1 on every recursive call, destroying accumulation from parent calls. Should accumulate height by passing a running depth parameter.]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root) // @@ [This condition returns height=1 prematurely for non‑root nodes, ignoring the actual depth accumulated so far. The check `p!=root` is incorrect and unnecessary.]
        {
            return height;
        }
        else if(p->data==q->data&&p==root) // @@ [For the root node this branch is entered; it calls sreachBST(p->right,q) and then increments height, but the recursive call for the right child is meaningless and leads to height=2 for a single-node tree. Root height should be 1 without any recursion.]
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
    return height; // @@ [Returns the global variable without using the result of recursive calls; the recursion does not propagate the correct depth.]
    if(p==NULL) // @@ [Unreachable code after the return statement above. This line is dead and does not affect execution, but indicates a logical structure error.]
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