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
    for(int i=0;i<n;i++) // @@ Variable declaration inside for loop is not allowed in C89/C90 standard, causing compilation error
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
        root=p; // @@ p->deep is not initialized for the root node, it should be explicitly set to 1
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
void g(struct node *k) // @@ Missing NULL check for parameter k, which may cause segmentation fault if the tree is empty
{
    if(k->left) // @@ Accessing member of potentially NULL pointer k without prior validation
        g(k->left);
    if(k->left==NULL&&k->right==NULL)
        printf("%d %d\n",k->data,k->deep);
    if(k->right)
        g(k->right);
}