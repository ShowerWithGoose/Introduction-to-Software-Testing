#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    int data;
    int h;
    struct Node *left,*right;
}*node=NULL,*root=NULL;
int height=1;
void input(struct Node *p,struct Node *t)//p代入时 代root 
{
    if(t->data<p->data)
    {
        if(p->left==NULL)
        {
            p->left=t;
            p->h=height; // @@ The height of the parent node 'p' is incorrectly updated here. It should only be set when 'p' is created or initially inserted. Updating it during subsequent insertions corrupts the height of existing nodes.
            height++;
            t->h=height;
        }
        else
        {
            height++;
            p=p->left;
            input(p,t);
        }
    }
    else
    {
        if(p->right==NULL)
        {
            p->right=t;
            p->h=height; // @@ The height of the parent node 'p' is incorrectly updated here. Similar to the left child case, this overwrites the correct height of an existing node.
            height++;
            t->h=height;
        }
        else
        {
            height++;
            p=p->right;
            input(p,t);
        }
    }
    return;
}
void output(struct Node *q)
{
    struct Node *middle;
    middle=q;
    if(q->left==NULL&&q->right==NULL)
    {
        printf("%d %d\n",q->data,q->h);
    }
    else
    {
        if(q->left!=NULL)
        {
        q=q->left;
        output(q);
        }
        if(q->right!=NULL)
        {
        q=middle->right; // @@ Although 'middle' preserves the original root of the current subtree, using 'q' (which might have been modified in the previous if block) to check condition is risky, but logically this line restores q for the right traversal. However, the main issue is that the variable 'q' is modified in the left traversal block `q=q->left`, affecting the state if not careful. But here `middle` is used correctly to get right child. The logic here is actually okay for traversal order, but let's look closer. Wait, if `q->left` was NULL, `q` remains `middle`. If `q->left` was not NULL, `q` becomes `q->left`. Then we check `if(q->right!=NULL)`. This checks the RIGHT CHILD OF THE LEFT CHILD, not the RIGHT CHILD OF THE ROOT. This is a logical error in traversal.
        output(q);
        }
    }
    return;
}
int main()
{    
    int n,i;
    int t[500];//小于树根： 
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    for(i=0;i<n;i++)
    {
        node=(struct Node *)malloc(sizeof(struct Node));
        node->data=t[i];
        node->left=NULL;
        node->right=NULL;
        if(root==NULL)
        {
            root=node;
            root->h=1;
        }
        else
        {
            input(root,node);
            height=1;
        }
    }
    output(root);
    return 0;
}