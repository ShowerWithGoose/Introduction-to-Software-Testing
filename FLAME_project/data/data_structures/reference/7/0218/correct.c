/*#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
	int h;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr create(BTNodeptr t,int x,int hight)
{
	hight++;
	if(t==NULL)
	{
		t=(BTNodeptr)malloc(sizeof(BTNode));
		t->lchild=NULL;
		t->rchild=NULL;
		t->data=x;
		t->h=hight;
	}
	else if(x<t->data)
	{
		t->lchild=create(t->lchild,x,hight);
	}
	else if(x>=t->data)
	{
		t->rchild=create(t->rchild,x,hight);
	}
	return t;
}
void print(BTNodeptr t)
{
	if(t)
	{
		if(!(t->lchild)&&!(t->rchild))
		{
			printf("%d %d\n",t->data,t->h);
		}
		print(t->lchild);
		print(t->rchild);
	}
}
int main()
{
	int n,i,x,hight;
	BTNodeptr p=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		hight=0;
		p=create(p,x,hight);
	}
	print(p);
	return 0;
}*/


#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
	int h;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr p=NULL,q,r;
int hight;
BTNodeptr create(int x)
{
	r=(BTNodeptr)malloc(sizeof(BTNode));
    r->lchild=NULL;
    r->rchild=NULL;
	if(p==NULL)
	{
		p=r;
		p->data=x;
		p->h=1;
	}
    else
    {
    	hight=1;
    	q=p;
    	while(1)
    	{
    		if(x<q->data&&q->lchild==NULL)
    		{
    			q=q->lchild=r;
    			q->h=++hight;
    			q->data=x;
    			break;
			}
			else if(x>=q->data&&q->rchild==NULL)
			{
    		    q=q->rchild=r;
    			q->h=++hight;
    			q->data=x;
    			break;
			}
			else if(x<q->data&&q->lchild)
			{
				q=q->lchild;
				hight++;
			}
			else if(x>=q->data&&q->rchild)
			{
				q=q->rchild;
				hight++;
			}
		}
		
	}
	return p;
}
void print(BTNodeptr t)
{
	if(t)
	{
		if(!(t->lchild)&&!(t->rchild))
		{
			printf("%d %d\n",t->data,t->h);
		}
		print(t->lchild);
		print(t->rchild);
	}
}
int main()
{
	int n,i,x,hight;

	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		p=create(x);
	}
	print(p);
	return 0;
}
/*#include <stdio.h>
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
int n; // number, self_statistic;
int i, j, k;

bst creat_bst(int n)
{
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
    return tree;
}

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
    tree = creat_bst(n);
    print_tree(tree);
    return 0;
}*/

/*#include <stdio.h>
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
int n; // number, self_statistic;
int i, j, k;

bst creat_bst(int n)
{
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
    return tree;
}

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
    tree = creat_bst(n);
    print_tree(tree);
    return 0;
}*/



