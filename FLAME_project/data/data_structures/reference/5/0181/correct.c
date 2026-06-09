#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node {
	int xishu;
	int zhishu;
	struct node* link;
} node;
char xishu[10], zhishu[10], p;

void printlist(node* head) {
	node*p = head->link;
	while (p->link != NULL) {
		printf("%d %d ", p->xishu, p->zhishu);
		p = p->link;
	}
	printf("%d %d\n", p->xishu, p->zhishu);
	return;
}
void deletenode(node*p, node*q) {
	p->link = q->link;
	free(q);
	return;
}
void addnode(node*list, int xishu, int zhishu) {
	node*p, *q, *ad;
	p = list;
	q = list->link;
	while (q != NULL) {
		if (q->zhishu == zhishu) {
			q->xishu += xishu;
			if (q->xishu == 0)
				deletenode (p, q);
			return;
		}
		if (q->zhishu < zhishu) {
			ad = (node*)malloc(sizeof(node));
			ad->xishu = xishu;
			ad->zhishu = zhishu;
			ad->link = q;
			p->link = ad;
			return;
		}
		p = q;
		q = q->link;
	}
	ad = (node*)malloc(sizeof(node));
	ad->xishu = xishu;
	ad->zhishu = zhishu;
	ad->link = NULL;
	p->link = ad;
	return;
}
int main() {
	node* list1 = (node*)malloc(sizeof(node));
	node* list2 = (node*)malloc(sizeof(node));
	node* list3 = (node*)malloc(sizeof(node));
	node* q;
	node* qq = list1;
	int xi, zhi;

	list3->link = NULL;
	while ((p = getchar()) != '\n') {
		ungetc(p, stdin);
		scanf("%s %s", xishu, zhishu);
		xi = atoi(xishu);
		zhi = atoi(zhishu);
		q = (node*)malloc(sizeof(node));
		q->xishu = xi;
		q->zhishu = zhi;
		q->link = NULL;
		qq->link = q;
		qq = q;
	}
	//printlist(list1);
	qq = list2;
	while ((p = getchar()) != '\n') {
		ungetc(p, stdin);
		scanf("%s %s", xishu, zhishu);
		xi = atoi(xishu);
		zhi = atoi(zhishu);
		q = (node*)malloc(sizeof(node));
		q->xishu = xi;
		q->zhishu = zhi;
		q->link = NULL;
		qq->link = q;
		qq = q;
	}
	//printlist(list2);
	q = list1->link;
	qq = list2->link;
	while (q != NULL) {
		while (qq != NULL) {

			xi = q->xishu * qq->xishu;
			zhi = q->zhishu + qq->zhishu;
			//printf("%d %d\n",xi,zhi);
			addnode(list3, xi, zhi);
			qq = qq->link;
		}
		qq = list2->link;
		q = q->link;

	}
	printlist(list3);
	return 0;
}

