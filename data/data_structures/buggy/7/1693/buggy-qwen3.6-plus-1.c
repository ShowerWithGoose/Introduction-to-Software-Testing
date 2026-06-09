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
            p->h=height; // @@ Incorrectly overwrites the height of an existing node p. The height of p is already set and should not be modified.
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
            p->h=height; // @@ Incorrectly overwrites the height of an existing node p. The height of p is already set and should not be modified.
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
        if(q->right!=NULL) // @@ q was reassigned to q->left in the previous block, so this condition checks the wrong node's right child. It should check middle->right.
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
            height=1;
        }
    }
    output(root);
    return 0;
}