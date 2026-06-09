#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ [Global variable 'height' is modified in recursive function 'sreachBST', causing incorrect height calculation due to shared state across recursive calls]
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q); // @@ [Function 'sreachBST' has flawed logic: it uses a global 'height' and does not correctly compute the depth of node 'q'; also, unreachable code after return]
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
    height=1; // @@ [Resets global 'height' on every call, but recursive calls interfere with each other due to shared global state]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height; // @@ [Returns 1 always here, which is incorrect unless q is direct child of root]
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [This recursive call doesn't make sense: if p == root and p->data == q->data, then q is root, so height should be 1, not recursing right]
            height++;
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Recursive call modifies global 'height', but return value is ignored; increment after recursion is logically wrong]
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same issue: ignores return value and incorrectly increments global height after recursion]
            height++;
        }
    }
    return height;
    if(p==NULL) // @@ [Unreachable code: this line will never execute because of the return statement above]
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
    else if(item>p->data||item==p->data) // @@ [Redundant condition: 'item >= p->data' would suffice; but logically correct per problem (right for >=)]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [Calls 'sreachBST' which uses flawed global 'height' logic, leading to incorrect height output]
    }
}