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
    f(root,h); // @@ [The function f does not handle the case when root is NULL (empty tree), which can cause a runtime error. Additionally, the height of each node is not stored during insertion, so the traversal cannot correctly compute heights on the fly using a single h parameter passed by value; this leads to incorrect height values for leaf nodes.]

    return 0;
}