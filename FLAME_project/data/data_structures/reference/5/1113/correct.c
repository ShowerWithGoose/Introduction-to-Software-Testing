#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct link {
	int a;
	int x;
	struct link* next;
} X;
X* first1 = NULL, * first2 = NULL, * first3 = NULL, * p, * q;
X* Insert(X* item,X* first3) {
	X* Y = first3;
	if (first3 == NULL) first3 = item,first3->next = NULL;
	else {
		if (item->x > first3->x) {
			item->next = first3;
			first3 = item;
			
		}
		else if (Y->next == NULL) item->next = NULL, Y->next = item;
		else {
			while ((item->x < Y->next->x)) {  
				if (Y->next->next== NULL) break;
			else Y = Y->next; }
			if (Y->next->next != NULL) {
				if (Y->next->x == item->x) Y->next->a = Y->next->a + item->a;
				else if (Y->next->x < item->x) {
					item->next = Y->next;
					Y->next = item;
				}
			}
			else {
				if (Y->next->x == item->x) Y->next->a = Y->next->a + item->a;
				else if (Y->next->x < item->x) {
					item->next = Y->next;
					Y->next = item;
				}
				else {
					item->next = NULL;
					Y->next->next = item;
				}
			}
		}
	}
	return first3;
}
X* mulit(X* first1, X* first2,X*first3) {
	X* Y = first1;
	while (Y != NULL) {
		X* item;
		item = (X*)malloc(sizeof(X));
		item->a = Y->a * first2->a;
		item->x = Y->x + first2->x;
		first3=Insert(item,first3);
		Y = Y->next;
	}
	return first3;
}

int main(){
	int flag = 1;
	while (flag) {
		q = (X*)malloc(sizeof(X));
		scanf("%d %d", &q->a, &q->x);
		if (first1 == NULL) first1 = p = q;
		else {
			if (p->x <= q->x) flag = 0;//读入第一个多项式终止条件
			else {
				p->next = q;
				p = q;
			}
		}
	}
	p->next = NULL;
	first2 = p = q;//第二个多项式开头
	while (flag == 0) {
		q = (X*)malloc(sizeof(X));
		if (scanf("%d %d", &q->a, &q->x)!=EOF) {
			p->next = q;
			p = q;
		}
		else flag = 1;
	}
	p->next = NULL;
	while (first2 != NULL) {
		first3=mulit(first1, first2,first3);
		first2 = first2->next;
	}
	while (first3 != NULL) {
		printf("%d %d ", first3->a, first3->x);
		first3 = first3->next;
	}
	return 0;
}
