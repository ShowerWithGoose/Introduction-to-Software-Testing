#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
struct node {
    int data;
    int depth;
	struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
int num;
BTNodeptr insertBST(BTNodeptr p, int item);
void VISIT(BTNodeptr p);
void preorder(BTNodeptr t);
int main()
{
    int i, item;
    int N;
    scanf("%d",&N);
	BTNodeptr root=NULL;
    for(i=0; i<N; i++){ //构造一个有10个元素的BST树
         scanf("%d", &item);
         num = 0;
		 root = insertBST(root, item);
     }
    preorder(root);
	return 0;
}
void preorder(BTNodeptr t)
{
	if(t!=NULL)
	{
		VISIT(t);
		preorder(t->lchild);
		preorder(t->rchild);
	}
 } 
BTNodeptr  insertBST(BTNodeptr p, int item)
{	
	num++;
    if(p == NULL){
        p = (BTNodeptr)malloc(sizeof(BTNode));
        p->data = item;
        p->lchild = p->rchild = NULL;
    	p->depth = num;
	} 
    else if( item < p->data)
        p->lchild = insertBST(p->lchild, item);
    else if( item >= p->data)
       p->rchild = insertBST(p->rchild,item);
    return p;
}

void VISIT(BTNodeptr p)
{
	if(p->lchild==NULL && p->rchild==NULL)
	printf("%d %d\n",p->data,p->depth);
}

