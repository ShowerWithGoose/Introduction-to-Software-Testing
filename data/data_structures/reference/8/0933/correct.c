#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct Edge{
	int num;
	struct Edge *next;
}edge;
struct vertex{
	edge *next;
	int num;
}ver[110];
int hash[110],verSum,edgeSum;
int team[110], head, tail;
void deepsh(struct vertex vert) {
	printf("%d ",vert.num);
	edge *pt = vert.next;
	hash[vert.num] = 1;
	while (pt != NULL) {
		if (hash[pt->num] != 1) {
			deepsh(ver[pt->num]);
		}
		pt = pt->next;
	}
	return;
}
void lensh(struct vertex vert) {
	printf("%d ",vert.num);
	edge *p = vert.next;
	while (p != NULL) {
		if (hash[p->num] != 1) {
			team[tail++] = p->num;
			hash[p->num] = 1;
		}
		p = p->next;
	}
	head++;
}
void insert(int from, int to) {
	ver[from].num = from;
	ver[to].num = to;
	edge *pr = ver[from].next;
	edge *ps;
	if (pr == NULL) {
		pr = (edge*)malloc(sizeof(edge));
	    pr->next = NULL, pr->num = to; 
	    ver[from].next = pr;
	} else {
		if (pr->num > to) {
			ps = (edge*)malloc(sizeof(edge));
			ps->next = ver[from].next, ps->num = to;
			ver[from].next = ps;
		} else {
			while (pr->next != NULL) {
			    if (pr->next->num > to) break;
			    pr = pr->next;
	        }
	        if (pr->num < to && pr->next == NULL) {
			    ps = (edge*)malloc(sizeof(edge));
			    pr->next = ps;
			    ps->next = NULL, ps->num = to;
		    } else {
			    ps = (edge*)malloc(sizeof(edge));
			    ps->next = pr->next, ps->num = to;
			    pr->next = ps;
		    }
		}
	}
}
int main()
{
	int i,from,to,key;
	edge *st;
	scanf("%d%d",&verSum,&edgeSum);
	for (i = 1; i <= edgeSum; ++i) {
		scanf("%d%d",&from,&to);
		insert(from,to);
		insert(to,from);
	}
	scanf("%d",&key);
    deepsh(ver[0]);
	printf("\n");
	for (i = 0; i < 110; ++i) hash[i] = 0;
	team[1] = ver[0].num, head = 1, tail = 2;
	hash[ver[0].num] = 1;
	while (head < tail) lensh(ver[team[head]]);
	printf("\n");
	for (i = 0; i < 110; ++i) hash[i] = 0;
	ver[key].next = NULL;
	for (i = 0; i < 110; ++i) {
		if (ver[i].next != NULL && ver[i].next->num == key)
		    ver[i].next = ver[i].next->next;
		else if (ver[i].next != NULL) {
			st = ver[i].next;
			while(st != NULL) {
				if (st->next != NULL)
				if (st->next->num == key) {
					st->next = st->next->next;
					break;
				}
				st = st->next;
			}
		}
	}
	deepsh(ver[0]);
	printf("\n");
	for (i = 0; i < 110; ++i) hash[i] = team[i] = 0;
	head = 1, tail = 2;
	hash[ver[0].num] = 1;
	while (head < tail) lensh(ver[team[head]]);
	return 0;
}




