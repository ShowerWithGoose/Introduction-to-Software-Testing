#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree
{
    int number;
    struct tree *right,*left;
    int height;
}*root,*p,*now;
struct TREE
{
    int NUMBER;
    int HEIGHT;
    struct TREE *next;
}*STR,*q,*head;
void tree_create(struct tree *a)//创造树
{
    if(root==NULL)
        root=p;
    else
    {
        if(p->number<a->number)
        {
            if(a->left==NULL)
            {
                a->left=p;
                p->height=a->height+1;
            }
            else
            {
                a=a->left;
                tree_create(a);
            }
        }
        else if(p->number>=a->number)
        {
            if(a->right==NULL)
            {
                a->right=p;
                p->height=a->height+1;
            }
            else
            {
                a=a->right;
                tree_create(a);
            }
        }
    }
}
void tree_find(struct tree *a)//找到所有的叶子结点
{
    if(a!=NULL)
    {
        if(a->left==NULL&&a->right==NULL)
        {
            q=(struct TREE*)malloc(sizeof(struct TREE));
            q->HEIGHT=a->height;
            q->NUMBER=a->number;
            q->next=NULL;
            if(head==NULL)
                head=STR=q;
            else
            {
                STR->next=q;
                STR=STR->next;
            }
        }
        else
        {
            tree_find(a->left);
            tree_find(a->right);
        }
    }
}
void tree_clean(struct tree *a)
{
    if(a!=NULL)
    {
        now=a;
        if(a->left!=NULL||a->right!=NULL)
        {
            a=a->left;
            p=a->right; // @@ [Error: p is a global pointer used for new nodes, but here it is reassigned to a->right, corrupting the tree structure and causing undefined behavior. Additionally, the cleanup logic is flawed and does not properly free all nodes.]
            free(now);
            tree_clean(a);
            tree_clean(p);
        }
    }
}
int main()
{
    int n,m,i;
    root=now=p=NULL;
    STR=head=q=NULL;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        p=(struct tree*)malloc(sizeof(struct tree));
        p->number=m;
        p->right=p->left=NULL;
        p->height=1;
        now=root;
        tree_create(now);
    }
    now=root;
    tree_find(now);
    STR=NULL;
    for(q=head; q!=NULL; STR=q,q=q->next)
    {
        printf("%d %d\n",q->NUMBER,q->HEIGHT);
        if(STR!=NULL)
            free(STR);
    }
    free(STR);
    tree_clean(root);
    return 0;
}