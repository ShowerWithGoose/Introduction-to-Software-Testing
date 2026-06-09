#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
struct node{
    int data;
    int high;
    struct node *lchild,*rchild;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

BTNodeptr insert_bst(BTNodeptr p,int item,int height)//插入元素 ，记录深度 
{
	height++;
    if(p==NULL)
    {
        p=(BTNodeptr)malloc(sizeof(BTNode));
        p->data=item;
        p->high=height;
        p->lchild=p->rchild=NULL;
    }
    else if(item<p->data)
    {
        p->lchild=insert_bst(p->lchild,item,height);
    }
    else if(item>=p->data)
    {
        p->rchild=insert_bst(p->rchild,item,height);
    }
    return p;
}

void print_bst(BTNodeptr t){
	if(t!=NULL){
		if(t->lchild==NULL&&t->rchild==NULL){
			printf("%d %d\n",t->data,t->high);
		}
		print_bst(t->lchild);
		print_bst(t->rchild);
	}
}



int main()
{
    int n,item,height=0;
    int i;
    BTNodeptr s=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&item);
        s=insert_bst(s,item,height);
    }
    print_bst(s);
    return 0;
}



