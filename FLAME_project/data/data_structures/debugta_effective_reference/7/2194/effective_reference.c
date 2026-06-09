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
int h;
BTNodeptr insertBST(BTNodeptr t, int item);
void VISIT(BTNodeptr t);
void preorder(BTNodeptr tree);
int main()
{
    int i, item;
    int n;
    scanf("%d",&n);
	BTNodeptr root=NULL;
    for(i=0; i<n; i++){ //构造一个有10个元素的BST树
         scanf("%d", &item);
         h = 0;
		 root = insertBST(root, item);
     }
    preorder(root);
	return 0;
}
void preorder(BTNodeptr tree)
{
	if(tree!=NULL)
	{
		VISIT(tree);
		preorder(tree->lchild);
		preorder(tree->rchild);
	}
 } 
BTNodeptr  insertBST(BTNodeptr t, int item)
{	
	h++;
    if(t == NULL){
        t = (BTNodeptr)malloc(sizeof(BTNode));
        t->data = item;
        t->lchild = t->rchild = NULL;
    	t->depth = h;
	} 
    else if( item < t->data)
        t->lchild = insertBST(t->lchild, item);
    else if( item >= t->data)
       t->rchild = insertBST(t->rchild,item);
    return t;
}

void VISIT(BTNodeptr t)
{
	if(t->lchild==NULL && t->rchild==NULL)
	printf("%d %d\n",t->data,t->depth);
}

