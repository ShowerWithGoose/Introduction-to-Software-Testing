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
        if(p->number<a->number) // @@ The comparison logic is inverted relative to the BST definition in the reference (Left < Root, Right >= Root). Here, if p->number < a->number, it goes left, which implies Left < Parent. However, the recursive call passes 'a' (the parent) instead of the child node, leading to infinite recursion or incorrect traversal. Also, the base case for insertion is missing proper handling of the recursive step's argument.
        {
            if(a->left==NULL)
            {
                a->left=p;
                p->height=a->height+1;
            }
            else
            {
                a=a->left; // @@ This assignment only changes the local pointer 'a'. It does not correctly pass the new node to the recursive call in a way that maintains state or updates the tree structure properly in the next recursive step because the function signature expects the current node to check against. More critically, the recursion logic is flawed: it should recurse on the child, but the condition checks against 'a' again in the next call without updating the context correctly for insertion.
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
                a=a->right; // @@ Same issue as above: local pointer update doesn't fix the recursive logic flaw. The function relies on global 'p' but traverses using 'a'. The main issue causing Runtime Error is likely stack overflow due to infinite recursion because 'a' is updated locally but the recursive call uses the updated 'a', yet the termination condition depends on 'a->left/right' being NULL. If the tree grows, this might work logically for traversal, BUT:
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
            a=a->left; // @@ Logic error: assumes left child exists if either child exists. If left is NULL but right is not, this sets a to NULL.
            p=a->right; // @@ Dereferencing 'a' when it could be NULL (if original a->left was NULL) causes Segmentation Fault (Runtime Error).
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
        tree_create(now); // @@ When root is NULL, tree_create sets root=p. However, in subsequent calls, 'now' is passed. If 'now' is NULL (which it isn't after first insert), it would fail. But the main issue is inside tree_create: the recursive calls do not return or break, leading to potential infinite loops or stack overflows if the logic doesn't hit a NULL child quickly. Actually, the critical Runtime Error comes from tree_clean.
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
    tree_clean(root); // @@ This function causes Segmentation Fault due to dereferencing NULL pointer when a node has only a right child.
    return 0;
}