#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct _Tree{
    int data;
    int high;
    struct _Tree* left;
    struct _Tree* right;
}Tree, *PTree;

PTree root;
    
void setBST(int item)
{
    PTree p,q;
    p=(PTree)malloc(sizeof(Tree));
    p->data=item;
    p->high=1;
    p->left=NULL;
    p->right=NULL;
    if(root==NULL)
        root=p;
    else
    {
        q=root;
        p->high=q->high+1; // @@ [The height of the new node is incorrectly initialized to root's height + 1. It should be updated during traversal down the tree, not just based on the root.]
        while(1)
        {
            if(item<q->data)
            {
                if(q->left==NULL)
                {
                    q->left=p;
                    break;
                }
                else
                {
                    q=q->left;
                    p->high++; // @@ [Missing increment of height as we go deeper into the tree. The height should increase with each level descended, but this line is absent.]
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
                    p->high++; // @@ [Same issue as above: missing height increment when traversing right subtree.]
                }
            }
        }
    }
}

int main()
{
    int n,data;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        setBST(data);
    }
    PTree stack[100],p=root;
    int top=-1;
    if (root!=NULL)
        do  //do while循环 
        {   //中序遍历 
            for(;p!=NULL;p=p->left)
                stack[++top]=p;  //左子树和根直接入栈 
            p=stack[top--];
            if(p->left==NULL&&p->right==NULL)
                printf("%d %d\n",p->data,p->high);
            p=p->right;
        }
        while (p!=NULL||top!=-1);
    return 0;
}