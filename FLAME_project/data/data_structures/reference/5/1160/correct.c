#include <stdio.h>
#include <stdlib.h>
#define ElemType int

typedef struct node{
	ElemType cor;
	ElemType exp;
	struct node *link;
} LNode;

LNode *CREATE(int n) // Create a link list with a head node which just hold the first place.
{
	if (n < 0)
	{
		printf("LNode CREAT Error: number of nodes is too small.");
		return NULL;
	}
	LNode *head, *node, *tail;
	head = (LNode*)malloc(sizeof(LNode));
	tail = head;
	for (int i = 0; i < n; i++)
	{
		node = (LNode*)malloc(sizeof(LNode));
		tail->link = node;
		tail = node;
	}
	tail->link = NULL;
	return head;
}

LNode *GET_LAST_NODE(LNode *list)
{
	LNode *step = list;
	while (step->link != NULL)
	{
		step = step->link;
	}
	return step;
}

LNode *CREATE_NODE(ElemType new_cor, ElemType new_exp)
{
	LNode *new_node = (LNode*)malloc(sizeof(LNode));
	new_node->cor = new_cor;
	new_node->exp = new_exp;
	new_node->link = NULL;
	return new_node;
}

LNode *APPEND_NODE(LNode *list, ElemType new_cor, ElemType new_exp, LNode *tail) // pass NULL if tail is unkown
{
	if (tail == NULL)
	{
		tail = GET_LAST_NODE(list);
	}
	LNode *new_node = CREATE_NODE(new_cor, new_exp);
	tail->link = new_node;
	return new_node;
}

void ADD_NODE_BETWEEN(LNode *list, ElemType new_cor, ElemType new_exp)
{
	LNode *step = list->link;
	LNode *follow = list;
	for (int i = 0; step != NULL && step->exp >= new_exp; i++)
	{
		step = step->link;
		follow = follow->link;
	}
	if (follow->exp == new_exp)
	{
		follow->cor += new_cor;
	}
	else
	{
		LNode *new_node = CREATE_NODE(new_cor, new_exp);
		follow->link = new_node;
		new_node->link = step;
	}
}

void DELETE(LNode *list, int n)
{
	LNode *step = list;
	LNode *next = step->link;
	for (int i = 0; i < n && next != NULL; i++)
	{
		step = step->link;
		next = next->link;
	}
	if (step == NULL)
	{
		printf("LNode DELETE Error: no such node. Index out of range.");
	}
	step->link = next->link;
	free(next);
}

int main()
{
	LNode *fx = CREATE(0);
	LNode *gx = CREATE(0);
	LNode *hx = CREATE(0);
	int f = 0;
	int g = 0;
	int cor; // coefficient
	int exp; // exponent
	LNode *tail = fx;
	while (1)
	{
		scanf("%d%d",&cor, &exp);
		tail = APPEND_NODE(fx, cor, exp, tail);
		f++;
		if (getchar() == '\n')
		{
			break;
		}
	}
	tail = gx;
	while (1)
	{
		scanf("%d%d",&cor, &exp);
		tail = APPEND_NODE(gx, cor, exp, tail);
		g++;
		if (getchar() == '\n')
		{
			break;
		}
	}
	for (LNode *ff = fx->link; ff != NULL; ff = ff->link)
	{
		for (LNode *gg = gx->link; gg != NULL; gg = gg->link)
		{
			int cor = ff->cor * gg->cor;
			int exp = ff->exp + gg->exp;
			ADD_NODE_BETWEEN(hx, cor, exp);
		}
	}
	for (LNode *hh = hx->link; hh != NULL; hh = hh->link)
	{
		if (hh->cor != 0)
		{
			printf("%d %d ",hh->cor,hh->exp);
		}
	}

	return 0;
}
