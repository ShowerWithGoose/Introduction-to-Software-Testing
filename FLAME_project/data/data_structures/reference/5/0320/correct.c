#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
	int coe;//多项式系数
	int pow;//多项式指数
	struct node *next;
};

struct node_1 {
	int xishu;
	int zhishu;
};


int main() {
	struct node_1 xiang_1[100], xiang_2[100];
	struct node *list, *p, *q, *r; //r存p的前继结点的指针
	list = NULL;
	p = NULL;
	int num_1 = 0, num_2 = 0;
	int i = 0, j = 0;
	char c;
	do {
		scanf("%d%d%c", &xiang_1[num_1].xishu, &xiang_1[num_1].zhishu, &c);
		num_1++;
	} while (c != '\n');
	do {
		scanf("%d%d%c", &xiang_2[num_2].xishu, &xiang_2[num_2].zhishu, &c);
		num_2++;
	} while (c != '\n');
	int multi, add; //multi用于系数相乘，add用于指数相加
	for (i = 0; i < num_1; i++) {
		for (j = 0; j < num_2; j++) {
			q = (struct node *)malloc(sizeof(struct node));
			multi = xiang_1[i].xishu * xiang_2[j].xishu;
			add = xiang_1[i].zhishu + xiang_2[j].zhishu;
			q->coe = multi;
			q->pow = add;
			q->next = NULL;
			if (list == NULL)
				list = p = q;
			else { //按照指数找出合适的插入位置
				for (p = list; p != NULL; r = p, p = p->next) {
					if (add < p->pow)
						continue;
					else if (add == p->pow) {
						p->coe += q->coe;
						free(q);
						q = NULL;
						break;
					} else { //add>p->pow 需要在p前面插入q
						if (p == list) {
							q->next = list;
							list = q;
						} else {
							q->next = p;
							r->next = q;
						}
						break;
					}
				}
				//需要在末尾插入q
				if (p == NULL)
					r->next = q;
			}
		}
	}
	for (p = list; p != NULL; p = p->next)
		printf("%d %d ", p->coe, p->pow);
	return 0;
}
//che清零

