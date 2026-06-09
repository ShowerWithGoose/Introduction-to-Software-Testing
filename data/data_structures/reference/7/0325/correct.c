#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct BSTree
{
    struct BSTree *lchild;
    int num;
    int high;
    struct BSTree *rchild;
};
typedef struct BSTree *bst;
bst tree, one, curr;
int n; 
int i, j, k;



bst print_tree(bst tree)
{
    if (tree == NULL)
        return NULL;
    if (tree->lchild == NULL && tree->rchild == NULL)
    {
        printf("%d %d\n", tree->num, tree->high);
    }
    print_tree(tree->lchild);
    print_tree(tree->rchild);
    return NULL;
}

int main()
{
    scanf("%d", &n);
    
    int dep = 0;
	    for (i = 0; i < n; i++)
	    {
	        one = (bst)malloc(sizeof(bst));
	        one->lchild = one->rchild = NULL;
	        scanf("%d", &one->num);
	        if (tree == NULL)
	        {
	            one->high = 1;
	            tree = curr = one;
	            dep = tree->high;
	            continue;
	        }
	        else
	        {
	            for (j = 0; j < dep + 1; j++)
	            {
	                one->high = curr->high;
	                if (one->num < curr->num && curr->lchild == NULL)
	                {
	                    curr = curr->lchild = one;
	                    curr->high++;
	                    break;
	                }
	                else if (one->num < curr->num && curr->lchild != NULL)
	                    curr = curr->lchild;
	                else if (one->num >= curr->num && curr->rchild == NULL)
	                {
	                    curr = curr->rchild = one;
	                    curr->high++;
	                    break;
	                }
	                else if (one->num >= curr->num && curr->rchild != NULL)
	                    curr = curr->rchild;
	            }
	            dep = one->high;
	        }
	        curr = tree;
	    }
    print_tree(tree);
    return 0;
}


