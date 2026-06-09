#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
	int x1, y1, x2, y2;
	struct node *next;
} ;

struct node *list[105], *p[105];

int n = 0; //计算已有的线段数

int isconnect(struct node *first, struct node *last, struct node *item) {
	if (item->x2 == first->x1 && item->y2 == first->y1)
		return 1;//接在最前面
	else if (item->x1 == last->x2 && item->y1 == last->y2)
		return 2;//接在最后面
	else
		return 0;
}

int main() {
	int num, count, max_count = 0, index = 0, flag = 0; //count计算一条连续线段中的线段数
	scanf("%d", &num);
	while (num--) {//录入线段的同时先将一些线段连起来，但有可能连不完全，故还需后续操作
		flag = 0;
		struct node *q = (struct node *)malloc(sizeof(struct node));
		if (q == NULL) {
			printf("error!\n");
			return EXIT_FAILURE;
		}
		scanf("%d%d%d%d", &q->x1, &q->y1, &q->x2, &q->y2);
		//printf("%d: x1 is %d, y1 is %d, x2 is %d, y2 is %d\n", count_tmp++, q->x1, q->y1, q->x2, q->y2);

		if (n == 0) {
			list[0] = p[0] = q;
			p[0]->next = NULL;
			n++;
		} else {
			for (int i = 0; i < n ; i++) {
				if (isconnect(list[i], p[i], q) == 1) { //接在最前面
					q->next = list[i];
					list[i] = q;
					flag = 1;
					break;
				} else if (isconnect(list[i], p[i], q) == 2) { //接在最后面
					p[i]->next = q;
					p[i] = p[i]->next;
					p[i]->next = NULL;
					flag = 1;
					break;
				}
			}
			//没接上 需要新建一条连续线段
			if (!flag) {
				list[n] = p[n] = q;
				p[n]->next = NULL;
				n++;
			}
		}
	}

	//进行一些遍历
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < n ; j++) {
			if (p[i]->x2 == list[j]->x1 && p[i]->y2 == list[j]->y1) {
				p[i]->next = list[j];
				p[i] = p[j]; //尾结点指针赋值
				list[j] = list[i];
			}
		}
	}

//找出需要输出的连续线段
	struct node *tmp;
	for (int i = 0; i < n ; i++) {
		count = 1; //清零
		for (tmp = list[i]; tmp->next != NULL; count++, tmp = tmp->next);
		if (count > max_count) {
			max_count = count;
			index = i;
		}
	}
	//printf("n is %d\n", n);

	/*	for (int i = 0; i < n ; i++) {
			printf("list[%d]->x1 is %d\nlist[%d]->y1 is %d\nlist[%d]->x2 is %d\nlist[%d]->y2 is %d\n", i, list[i]->x1, i,
			       list[i]->y1,
			       i,
			       list[i]->x2, i, list[i]->y2);
		}
		printf("index is %d\n", index);


		for (int i = 0; i < n; i++) {
			printf("p[%d]->x2 is %d\np[%d]->y2 is %d\n", i, p[i]->x2, i, p[i]->y2);
		}
		printf("list[2]->x1 is %d, list[2]->y1 is %d\n", list[2]->x1, list[2]->y1);
		printf("list[2]->x2 is %d, list[2]->y2 is %d\n", list[2]->x2, list[2]->y2);
	*/
	/*printf("max_count is %d\nlist[index]->x1 is %d\nlist[index]->y1 is %d\nlist[index]->x2 is %d\nlist[index]->y2 is %d\n",
	       max_count, list[index]->x1, list[index]->y1, list[index]->x2, list[index]->y2);
	*/
	printf("%d %d %d\n", max_count, list[index]->x1, list[index]->y1);
	return 0;
}
//FREE
//che清零



