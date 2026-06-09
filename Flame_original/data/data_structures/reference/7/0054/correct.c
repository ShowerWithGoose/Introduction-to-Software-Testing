#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bstree
{
    struct bstree *lchild;
    int a;
    int h;
    struct bstree *rchild;
};
typedef struct bstree *bst;
bst tree, one, curr;
int n;
int i, j, k;
bst creat(int n)
{
    int deep=0;
    for (i=0;i<n;i++)
    {
        one=(bst)malloc(sizeof(bst));
        one->lchild=one->rchild=NULL;
        scanf("%d",&one->a);
        if (tree==NULL)
        {
            one->h=1;
            tree=curr = one;
            deep=tree->h;
            continue;
        }
        else
        {
            for (j=0;j<deep+1;j++)
            {
                one->h=curr->h;
                if (one->a<curr->a&&curr->lchild==NULL)
                {
                    curr=curr->lchild=one;
                    curr->h++;
                    break;
                }
                else if(one->a<curr->a&&curr->lchild!=NULL)
                    curr = curr->lchild;
                else if(one->a>=curr->a&&curr->rchild==NULL)
                {
                    curr=curr->rchild=one;
                    curr->h++;
                    break;
                }
                else if(one->a>=curr->a&&curr->rchild!= NULL)
                    curr=curr->rchild;
            }
            deep=one->h;
        }
        curr=tree;
    }
    return tree;
}

bst print_tree(bst tree)
{
    if (tree==NULL)
        return NULL;
    if (tree->lchild==NULL&&tree->rchild==NULL)
    {
        printf("%d %d\n",tree->a,tree->h);
    }
    print_tree(tree->lchild);
    print_tree(tree->rchild);
    return NULL;
}

int main()
{
    scanf("%d", &n);
    tree=creat(n);
    print_tree(tree);
    return 0;
}






