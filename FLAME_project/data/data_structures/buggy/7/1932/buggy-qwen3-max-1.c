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
        p->height=1; // @@ [The height of the root should be 1, but when inserting non-root nodes, their height is set correctly only if parent's height is already set. However, the main issue is that when root is NULL, 'now' is passed as NULL to tree_create, causing undefined behavior in recursive calls.]
        now=root;
        tree_create(now); // @@ [When root is NULL (first insertion), 'now' is NULL, and tree_create is called with a=NULL. Inside tree_create, the condition 'if(root==NULL)' correctly sets root=p, but for subsequent insertions, passing 'now=root' is correct. However, the real critical error is in tree_clean and memory management leading to runtime error. But more importantly, the traversal order in tree_find is preorder, not left-to-right (inorder) as required. The problem asks for leaf nodes "from left to right", which means inorder traversal, but tree_find uses preorder (visit node, then left, then right). This causes wrong output order. However, the test case shows missing outputs entirely, suggesting a deeper issue.]

        // Actually, looking at the expected vs buggy output: Buggy output is empty. So the program likely crashes before printing.
        // The crash is likely in tree_clean or in the final freeing loop.

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
    free(STR); // @@ [If head is NULL (no leaves found), then STR remains NULL, and this free(STR) is safe. But if head is not NULL, then after the loop, STR points to the last freed node? Actually, the loop frees all nodes except the last one. Then free(STR) frees the last one. But if there are no leaves, head is NULL, loop doesn't run, STR is still NULL from initialization, so free(NULL) is safe. So this may not be the issue.]

    tree_clean(root); // @@ [This function has serious flaws: it accesses 'a->right' after setting 'a = a->left', and if a->left is NULL, then 'a' becomes NULL and 'a->right' is invalid. Also, it doesn't handle the case when a node has only one child. Moreover, it doesn't free leaf nodes at all because the condition is 'if(a->left!=NULL || a->right!=NULL)', so leaf nodes are never freed, but more critically, when a node has only a left child, after 'a = a->left', then 'p = a->right' is okay, but if a node has only a right child, then 'a = a->left' sets a to NULL, and then 'p = a->right' dereferences NULL -> Runtime Error.]

    return 0;
}