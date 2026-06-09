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
BTNnodeptr insertBST(BTNnodeptr p,int a,int deep);
void inorder(BTNnodeptr p);
int deep=1;
int main()
{
    BTNnodeptr root=NULL;
    int N,m;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&m);
        root=insertBST(root,m,deep);
    }
    inorder(root);
    return 0;
}
BTNnodeptr insertBST(BTNnodeptr p,int a,int deep)
{
    if(p==NULL)
    {
        p=(BTNnodeptr)malloc(sizeof(BTNnode));
        p->num=a;
        p->right=p->left=NULL;
        p->depth=deep;
    }
    else if(a<p->num)
    {
        p->left=insertBST(p->left,a,deep+1);//注意此处为p->left
    }
    else if(a>=p->num)
    {
        p->right=insertBST(p->right,a,deep+1);
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


