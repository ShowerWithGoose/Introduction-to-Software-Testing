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
    for(int i=0;i<n;i++) // @@ [Compilation Error] C89/C90 standard does not allow variable declaration inside for-loop initialization. Declare 'int i' before the loop.
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
        root=p; // @@ [Logical Error] p->deep is not initialized here. It should be set to 1 for the root node.
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
    if(k->left) // @@ [Runtime Error] If k is NULL (e.g., empty tree), accessing k->left causes a segmentation fault. Add a NULL check for k at the start of the function.
        g(k->left);
    if(k->left==NULL&&k->right==NULL)
        printf("%d %d\n",k->data,k->deep);
    if(k->right)
        g(k->right);
}