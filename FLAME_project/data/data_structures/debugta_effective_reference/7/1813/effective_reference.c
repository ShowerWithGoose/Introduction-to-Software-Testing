#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
struct Node{
    int num;
    int depth;
    struct Node *left,*right;
};
typedef struct Node BTNnode;
typedef struct Node *BTNnodeptr;
BTNnodeptr insertBST(BTNnodeptr p,int a,int depth);
void inorder(BTNnodeptr p);
int depth=1;
int main()
{
    BTNnodeptr root=NULL;
    int n,num;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        root=insertBST(root,num,depth);
    }
    inorder(root);
    return 0;
}
BTNnodeptr insertBST(BTNnodeptr p,int a,int depth)
{
    if(p==NULL)
    {
        p=(BTNnodeptr)malloc(sizeof(BTNnode));
        p->num=a;
        p->right=p->left=NULL;
        p->depth=depth;
    }
    else if(a<p->num)
    {
        p->left=insertBST(p->left,a,depth+1);//注意此处为p->left
    }
    else if(a>=p->num)
    {
        p->right=insertBST(p->right,a,depth+1);
    }
    return p;
}
void inorder(BTNnodeptr p)
{
    if(p!=NULL)
    {
    inorder(p->left);
        if(p->left==NULL&&p->right==NULL)
        {
            printf("%d %d\n",p->num,p->depth);
        }
    inorder(p->right);
    }
}


