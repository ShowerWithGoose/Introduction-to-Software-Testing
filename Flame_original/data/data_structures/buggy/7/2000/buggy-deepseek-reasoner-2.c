#include <stdio.h>
#include <stdlib.h>
typedef int Datatype;
struct node{
    Datatype data;
    struct node *left;
    struct node *right;
    int depth;
};    
typedef struct node BTNode,*BTNodePtr;
BTNodePtr root=NULL;
BTNodePtr insert(BTNodePtr p,Datatype data,int depth);
void print(BTNodePtr p);
void inorder(BTNodePtr p);
int main()
{
    int n,data;
    BTNodePtr p=NULL;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&data);
        p=insert(p,data,1);
        if (i==0) root=p;
    }
    inorder(root);
    return 0;
}
BTNodePtr insert(BTNodePtr p,Datatype data,int depth)
{
    if (p==NULL)
    {
        p=(BTNodePtr)malloc(sizeof(BTNode));
        p->data=data;
        p->left=p->right=NULL;
        p->depth=depth;
    }
    else if (data<p->data)
    {
        p->left=insert(p->left,data,depth+1);
    }
    else if (data>p->data) // @@ [The condition should be data >= p->data to match the specification that right child values are greater than or equal to root.]
    {
        p->right=insert(p->right,data,depth+1);
    }
    return p;
}
void print(BTNodePtr p)
{
    printf("%d %d\n",p->data,p->depth);
}
void inorder(BTNodePtr root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        if (root->left==NULL&&root->right==NULL)
            print(root);
        inorder(root->right);
    }
}