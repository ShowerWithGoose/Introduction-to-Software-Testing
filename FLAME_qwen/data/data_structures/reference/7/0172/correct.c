#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int count;
	struct node*lchild;
	struct node*rchild;
}BTNode,*BTNodeptr;
BTNodeptr T;
int num;
 
BTNodeptr  insertBST(BTNodeptr p, int item)
{ 
    if(p == NULL)
	{
        p = (BTNodeptr)malloc(sizeof(BTNode)); 
        p->count = item;
        p->lchild = p->rchild = NULL;
    } 
    else if( item < p->count)
        p->lchild = insertBST(p->lchild, item);
    else if( item >= p->count)
       	p->rchild = insertBST(p->rchild,item);
    return p;
}
 
int searchBST(BTNodeptr target)
{
    BTNodeptr p = T;
    int n=1;
    while (p != NULL) 
    {
        if (target == p)
            break;//查找结束
        if (target->count >= p->count) 
        {
            n++;
            p = p->rchild;//将p移到右子树的结点
        }
        else 
        {
        	n++;
            p = p->lchild;//将p移到左子树的根结点
        }
    }
    return n;
}

void preorder(BTNodeptr T)
{
	//BTNodeptr p=T;
    if (T != NULL)
    {
        if(T->lchild==NULL&&T->rchild==NULL)
        	printf("%d %d\n",T->count,searchBST(T));
        preorder(T->lchild);
        preorder(T->rchild);
    }
}

int main()
{
	int i;
	int item;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&item);
		T=insertBST(T,item);
	}
	preorder(T);
	//printf("\n%d",T->count);
	return 0;
}

