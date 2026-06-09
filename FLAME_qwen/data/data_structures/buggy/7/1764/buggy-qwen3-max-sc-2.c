#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ [Global variable 'height' is modified recursively in sreachBST without proper initialization per call, leading to incorrect height calculation]
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q); // @@ [Function name typo: 'sreachBST' should be 'searchBST'; also logic for computing height is flawed due to global 'height' and incorrect recursion handling]
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
    height=1; // @@ [Resets global 'height' to 1 on every call, but recursive calls overwrite it incorrectly; also, this function does not correctly compute the depth of node 'q']
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height; // @@ [Returns height=1 always here, which is wrong because actual depth may be greater]
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [Incorrectly recurses right even when found at root; also ignores return value]
            height++; // @@ [Increments global height after recursive call, corrupting value]
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Ignores return value of recursive call; modifies global height after return]
            height++; // @@ [Post-increment leads to incorrect accumulation]
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same issue: ignores return value and corrupts global height]
            height++; // @@ [Same issue]
        }
    }
    return height;
    if(p==NULL) // @@ [Unreachable code: this line never executes because of prior return]
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
    else if(item>p->data||item==p->data) // @@ [Redundant condition: 'item>=p->data' suffices; but logically correct per problem (right for >=)]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [Calls flawed sreachBST which uses global 'height', causing incorrect height output for leaf nodes]
    }
}