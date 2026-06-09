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
        if(p->number<a->number) // @@ The comparison logic is inverted relative to the BST definition in the reference (Left < Root, Right >= Root). Here, if p->number < a->number, it goes left, which implies Left < Parent. However, the recursive call passes 'a' (the parent) instead of the child node, leading to infinite recursion or incorrect traversal. Also, the base case for insertion is missing proper handling of NULL children in the recursive step.
        {
            if(a->left==NULL)
            {
                a->left=p;
                p->height=a->height+1;
            }
            else
            {
                a=a->left; // @@ This assignment only changes the local pointer 'a'. It does not correctly pass the child node to the recursive call in a way that maintains state for insertion. More critically, the function lacks a return or proper recursive structure to handle the traversal down the tree. It should call tree_create(a->left) directly.
                tree_create(a); // @@ Infinite recursion or stack overflow because 'a' is updated locally but the logic doesn't properly descend. If a->left was not NULL, it updates a to a->left and calls tree_create(a). This looks like it attempts to traverse, but the initial check `if(root==NULL)` is only for the very first node. For subsequent nodes, if we go left, we update `a` and recurse. However, the condition `if(p->number < a->number)` is checked against the *current* node `a`. If we move to `a->left`, we need to compare again. The logic here is flawed because it doesn't handle the case where the tree is not empty correctly in a recursive manner without losing context or causing infinite loops if the structure isn't perfectly balanced or if pointers aren't updated correctly in the caller. Actually, the main issue is that `tree_create` is called with `now` (which is root) from main. Inside, if it goes to else, it checks conditions. If it recurses, it passes `a` (which has been updated to child). This part *might* work logically for traversal IF the base case was handled, but the real crash comes from `tree_clean`.
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
                a=a->right; // @@ Same issue as above: local pointer update doesn't fix the recursive descent logic properly if the function signature doesn't support returning/updating parent links, but here it's just traversal. The bigger issue is likely in memory management or the clean function.
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
            a=a->left; // @@ Logic Error: This assumes left child exists if either left or right exists. If left is NULL but right is not, a becomes NULL.
            p=a->right; // @@ Runtime Error: If a->left was NULL, 'a' is now NULL. Accessing a->right causes a Segmentation Fault (Runtime Error).
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