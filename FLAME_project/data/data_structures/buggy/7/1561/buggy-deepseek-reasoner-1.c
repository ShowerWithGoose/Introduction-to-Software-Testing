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
    if(p->left!=NULL || p->right!=NULL) // @@ p may be NULL when called recursively from lines 17 or 18; dereferencing NULL pointer causes runtime error. Add a NULL check before this line.
    {
        f(p->left,h+1);
        f(p->right,h+1);
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