#include<stdio.h>
#include<string.h>//为什么链表会简单？ 
#include<stdlib.h>
struct link {
	int a, n; //a为系数，n为指数
	struct link*next;//建成链表
}*p[3], *q[3], *first[3]; //分别为乘数、被乘数、积的三个指针
void change(struct link *a, struct link *b) {//更换两个结点内的内容
	struct link c;
	c.a = b->a;
	c.n = b->n;
	b->a = a->a;
	b->n = a->n;
	a->a = c.a;
	a->n = c.n;
}
void bubble(int num_3) {//冒泡排序函数
	for (int i = 0; i <= num_3; i++) {
		int flag = 0;
		for (int j = 0; j <= num_3 - 2; j++) {
			if ((q[2]->n) < (q[2]->next->n)	) {
				change(q[2], q[2]->next);
				flag = 1;
			}
			q[2] = q[2]->next;
		}
		q[2] = q[2]->next;
		if (flag == 0) {
			break;
		}
	}
}
void sum(int num_3) {//合并同类项函数
	struct link *point = NULL;
	for (int i = 0; i <= num_3 - 1; i++) {
		if ((q[2]->n) == (q[2]->next->n)&&num_3!=1) {
			point = q[2]->next;
			q[2]->a = (point->a) + (q[2]->a);
			q[2]->next = q[2]->next->next;
			free(point);
		} else
			q[2] = q[2]->next;
	}
}
int main() {
	int a1, n1, num_1 = 0, num_2 = 0, num_3 = 0; //输入的系数与指数
	char flag;
	p[0] = NULL, first[0] = NULL, q[0] = NULL;
	while (scanf("%d %d%c", &a1, &n1, &flag)) { //输入第一个多项式
		p[0] = (struct link*)malloc(sizeof(struct link));
		p[0]->a = a1;
		p[0]->n = n1;
		p[0]->next = NULL;
		if (first[0] == NULL) {
			first[0] = q[0] = p[0] ; //初始所有指针都指向第一个结点
		} else {
			q[0]->next = p[0];
			q[0] = q[0]->next;//p指向当前已建好的最后一个结点
		}
		num_1++;
		if (flag == '\n') {
			break;
		}
	}
	q[0]->next = first[0];
	q[0] = q[0]->next;
	flag = 'a';
	p[1] = NULL, first[1] = NULL;
	while (scanf("%d %d%c", &a1, &n1, &flag)) { //输入第一个多项式
		p[1] = (struct link*)malloc(sizeof(struct link));
		p[1]->a = a1;
		p[1]->n = n1;
		p[1]->next = NULL;
		if (first[1] == NULL) {
			first[1] = q[1] = p[1]; //初始所有指针都指向第一个结点
		} else {
			q[1]->next = p[1]  ;
			q[1] = q[1]->next;//p指向当前已建好的最后一个结点
		}
		num_2++;
		if (flag == '\n') {
			break;
		}
	}
	q[1]->next = first[1];
	q[1] = q[1]->next;
	p[2] = NULL, first[2] = NULL, q[2] = NULL;
	for (int i = 0; i <= num_1 - 1; i++) { //得到乘积式
		for (int j = 0; j <= num_2 - 1; j++) {
			p[2] = (struct link*)malloc(sizeof(struct link));
			p[2]->a = q[1]->a * q[0]->a;
			p[2]->n = q[1]->n + q[0]->n;
			p[2]->next = NULL;
			if (first[2] == NULL) {
				first[2] = q[2] = p[2]; //初始所有指针都指向第一个结点
			} else {
				q[2]->next = p[2];
				q[2] = q[2]->next;//p指向当前已建好的最后一个结点
			}
			q[1] = q[1]->next;
			num_3++;
		}
		q[0] = q[0]->next;
	}
	q[2]->next = first[2];
	q[2] = q[2]->next;
	bubble(num_3);//排序
	sum (num_3); //合并同类项

	for (; ; ) {//释放内存+输出
		if (q[2]->a != 0) {
			printf("%d %d ", q[2]->a, q[2]->n);
		}
		p[2] = q[2];
		q[2] = q[2]->next;
		free(p[2]);
		if (q[2] == first[2]) {
			break;
		}
	}
	for (int i = 0; i <= num_1 - 1; i++) { //释放内存
		q[0] = p[0];
		p[0] = p[0]->next;
		free(q[0]);
	}
	for (int i = 0; i <= num_2 - 1; i++) { //释放内存
		q[1] = p[1];
		p[1] = p[1]->next;
		free(q[1]);
	}
	return 0;
}

