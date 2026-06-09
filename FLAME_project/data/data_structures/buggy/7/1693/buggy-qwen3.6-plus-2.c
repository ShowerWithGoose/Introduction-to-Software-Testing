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
            p->h=height; // @@ The height of the parent node 'p' is being overwritten incorrectly. It should retain its existing height. Only the new node 't' needs its height set.
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
            p->h=height; // @@ The height of the parent node 'p' is being overwritten incorrectly. It should retain its existing height. Only the new node 't' needs its height set.
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
        q=middle->right; // @@ Although 'middle' preserves the original root of this subtree, using 'q' here is risky if the previous recursive call modified state unexpectedly, but logically this line attempts to correct the pointer. However, the primary logic error causing Runtime Error or wrong output is often in the height calculation or tree structure. In this specific code, if q->left was NULL, q remains unchanged. If q->left was not NULL, q becomes left child. Then we check q->right. But we want middle->right. This line is actually correct in intent (using middle), but let's look closer. Wait, if q->left is NULL, we skip the first if. Then we check if q->right != NULL. Here q is still the original node. So middle->right is same as q->right. If q->left was NOT NULL, q is now left child. Then we check if q->right != NULL (checking left child's right). This is WRONG. We should check middle->right. The code does `if(q->right!=NULL)` which checks the LEFT child's right sibling existence? No, it checks the current q (which is left child)'s right pointer. But we want to traverse the RIGHT child of the ORIGINAL node (middle). So the condition `if(q->right!=NULL)` is checking the wrong node's right child. It should be `if(middle->right!=NULL)`.
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