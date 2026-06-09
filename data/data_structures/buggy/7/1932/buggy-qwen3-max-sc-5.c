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
            p=a->right;
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
        tree_create(now); @@ [When root is NULL, 'now' is NULL and passed to tree_create. Inside tree_create, when root is NULL, it sets root=p correctly, but on subsequent calls when root is not NULL, the function uses the passed 'a' (which may be NULL if root was just set in previous iteration and now=root was done before insertion). Specifically, after first insertion, root != NULL, but 'now' is set to root before calling tree_create, which is okay. However, the real issue is that when root is NULL, tree_create is called with a = NULL, and then inside tree_create, the code accesses a->number (e.g., p->number < a->number) which dereferences NULL, causing undefined behavior (likely crash). This leads to runtime error, but the reported error is "gcc: not found", which is a compilation environment issue. However, given the context of logical errors causing failure on test cases, the actual bug is the NULL dereference in tree_create when a is NULL (i.e., when root is NULL, now=root=NULL is passed as 'a', and then a->number is accessed).]
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
    tree_clean(root); @@ [The tree_clean function has incorrect logic: it sets 'now=a', then if the node has children, it sets 'a=a->left' and 'p=a->right' (but if a->left is NULL, then a becomes NULL and p = NULL->right which is invalid). Also, it doesn't properly traverse and free all nodes. This can cause segmentation fault during cleanup, but more critically, the initial insertion logic already has a NULL dereference bug.]
    return 0;
}