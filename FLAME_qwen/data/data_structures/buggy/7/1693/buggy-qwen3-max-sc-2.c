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
            p->h=height; // @@ [This line incorrectly updates the parent's height 'h' instead of the new node's height. Also, 'height' is a global variable that gets reused across insertions, leading to incorrect height calculations.]
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
            p->h=height; // @@ [Same issue: parent's height is overwritten, and global 'height' causes incorrect state across recursive calls and multiple insertions.]
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
        if(q->right!=NULL) // @@ [After traversing left subtree, 'q' has been changed; using 'q->right' here may access wrong/right child of left child instead of original node's right child. Should use 'middle->right'. However, note that the next line does use 'middle->right', so this condition should also use 'middle->right != NULL' to be consistent and correct.]
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
            height=1; // @@ [Resetting 'height' after insertion is too late; during the recursive 'input' call, the global 'height' was already modified and used incorrectly. The global 'height' approach is fundamentally flawed for tracking node depth during insertion.]
        }
    }
    output(root);
    return 0;
}