#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
struct node {
	int pre;
	int back;
	struct node *next;
};
void Listsort(struct node *head, int cnt);
int main() {
	struct node *head1 = NULL, *head2 = NULL, *p, *r, *t1, *t2, *pnew;

	int a, b, check;
	int cnt = 0;
	char c;


	while ((check = scanf("%d%d%c", &a, &b, &c)) == 3) {
		p = (struct node *)malloc(sizeof(struct node));
		p->pre = a;
		p->back = b;
		p->next = NULL;

		//printf("%d %d\n",p->pre,p->back);

		if (head1 == NULL) head1 = p;
		else r->next = p;

		r = p;
		if (c == '\n') break;
	}
	while ((check = scanf("%d%d%c", &a, &b, &c)) == 3) {
		p = (struct node *)malloc(sizeof(struct node));
		p->pre = a;
		p->back = b;
		p->next = NULL;

		//printf("%d %d\n",p->pre,p->back);//debug

		if (head2 == NULL) head2 = p;
		else r->next = p;

		r = p;
		if (c == '\n') break;
	}


	t1 = head1;
	t2 = head2;
	struct node *headnew = NULL, *r2, *temp = NULL;

	while (t2 != NULL) {
		while (t1 != NULL) {

			pnew = (struct node *)malloc(sizeof(struct node));
			pnew->pre = t1->pre * t2->pre;
			pnew->back = t1->back + t2->back;
			pnew->next = NULL;
			//printf("%d %d\n",pnew->pre,pnew->back);//debug
			cnt++;

			if (headnew == NULL) headnew = pnew;
			else r2->next = pnew;
			r2 = pnew;
			t1 = t1->next;
		}
		t2 = t2->next;
		t1 = head1;
	}

	Listsort(headnew, cnt);

	//合并同类项
	pnew = headnew;
	for (; pnew != NULL; pnew = pnew->next) {
		if (pnew->next == NULL) break;
		if (pnew->next->back == pnew->back) {
			pnew->pre = pnew->pre + pnew->next->pre;
			temp = pnew->next;
			pnew->next = temp->next;
			free(temp);
			temp=NULL;
			//系数相同
		}
		if(pnew->next->back == pnew->back){
			pnew->pre = pnew->pre + pnew->next->pre;
			temp = pnew->next;
			pnew->next = temp->next;
			free(temp);
			temp=NULL;
			//系数相同
		}
	}

	pnew = headnew;
	for (; pnew != NULL; pnew = pnew->next) {
		printf("%d %d ", pnew->pre, pnew->back);
	}
	printf("\n");
	return 0;
}
void Listsort(struct node *head, int cnt) {
	int i = 0;
	int j = 0;

	struct node * L = head;

	struct node * p;
	struct node * p1;

	for (i = 0; i <= cnt - 1; i++) {
		L = head;
		for (j = 0; j <= cnt - i - 1; j++) {

			p = L;
			p1 = L->next;
			if (p1 == 0x0) break;
			if (p->back < p1->back) {
				int temp1 = p->back;
				int temp2 = p->pre;
				p->back = p1->back;
				p1->back = temp1;
				p->pre = p1->pre;
				p1->pre = temp2;
			}
			L = L->next;
		}

	}
}


