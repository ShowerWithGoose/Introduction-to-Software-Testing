#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int element;
	struct node *llink;
	struct node *rlink;
} tnode;
void insertt(int);
void peek(tnode*, int);
tnode *root = NULL;
int main()
{
	int a, n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		insertt(a);
	}
	peek(root, 1);
}
void insertt(int newelement)
{
	tnode *p = (tnode*)malloc(sizeof(tnode));
	p->element = newelement;
	p->llink = p->rlink = NULL;
	if(root == 0)
	{
		root = p;
		return;
	}
	tnode *temp = root;
	int flag = 0;
	while(flag == 0)
	{
		if(newelement < temp->element)
		{
			if(temp->llink)
			temp = temp->llink;
			else
			temp->llink = p, flag = 1;
		}
		else
		{
			if(temp->rlink)
			temp = temp->rlink;
			else
			temp->rlink = p, flag = 1;
		}
	}
}
void peek(tnode *t, int high)
{
	if(t == 0) return;
	if(t->llink == 0 && t->rlink == 0)
	{
		printf("%d %d\n", t->element, high);
		return;
	}
	peek(t->llink, high + 1); 
	peek(t->rlink, high + 1);
}

