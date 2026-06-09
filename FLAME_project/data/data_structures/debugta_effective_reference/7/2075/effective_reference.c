#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Node{
    int data;
    int depth;
    struct Node *left,*right;
};
typedef struct Node BTNnode;
typedef struct Node *BTNnodeptr;
BTNnodeptr insertBST(BTNnodeptr root,int a,int h);
void inorder(BTNnodeptr root);
int h=1;
int main()
{
    BTNnodeptr root=NULL;
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        root=insertBST(root,item,h);
    }
    inorder(root);
    return 0;
}
BTNnodeptr insertBST(BTNnodeptr root,int a,int h)
{
    if(root==NULL)
    {
        root=(BTNnodeptr)malloc(sizeof(BTNnode));
        root->data=a;
        root->right=root->left=NULL;
        root->depth=h;
    }
    else if(a<root->data)
    {
        root->left=insertBST(root->left,a,h+1);//注意此处为p->left
    }
    else if(a>=root->data)
    {
        root->right=insertBST(root->right,a,h+1);
    }
    return root;
}
void inorder(BTNnodeptr root)
{
    if(root!=NULL)
    {
    inorder(root->left);
        if(root->left==NULL&&root->right==NULL)
        {
            printf("%d %d\n",root->data,root->depth);
        }
    inorder(root->right);
    }
}


