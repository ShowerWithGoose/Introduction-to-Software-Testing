#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ [Global variable 'height' is used in recursive function 'sreachBST', causing incorrect height calculation due to shared state across recursive calls]
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q); // @@ [Function 'sreachBST' has flawed logic for computing node height and contains unreachable code after return statement]
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
    height=1; // @@ [Resets global 'height' on every call, breaking recursion-based height tracking]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height; // @@ [Returns 1 always for non-root matches, ignoring actual depth]
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [Incorrectly recurses right even when target may not be there; also ignores return value]
            height++; // @@ [Increments global height after recursive call, leading to wrong values]
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Ignores return value of recursive call]
            height++; // @@ [Post-recursion increment corrupts height due to global variable use]
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Ignores return value of recursive call]
            height++; // @@ [Post-recursion increment corrupts height due to global variable use]
        }
    }
    return height; // @@ [Returns global height which has been inconsistently modified]
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
    else if(item>p->data||item==p->data) // @@ [Redundant condition: 'item>=p->data' would suffice; but logically correct per problem (right for >=)]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [Calls flawed 'sreachBST' which returns incorrect height due to global variable misuse and broken recursion logic]
    }
}