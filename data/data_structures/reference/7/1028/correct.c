#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
static struct branch {
	int num;
	int depth;
	struct branch *left, *right, *parent;
};
typedef struct branch Node;
typedef struct branch *Nodeptr;
void setup(int, Nodeptr);
void deletree(Nodeptr, int,int);
int main () {
	int n;
	int op;
	int min = 0;
	Nodeptr head, p, q;
	head = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &op);
		if (op < min) {
			min = op;
		}
		if (i == 0) {
			p = (Nodeptr)malloc(sizeof(Node));
			p->num = op;
			p->depth = 1;
			p->left = NULL;
			p->right = NULL;
			p->parent = NULL;
			head = p;
		} else {
			p=head;
			while (1) {
				if (op < p->num) {
					if (p->left == NULL) {
						q = (Nodeptr)malloc(sizeof(Node));
						q->num = op;
						q->depth = p->depth + 1;
						q->left = NULL;
						q->right = NULL;
						q->parent = p;
						p->left = q;
						break;
					} else p = p->left;
				} else {
					if (p->right == NULL) {
						q = (Nodeptr)malloc(sizeof(Node));
						q->num = op;
						q->depth = p->depth + 1;
						q->left = NULL;
						q->right = NULL;
						q->parent = p;
						p->right = q;
						break;
					} else p = p->right;
				}
			}
		}
	}
	deletree(head, min,n);
	return 0;
}
void deletree(Nodeptr head, int min,int n) {
	Nodeptr p, q;
	p = head;
	int x = min - 1;
	while (head->left != NULL || head->right != NULL) {
		if (p->left != NULL) {
			p->num = x;
			p = p->left;
		} else if (p->right != NULL) {
			p->num = x;
			p = p->right;
		} else {
			q = p->parent;
			if (p == q->left) {
				q->left = NULL;
			} else q->right = NULL;
			if (p->num > x) {
				printf("%d %d\n", p->num, p->depth);
			}
			free(p);
			p = q;
		}
	}
	if(n==1){
		printf("%d %d\n", p->num, p->depth);
	}
	free(head);
}

