#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree {
	int num;
	int flag;
	struct tree* lchild;
	struct tree* rchild;
};
struct tree* head = NULL, *p = NULL, *r = NULL;
int main() {
	int n, s, layer = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s);
		r = (struct tree*)malloc(sizeof(struct tree));
		r->num = s;
		r->flag = 0;
		if (head == NULL) {
			head = p = r;
		} else {
			p = head;
			while (1) {
				if (r->num < p->num) {
					if (p->lchild == NULL) {
						p->lchild = r;
						break;
					} else {
						p = p->lchild;
					}
				} else if (r->num >= p->num) {
					if (p->rchild == NULL) {
						p->rchild = r;
						break;
					} else {
						p = p->rchild;
					}
				}
			}
		}
	}
	while (1) {
		p = head;
		layer = 0;
		while (1) {
			layer++;
			if (p->lchild != NULL) {
				if (p->lchild->flag == 0) {

					p = p->lchild;
					continue;
				}
			}
			if (p->rchild != NULL) {
				if (p->rchild->flag == 0) {
					p = p->rchild;
					continue;
				}
				if (p->rchild->flag == 1) {
					p->flag = 1;
					break;
				}
			}
			if (p->lchild == NULL && p->rchild == NULL) {
				printf("%d %d\n", p->num, layer);
				p->flag = 1;
				break;
			}
			if (p->rchild == NULL) {
				p->flag = 1;
				break;
			}

		}
		if (head->flag == 1) {
			break;
		}
	}
	/*	while (1) {
			printf("%d", p->num);
			if (p->lchild == NULL) {
				break;
			}
			p = p->lchild;
		}
	*/
	return 0;
}

