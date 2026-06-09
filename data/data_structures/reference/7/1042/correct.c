#include <stdio.h>
#include  <stdlib.h>
struct tree {
    int data;
    int hight;
    struct tree *left,*right;
};
typedef struct tree BTNode;
typedef struct tree *BTNodeptr;
void inorder(BTNodeptr );
BTNodeptr insertBST(BTNodeptr ,int );
int hight=0;
int main()
{
    int i=0,n,item;
    BTNodeptr root = NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        root = insertBST(root,item);
        hight=0;
    }
    inorder(root);
    return 0;
}
void inorder(BTNodeptr t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        if(t->left==NULL&&t->right==NULL)
        {
            printf("%d %d\n",t->data,t->hight);
        }
        inorder(t->right);
    }
}
BTNodeptr insertBST(BTNodeptr p,int item)
{
    if(p==NULL)
    {
        hight++;
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->left=p->right=NULL;
    }
    else if(item < p->data)
    {
        hight++;
        p->left = insertBST(p->left,item);
    }
    else if(item >= p->data)
    {
        hight++;
        p->right = insertBST(p->right,item);
    }
    else    hight++; //树中存在该元素
    p->hight=hight;
    return p;
}
/*int max(x,y) 
{ if(x >y)  return x; else return y; }
int  heightTree(BTNodeptr  p)
{
    if(p == NULL)
        return 0;
    else
        return 1 + max(heightTree(p->left), 
                                 heightTree(p->right));
 }     //计算树的高度
*/
