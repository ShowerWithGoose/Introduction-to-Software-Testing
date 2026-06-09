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
    int item; // @@ Variable declaration after an executable statement violates C89 standard, which may cause a compilation error in strict mode.
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
    height=1; // @@ Resets height to 1 on every recursive call, preventing correct depth calculation from the root.
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ Return value of the recursive call is ignored, so the height is not propagated or updated correctly.
            height++;
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ Return value of the recursive call is ignored, so the height is not propagated or updated correctly.
            height++;
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ Return value of the recursive call is ignored, so the height is not propagated or updated correctly.
            height++;
        }
    }
    return height;
    if(p==NULL) // @@ Unreachable code due to the preceding return statement.
    return 0; // @@ Unreachable code.
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