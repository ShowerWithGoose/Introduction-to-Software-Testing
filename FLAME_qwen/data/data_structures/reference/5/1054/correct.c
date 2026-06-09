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
	int len1 = 0, len2 = 0, len3 = 0;
	LinkList list1 = creat1(), p1 = NULL;
	p1 = list1;//第一个链表储存第一排多项式数据
	len1 = list1->nub;

	LinkList list2 = creat1(), p2 = NULL;
	p2 = list2;//第二个链表储存第一排多项式数据
	len2 = list2->nub;

	LinkList list3 = creat2(len1 * len2),p3=NULL;
	p3 = list3;
	len3 = len1 * len2;

	while (p1 != NULL) {
		while (p2 != NULL) {
			p3->coe = (p1->coe) * (p2->coe);
			p3->exp = (p1->exp) + (p2->exp);
			p2 = p2->link;
			p3 = p3->link;
		}
		p1 = p1->link;
		p2 = list2;
	}//已经乘完，等待组合系数并按降幂排列
	p3 = list3;
	
	
	
		int i, j, hold, flag;
		for (i = 0; i < len3 - 1; i++)
		{
			flag = 0;
			for (j = 0; j < len3 - 1 - i; j++)
			{
				if (p3->exp < p3->link->exp)
				{
					hold = p3->exp;
					p3->exp = p3->link->exp;
					p3->link->exp = hold;

					hold = p3->coe;
					p3->coe = p3->link->coe;
					p3->link->coe = hold;

					flag = 1;
				}
				
				p3 = p3->link;
			}
		 
			p3 = list3;
			if (0 == flag)
				break;
		}
		p3 = list3;

		while (p3->link != NULL) {
			if (p3->link != NULL) {
				if (p3->exp == p3->link->exp) {
					p3->coe = (p3->coe) + (p3->link->coe);
					p3->link = p3->link->link;
				}
				p3 = p3->link;
			}
	     }
		p3 = list3;
		while (p3->link != NULL) {
			if (p3->link != NULL) {
				if (p3->exp == p3->link->exp) {
					p3->coe = (p3->coe) + (p3->link->coe);
					p3->link = p3->link->link;
				}
				printf("%d %d ", p3->coe, p3->exp);
				p3 = p3->link;
			}
		}
		p3 = list3;
		while (p3 ->link!= NULL) {
			p3 = p3->link;
		}
			printf("%d %d ", p3->coe, p3->exp);
	return 86;
}

