#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

struct takanashi
{
    int high;
    int date;
    struct takanashi *left,*right;
};

typedef struct takanashi tree;
typedef struct takanashi* treeptr;

treeptr first;

treeptr intree(treeptr root,int temp,int len)
{
    len++;
    if(root==NULL)
    {
        root=(tree*)malloc(sizeof(tree));
        root->date=temp;
        root->left=root->right=NULL;
        first=root;
        root->high=len;
    }
    else if(temp<root->date)
        root->left=intree(root->left,temp,len);
    else if(temp>=root->date)
        root->right=intree(root->right,temp,len);
    return root;
}

void output(treeptr root)
{
    if(root)
    {
        if((root->left==NULL)&&(root->right==NULL))
            printf("%d %d\n",root->date,root->high);
        output(root->left);
        output(root->right);
    }
}

int main()
{
    int i,n,temp;
    int len;
    treeptr root=NULL;
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    {
        len=0;
        scanf("%d",&temp);
       root=intree(root,temp,len);
    }

    output(root);
}

