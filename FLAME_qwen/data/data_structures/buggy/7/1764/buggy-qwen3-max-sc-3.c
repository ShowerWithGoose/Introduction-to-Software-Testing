#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr root=NULL;
int height; // @@ [Global variable 'height' is modified non-locally in recursive function 'sreachBST', causing incorrect height calculation due to shared state across recursive calls]
BTNodeptr insertBST(BTNodeptr p,int item);
int sreachBST(BTNodeptr p,BTNodeptr q); // @@ [Function 'sreachBST' has flawed logic: it uses a global 'height' variable and increments it during unwinding, leading to incorrect height values; also, unreachable code after 'return height']
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
    height=1; // @@ [Resets global 'height' on every call, but recursive calls interfere with each other because they share the same global variable]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [Incorrectly recurses even after finding the node; also, does not handle case where node is root properly]
            height++; // @@ [Modifies global 'height' after recursive call, which corrupts value for other calls]
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Recursive call does not use returned value; instead relies on global 'height' which is error-prone]
            height++; // @@ [Same issue: modifies global state incorrectly during recursion unwinding]
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same problem: ignores return value and mutates global 'height']
            height++; // @@ [Leads to overcounting height due to multiple increments during unwinding]
        }
    }
    return height;
    if(p==NULL) // @@ [Unreachable code: this line comes after a return statement and will never execute]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [Calls 'sreachBST' which returns incorrect height due to global variable misuse and flawed recursion logic]
    }
}