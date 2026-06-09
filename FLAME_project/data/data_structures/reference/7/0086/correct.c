#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
struct st
{
	int content;
	struct st* llink, * rlink;
	int place;
}*root;
int date,i;
struct st* insert(struct st* p)
{
	if (p == NULL)
	{
		p = (struct st*)malloc(sizeof(struct st));
		p->content = date;
		p->place = i + 1;
		p->llink = p->rlink = NULL;
	}
	else if (date < p->content)
		i++,p->llink=insert(p->llink);
	else
		i++,p->rlink=insert(p->rlink);
	return p;
}
void bianli(struct st *p)
{
	if (p != NULL)
	{
		bianli(p->llink);
		if (p->llink == NULL && p->rlink == NULL)
			printf("%d %d\n", p->content,p->place);
		bianli(p->rlink);
	}
}
int main()
{
	root = NULL;
	int n;
	scanf("%d", &n);
	for (; n > 0; n--)
	{
		scanf("%d", &date);
		i = 0, root = insert(root);
	}
	bianli(root);
}
