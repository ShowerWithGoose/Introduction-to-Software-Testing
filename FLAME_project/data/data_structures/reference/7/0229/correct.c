#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

struct Tree
{  
    int num;
    int high;
    struct Tree *rchild;
	struct Tree *lchild;
};
typedef struct Tree *mood;
mood tree,one,two;

int n;
int i,j,k;

mood creat_bst(int n);
mood print_tree(mood tree);

int main()
{
    scanf("%d", &n);
    tree=creat_bst(n);
    print_tree(tree);
    return 0;
}

mood creat_bst(int n)
{
    int dep=0;
    for (i=0;i<n;i++)
    {
        one=(mood)malloc(sizeof(mood));
        one->lchild=one->rchild=NULL;
        scanf("%d",&one->num);
        if (tree==NULL)
        {
            one->high=1;
            tree=two=one;
            dep=tree->high;
            continue;
        }
        else
        {
            for(j=0;j<dep+1;j++)
            {
                one->high=two->high;
                if(one->num<two->num&&two->lchild==NULL)
                {
                    two=two->lchild=one;
                    two->high++;
                    break;
                }
                else if(one->num<two->num&&two->lchild!=NULL)
                    two=two->lchild;
                else if(one->num>=two->num&&two->rchild==NULL)
                {
                    two=two->rchild=one;
                    two->high++;
                    break;
                }
                else if(one->num>=two->num&&two->rchild!=NULL)
                    two=two->rchild;
            }
            dep=one->high;
        }
        two=tree;
    }
    return tree;
}

mood print_tree(mood tree)
{
    if (tree==NULL)
        return NULL;
    if (tree->lchild==NULL&&tree->rchild==NULL)
    {
        printf("%d %d\n",tree->num,tree->high);
    }
    print_tree(tree->lchild);
    print_tree(tree->rchild);
    return NULL;
}



