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
            p->h=height; // @@ Error: This sets the parent node's height to the current height, but the parent's height should already be set correctly when it was inserted. This overwrites the parent's height incorrectly.
            height++;
            t->h=height; // @@ Error: This sets the new node's height to the incremented height, but the new node's height should be the parent's height + 1, not the incremented value. Also, the parent's height is incorrectly set above.
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
            p->h=height; // @@ Error: Same issue as above - incorrectly overwrites parent's height.
            height++;
            t->h=height; // @@ Error: Same issue as above - incorrectly sets new node's height.
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
        q=middle->right;
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
            height=1; // @@ Error: Resetting height to 1 after each insertion is incorrect; height should be tracked relative to the root during traversal, not reset globally.
        }
    }
    output(root);
    return 0;
}