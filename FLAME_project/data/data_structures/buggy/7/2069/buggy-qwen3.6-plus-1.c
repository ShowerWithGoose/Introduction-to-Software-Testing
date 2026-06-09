#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
    int data;
    int deep;
    struct node *left,*right;
};
struct node *root;
void f(int item);
void g(struct node *k);
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        f(x);
    }
    g(root);
    return 0;
}
void f(int item)
{
    struct node *p,*q;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
    {
        root=p;
        p->deep = 1; // @@ The depth of the root node was not initialized to 1, causing it to remain 0 (or garbage) when printed.
    }
    else
    {
        q=root;
        int d=1;
        while(1)
        {
            if(item<q->data)
            {
                if(q->left==NULL)
                {
                    p->deep=d+1;
                    q->left=p;
                    break;
                }
                else
                {
                    q=q->left;
                    d++;
                }
            }
            else
            {
                if(q->right==NULL)
                {
                    p->deep=d+1;
                    q->right=p;
                    break;
                }
                else
                {
                    q=q->right;
                    d++;
                }
            }
        }
    }
}
void g(struct node *k)
{
    if(k!=NULL) // @@ Added null check to prevent segmentation fault when the tree is empty or during recursion on NULL children, matching the safety of the reference implementation.
    {
        if(k->left)
            g(k->left);
        if(k->left==NULL&&k->right==NULL)
            printf("%d %d\n",k->data,k->deep);
        if(k->right)
            g(k->right);
    }
}