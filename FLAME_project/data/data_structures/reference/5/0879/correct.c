#include <stdio.h>
#include <stdlib.h>
struct fun
{
	int xishu;
	int exp;
	struct fun *link;
}; 
struct fun *fsum(struct fun*, struct fun*);
int main()
{
	struct fun *p1 = NULL, *p2 = NULL, *ans = NULL;
	while(1)
	{
		int x, e;
		scanf("%d %d", &x, &e);
		struct fun *temp = (struct fun*)malloc(sizeof(struct fun));
		temp->exp = e;
		temp->xishu = x;
		temp->link = NULL;
		p1 = fsum(p1, temp);
		if(getchar() == '\n')
		{
			break;
		}
	}
	int x, e;
	while(scanf("%d%d", &x, &e) != EOF)
	{
		struct fun *temp = (struct fun*)malloc(sizeof(struct fun));
		temp->exp = e;
		temp->xishu = x;
		temp->link = NULL;
		p2 = fsum(p2, temp);
	}
	struct fun *t1 = p1, *t2 = p2;
	while(t1 != NULL)
	{
		t2 = p2;
		while(t2 != NULL)
		{
			struct fun *tem;
			tem = (struct fun*)malloc(sizeof(struct fun));
			tem->exp = t1->exp + t2->exp;
			tem->xishu = t1->xishu * t2->xishu;
			tem->link = NULL;
			ans = fsum(ans, tem);
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t1 = ans;
	while(t1 != NULL)
	{
		if(t1->xishu != 0)
		{
			printf("%d %d ", t1->xishu, t1->exp);
		}
		t1 = t1->link; 
	}
	return 0;
}
struct fun *fsum(struct fun *lon, struct fun *single)
{
	if(lon == NULL)
	{
		return single;
	}
	if(lon->exp < single->exp)
	{
		single->link = lon;
		return single;
	}
	if(lon->exp == single->exp)
	{
		lon->xishu += single->xishu;
		free(single);
		return lon; 
	}
	struct fun *p = lon;
	while(1)
	{
		if(p->link == NULL)
		{
			p->link = single;
			return lon;
		}
		if(p->link->exp < single->exp)
		{
			single->link = p->link;
			p->link = single;
			return lon; 
		}
		if(p->link->exp == single->exp)
		{
			p->link->xishu += single->xishu;
			free(single);
			return lon;
		}
		p = p->link;
	}
};

