#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;
struct node
{
    Datatype height;
    Datatype data;
    struct node *left, *right;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr root=NULL;
int h;

BTNodeptr insertBST(BTNodeptr p, Datatype item) //树根结点、插入元素
{
    h++;
    if(p == NULL)
    {
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->height=h;
        p->left = p->right = NULL;
    }
    else if( item < p->data)
        p->left = insertBST(p->left, item);
    else if( item >= p->data)
        p->right = insertBST(p->right,item);
    // else
    //     do-something;   //树中存在该元素
    return p;
}
void visit(BTNodeptr t)
{
    if(t->left==NULL && t->right==NULL)
        printf("%d %d\n",t->data,t->height);
    return;
}
void inorder(BTNodeptr t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        visit(t);   /* 访问t指向结点 */
        inorder(t->right);
    }
}


int main()
{
    int n,item;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&item);
        h=0;
        root=insertBST(root,item);  //调用递归插入算法
    }
    inorder(root);
    return 0;
}
