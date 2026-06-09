#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ [Global variable 'height' is modified recursively in 'sreachBST', causing incorrect height calculation due to shared state across recursive calls]
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q); // @@ [Function name typo: 'sreachBST' should likely be 'searchBST'; also logic for computing height is flawed]
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
    height=1; // @@ [Resets global 'height' on every call, but recursive calls interfere with each other because they all share the same global variable]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root) // @@ [When node is root, it incorrectly recurses into right subtree and increments height, which is logically wrong for height calculation]
        {
            sreachBST(p->right,q);
            height++;
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Recursive call does not use returned value; instead relies on global 'height' which gets overwritten]
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same issue: recursive result ignored, global 'height' incremented after possibly unrelated recursive modification]
            height++;
        }
    }
    return height;
    if(p==NULL) // @@ [Unreachable code: this line will never execute because it comes after a return statement]
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
    else if(item>p->data||item==p->data) // @@ [Redundant condition: 'item >= p->data' would suffice; however, this is logically correct per problem (right child >= root)]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [Calls flawed 'sreachBST' which uses global 'height', leading to incorrect height output for leaf nodes]
    }
}