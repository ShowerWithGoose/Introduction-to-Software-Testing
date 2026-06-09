#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int nub;//数据域
	int coe;//系数
	int exp;//指数
	struct node* link;//指针域
}LNode, * LinkList;

LinkList creat1() {//建立一个线性链表
	LinkList p = NULL, r = NULL, list = NULL;
	int i = 1;
	int a1=0, a2=0;
	
		while (scanf("%d%d", &a1, &a2) != EOF)
		{
			p = (LinkList)malloc(sizeof(LNode));//申请一个新的链接点
			p->nub = i;
			p->coe = a1;
			p->exp = a2;
			p->link = NULL;//链表末尾结点指针域为置空
			i++;
			if (list == NULL)
			{
				list = p;
			}
			else {
				r->link = p;//将新结点链接在链表尾部
			}
			r = p;//指针变量r总是指向链表末尾
			r->link = NULL;
			if (getchar() == '\n') {
				list->nub = i-1;
				return list;
			}
			else {
				continue;
			}
		}
		list->nub = i-1;
	return(list);
}
LinkList creat2(int n) {//建立一个线性链表（长度为n）
	LinkList p = NULL, r = NULL, list = NULL;
	int i = 1;
	for (i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(LNode));//申请一个新的链接点
		p->nub = i;
		p->link = NULL;//链表末尾结点指针域为置空
		if (list == NULL)
		{
			list = p;
		}
		else {
			r->link = p;//将新结点链接在链表尾部
		}
		r = p;//指针变量r总是指向链表末尾
		r->link= NULL;
	}
	return(list);
}

int main() {
	int coe = 0, exp = 0;//coe为系数，exp为指数
	int len1 = 0, len2 = 0, t = 0;
	LinkList p1 = creat1(), m = NULL;
	m = p1;//第一个链表储存第一排多项式数据
	len1 = p1->nub;

	LinkList p2 = creat1(), l = NULL;
	l = p2;//第二个链表储存第一排多项式数据
	len2 = p2->nub;

	LinkList p3 = creat2(len1 * len2),r=NULL;
	r = p3;
	t = len1 * len2;

	while (m != NULL) {
		while (l != NULL) {
			r->coe = (m->coe) * (l->coe);
			r->exp = (m->exp) + (l->exp);
			l = l->link;
			r = r->link;
		}
		m = m->link;
		l = p2;
	}//已经乘完，等待组合系数并按降幂排列
	r = p3;
	
	
	
		int i, j, hold, flag;
		for (i = 0; i < t - 1; i++)
		{
			flag = 0;
			for (j = 0; j < t - 1 - i; j++)
			{
				if (r->exp < r->link->exp)
				{
					hold = r->exp;
					r->exp = r->link->exp;
					r->link->exp = hold;

					hold = r->coe;
					r->coe = r->link->coe;
					r->link->coe = hold;

					flag = 1;
				}
				
				r = r->link;
			}
		 
			r = p3;
			if (0 == flag)
				break;
		}
		r = p3;

		while (r->link != NULL) {
			if (r->link != NULL) {
				if (r->exp == r->link->exp) {
					r->coe = (r->coe) + (r->link->coe);
					r->link = r->link->link;
				}
				r = r->link;
			}
	     }
		r = p3;
		while (r->link != NULL) {
			if (r->link != NULL) {
				if (r->exp == r->link->exp) {
					r->coe = (r->coe) + (r->link->coe);
					r->link = r->link->link;
				}
				printf("%d %d ", r->coe, r->exp);
				r = r->link;
			}
		}
		r = p3;
		while (r ->link!= NULL) {
			r = r->link;
		}
			printf("%d %d ", r->coe, r->exp);
	return 86;
}

