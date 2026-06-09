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
    height=1; // @@ [This resets height to 1 at the start of every call, but height should accumulate during recursion. Also, the logic for computing height is flawed because it doesn't correctly track depth from root to node.]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height; // @@ [Returning height=1 here is incorrect because it doesn't reflect the actual depth of the node in the tree.]
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [This recursive call is unnecessary and incorrect when p == q == root; also, height is incremented after the call, leading to wrong height calculation.]
            height++; // @@ [Incrementing height after a recursive call that may not even reach the target leads to incorrect height values.]
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Recursive call is made, but its return value is ignored, and height is incremented unconditionally afterward, which does not correctly compute depth.]
            height++; // @@ [Same issue: height is incremented regardless of whether the recursive call actually progressed toward the target node.]
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same problem: return value ignored, height incremented incorrectly.]
            height++; // @@ [Incorrectly increments height without knowing if the path was valid or how deep the node really is.]
        }
    }
    return height;
    if(p==NULL)
    return 0; // @@ [This code is unreachable due to the return statement above; also, base case handling is missing in the recursion.]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [The sreachBST function does not correctly compute the height (depth) of node p; it uses a global variable and flawed recursion, leading to wrong height output like 2 instead of 1 for a single-node tree.]
    }
}