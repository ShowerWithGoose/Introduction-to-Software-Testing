#include<stdio.h>
#include<stdlib.h>
typedef struct position{
		int x, y;
	} position;
	typedef struct line{
		position v1, v2;
		struct line *link;
	} line, *LinkList;
int main()
{
	LinkList p, q, r, list = NULL;
	position start;
	int n, i, j, x1, x2, y1, y2, len, len_max = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)	//生成链表 
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		p = (LinkList)malloc(sizeof(line));
		p->link = NULL;
		if(x1 > x2)
		{
			p->v1.x = x2;
			p->v1.y = y2;
			p->v2.x = x1;
			p->v2.y = y1;
		}
		else
		{
			p->v1.x = x1;
			p->v1.y = y1;
			p->v2.x = x2;
			p->v2.y = y2;
		}
		if(list == NULL)
			list = p;
		else
			r->link = p;
		r = p;
	}
	for(p = list; p != NULL; len = 1, p = p->link)	//连线并删除已连线线段 
	{
		for(r = p, q = r->link; q != NULL; q = r->link)
		{
			if(p->v1.x == q->v1.x && p->v1.y == q->v1.y)
			{
				if(p->v2.x > q->v2.x)
					p->v1 = q->v2;
				else
				{
					p->v1 = p->v2;
					p->v2 = q->v2;
				}
				r->link = q->link;
				free(q);
				len++;
				r = p;
			}
			else if(p->v2.x == q->v2.x && p->v2.y == q->v2.y)
			{
				if(p->v1.x > q->v1.x)
				{
					p->v1 = q->v1;
					p->v2 = p->v1;
				}
				else
					p->v2 = q->v1;
				r->link = q->link;
				free(q);
				len++;
				r = p;
			}
			else if(p->v1.x == q->v2.x && p->v1.y == q->v2.y)
			{
				p->v1 = q->v1;
				r->link = q->link;
				free(q);
				len++;
				r = p;
			}
			else if(p->v2.x == q->v1.x && p->v2.y == q->v1.y)
			{
				p->v2 = q->v2;
				r->link = q->link;
				free(q);
				len++;
				r = p;
			}
			else
				r = r->link;
		}
		if(len > len_max)
		{
			len_max = len;
			start = p->v1;
		}
	}
	printf("%d %d %d", len_max, start.x, start.y);
	return 0;
}

