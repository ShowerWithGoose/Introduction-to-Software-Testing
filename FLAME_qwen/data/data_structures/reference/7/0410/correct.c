#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    int deep;
    struct node *left,*right;
};

typedef struct node Tree;
typedef struct node *Nodeptr;
Nodeptr high;

Nodeptr op(Nodeptr root,int tmp,int len)
{
    len++;
    if(root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));
        root->num = tmp;
        root->left = NULL;
        root->right = NULL;
        high = root;
        root->deep = len;
    }
    else if(tmp<root->num)root->left = op(root->left,tmp,len);
    else if(tmp>=root->num)root->right = op(root->right,tmp,len);
    return root;
}

void homo(Nodeptr root)
{
    if(root!=NULL)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            printf("%d %d\n",root->num,root->deep);
        }
        homo(root->left);
        homo(root->right);
    }
    return;
}

int main()
{
    Nodeptr root = NULL;
    int n,tmp,len;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {

        scanf("%d",&tmp);
        len = 0;
        root = op(root,tmp,len);
    }
    homo(root);

    return 0;
}

