#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* Root=NULL;

struct node* Insert(struct node* root,int element)
{
    if(root==NULL)
    {
        root=malloc(sizeof(struct node));
        root->data=element;
        root->left=root->right=NULL;
    }
    else if(element<root->data)
        root->left=Insert(root->left,element);
    else if(element>=root->data)
        root->right=Insert(root->right,element);
    return root;
}

int Height(struct node* root,int aim)
{
    if(root==NULL)
        return 0;

    int height=0;
    struct node* tmp=root;
    while(tmp)
    {
        if(tmp->data==aim)
        {
            height++;
            if(tmp->left==NULL && tmp->right==NULL)
                break;
            else
                tmp=tmp->right;
        }
        else if(aim<tmp->data)
        {
            height++;
            tmp=tmp->left;
        }
        else
        {
            height++;
            tmp=tmp->right;
        }
    }
    return height;
}

void Visitleef(struct node* root)
{
    if(root==NULL)
        return;
    else
    {
        if(root->left==NULL &&root->right==NULL)
        {
            printf("%d %d\n",root->data,Height(Root,root->data));
            return;
        }
        else
        {
            Visitleef(root->left);
            Visitleef(root->right);
        }
    }
}

int main(void)
{
    int N;
    scanf("%d",&N);

    int element;
    while(N--)
    {
        scanf("%d",&element);
        Root=Insert(Root,element);
    }
    Visitleef(Root);
    return 0;
}
