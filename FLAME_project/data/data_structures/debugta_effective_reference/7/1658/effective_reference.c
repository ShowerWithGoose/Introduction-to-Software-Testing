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
tnode *list = NULL;
int main()
{
	int temp, n;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &temp);
		insertt(temp);
	}
	peek(list, 1);
}
void insertt(int newelement)
{
	tnode *p = (tnode*)malloc(sizeof(tnode));
	p->element = newelement;
	p->llink = p->rlink = NULL;
	if(list == 0)
	{
		list = p;
		return;
	}
	tnode *find = list;
	int flag = 0;
	while(flag == 0)
	{
		if(newelement < find->element)
		{
			if(find->llink)
			find = find->llink;
			else
			find->llink = p, flag = 1;
		}
		else
		{
			if(find->rlink)
			find = find->rlink;
			else
			find->rlink = p, flag = 1;
		}
	}
}
void peek(tnode *link, int floor)
{
	if(link == 0) return;
	if(link->llink == 0 && link->rlink == 0)
	{
		printf("%d %d\n", link->element, floor);
		return;
	}
	peek(link->llink, floor + 1); 
	peek(link->rlink, floor + 1);
}

