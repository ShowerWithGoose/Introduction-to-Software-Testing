#include<stdio.h>
struct node{
    int num;
    int count;
    struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
int i=1;
BTNodeptr insertBST(BTNodeptr p,int n)
{
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->num=n;
        p->count=i;
        p->left=p->right=NULL;
        i=1;
    }
    else if(n<p->num)
    {
        i++;
        p->left=insertBST(p->left,n);
    }
    else if(n>=p->num)
    {
        i++;
        p->right=insertBST(p->right,n);
    }
    return p;
}
void inorder(BTNodeptr p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        if(p->left==NULL&&p->right==NULL)
            printf("%d %d\n",p->num,p->count);
        inorder(p->right);
    }
}
int main()
{
    BTNodeptr T;
    T=NULL;
    int m,j,n;
    scanf("%d",&m);
    for(j=0;j<m;j++)
    {
        scanf("%d",&n);
        T=insertBST(T,n);
    }
    inorder(T);
    return 0;
}

