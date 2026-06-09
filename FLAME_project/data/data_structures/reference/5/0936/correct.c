#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int x=0,y=0;
struct Zhishu {
	int xs;
	int zs;
	struct Zhishu *next;
}*diyi = NULL, *dier = NULL, *jieguo = NULL;
void insertword(struct Zhishu *p, struct Zhishu *q,struct Zhishu *t) {
	if (jieguo == NULL) {
		jieguo = t;
	} else if (q == NULL) {
		t->next = jieguo;
		jieguo = t; //保护头指针
	} else {
		q->next = t;
		t->next = p;
	}
}
void searchword(struct Zhishu *t) {
	struct Zhishu *p, *q = NULL;
	for (p = jieguo; p != NULL; q = p, p = p->next) {
		if (t->zs==p->zs) {
			p->xs+=t->xs;
			break;
		} else if (t->zs>p->zs) {
			insertword(p, q,t);
			break;
		}
	}
	if(p==NULL){
		insertword(p, q,t);
	}
}
int main() {
	struct Zhishu *p, *q, *t;
	int m, n;
	char c;
	while (scanf("%d %d%c", &m, &n, &c) != 0) {
		x++;
		p = (struct Zhishu *)malloc(sizeof(struct Zhishu));
		p->xs = m;
		p->zs = n;
		p->next = NULL;
		if (diyi == NULL) {
			diyi = q = p;
		} else {
			q->next = p;
			q = q->next;
		}
		if (c == '\n') {
			break;
		}
	}
	while (scanf("%d %d%c", &m, &n, &c) != 0) {
		y++;
		p = (struct Zhishu *)malloc(sizeof(struct Zhishu));
		p->xs = m;
		p->zs = n;
		p->next = NULL;
		if (dier == NULL) {
			dier = q = p;
		} else {
			q->next = p;
			q = q->next;
		}
		if (c == '\n') {
			break;
		}
	}
	p=diyi;
    for(int i=0;i<x;i++){
    	q=dier;
		for(int j=0;j<y;j++){
			t=(struct Zhishu *)malloc(sizeof(struct Zhishu));
			t->xs=(p->xs)*(q->xs);
			t->zs=(p->zs)+(q->zs);
			t->next=NULL;
			searchword(t);
			q=q->next;
		}
		p=p->next;
	}
	for(p=jieguo;p!=NULL;p=p->next){
		printf("%d %d ",p->xs,p->zs);
	}
	return 0;
}

