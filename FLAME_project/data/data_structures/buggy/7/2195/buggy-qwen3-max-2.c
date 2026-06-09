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
        p->high=q->high+1; // @@ [This sets p->high only once based on root's height, but during traversal down the tree, the height should be updated incrementally as we go deeper. The correct height of the new node depends on the depth of its parent, which is not tracked properly here.]
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
                    q=q->left; // @@ [When moving to the left child, the code does not update p->high to reflect the increasing depth. The height of p should be parent's height + 1, but parent changes as we traverse, and this is never updated after the initial assignment.]
            }
            else
            {
                if(q->right==NULL)
                {
                    q->right=p;
                    break;
                }
                else
                    q=q->right; // @@ [Same issue as above: when traversing right, p->high is not updated to match the current depth. Thus, all inserted nodes end up with height = root->high + 1 = 2, leading to incorrect leaf heights in output.]
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