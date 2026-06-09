#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    int height;
    struct Node *left,*right;
}Tree;
Tree *first;
Tree *New(Tree *root,int temp,int len);
void print(Tree *root);
Tree *New(Tree *root,int temp,int len)
{
    len++;
    if(root==NULL)
    {
        root=(Tree *)malloc(sizeof(Tree));
        root->data=temp;
        root->left=root->right =NULL;
        first=root;
        root->height=len;
    }
    else if(temp<root->data)
        root->left =New(root->left,temp,len);
    else if(temp>=root->data)
        root->right=New(root->right,temp,len);
    return root;
}
void print(Tree *root)
{
    if(root)
    {
        if(!(root->left)&&!(root->right))
        {
            printf("%d %d\n",root->data,root->height);
        }
        print(root->left);
        print(root->right);
    }
}
int main()
{
    Tree *root = NULL;
    int n,temp,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&temp);
        int len=0;
        root=New(root,temp,len);
    }
    print(root);
    return 0;
}

