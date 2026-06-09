#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct bst{
    int data;
    struct bst* left,*right;
};
typedef struct bst* BST;
typedef struct bst Bst;

void f(BST p,int h)
{
    if(p->left!=NULL || p->right!=NULL)
    {
        f(p->left,h+1); // @@ [Potential null pointer dereference: p->left may be NULL when p->right is not NULL, causing crash inside f.]
        f(p->right,h+1); // @@ [Potential null pointer dereference: p->right may be NULL when p->left is not NULL, causing crash inside f.]
    }
    else
    printf("%d %d\n",p->data,h);
}

int main()
{
    BST root=NULL,p,q;
    int data;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        p=(BST)malloc(sizeof(Bst));
        p->data=data;
        p->left=NULL;
        p->right=NULL;
        
        if(root==NULL)
        {
            root=p;
        }
        else
        {
            q=root;
            while(1)
            {
                if(p->data<q->data)
                {
                    if(q->left==NULL)
                    {
                        q->left=p;
                        break;
                    }
                    else
                    {
                        q=q->left;
                    }
                }
                else
                {
                    if(q->right==NULL)
                    {
                        q->right=p;
                        break;
                    }
                    else
                    {
                        q=q->right;
                    }
                }
            }
        }
    }
//    printf("%d",root->left->data);
//    return 0;
    
    int h=1;
    f(root,h);
    
    return 0;
}