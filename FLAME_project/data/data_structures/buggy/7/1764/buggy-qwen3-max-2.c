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
    height=1; // @@ [This resets height to 1 at the start of every call, but height should accumulate during recursion. Also, this global variable approach is flawed because recursive calls interfere with each other.]
    if(p!=NULL)
    {
            if(p->data==q->data&&p!=root)
        {
            return height;
        }
        else if(p->data==q->data&&p==root)
        {
            sreachBST(p->right,q); // @@ [This recursive call doesn't make sense when p == q (same node). It leads to incorrect height calculation. Also, height is incremented after the call, which is logically wrong.]
            height++; // @@ [Incrementing height after a recursive call that already modifies height leads to double counting or incorrect values.]
        }
        else if(p->data>q->data)
        {
            sreachBST(p->left,q); // @@ [Recursive call modifies global 'height', but then we increment it again below, leading to overcounting.]
            height++; // @@ [Same issue: height is being incremented after recursive call, causing incorrect height computation.]
        }
        else if(p->data<q->data)
        {
            sreachBST(p->right,q); // @@ [Same problem: recursive call followed by increment corrupts height value.]
            height++; // @@ [Overcounts height due to post-recursion increment on a global variable.]
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
        printf("%d %d\n",p->data,sreachBST(root,p)); // @@ [The function sreachBST uses a flawed global 'height' variable and incorrect recursion logic, leading to wrong height values (e.g., root leaf reported as height 2 instead of 1).]
    }
}