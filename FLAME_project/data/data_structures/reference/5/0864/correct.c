#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ll long long
#define ull unsigned long long

struct node {
	int coe;
	int index;
	struct node *next;

};

typedef struct node *Nodeptr;

int main() {
	Nodeptr head1 = NULL, head2 = NULL, tail1, tail2, p1, p2, t1, t2, head3 = NULL, tail3, p3, t3;
	char c;

	do {
		p1 = (Nodeptr)malloc((sizeof(struct node)));
		scanf("%d%d%c", &p1->coe, &p1->index, &c);

		if (NULL == head1)
			head1 = tail1 = p1;

		else {
			tail1->next = p1;
			tail1 = p1;
		}
	} while (c != '\n');
	tail1->next = NULL;
//ok


	do {
		p2 = (Nodeptr)malloc((sizeof(struct node)));
		scanf("%d%d%c", &p2->coe, &p2->index, &c);

		if (NULL == head2)
			head2 = tail2 = p2;

		else {
			tail2->next = p2;
			tail2 = p2;
		}
	} while (c != '\n');
	tail2->next = NULL; //ok

	for (t1 = head1; t1 != NULL; t1 = t1->next) {
		for (t2 = head2; t2 != NULL; t2 = t2->next) {
			p3 = (Nodeptr)malloc((sizeof(struct node)));
			p3->coe = t1->coe * t2->coe;
			p3->index = t1->index + t2->index;
			if (NULL == head3)
				head3 = tail3 = p3;
			else {
				tail3->next = p3;
				tail3 = p3;
			}


		}
		t2 = head2;
	}
	tail3->next = NULL;



	Nodeptr max, temp, find;
	max = (Nodeptr)malloc(sizeof(struct node));
	max->index = 0;

	for (t3 = head3; t3 != NULL; t3 = t3->next) {
		if (t3->coe == 0)
			continue;
		for (temp = t3->next; temp != NULL; temp = temp->next) {
			if ((temp->index == t3->index) && (temp->coe != 0)) {
				t3->coe += temp->coe;
				temp->coe = 0;
			}
		}

	}
	t3 = head3;

	while (head3 != NULL) {
		for (; t3->next != NULL; t3 = t3->next) {
			if ((t3->index > max->index) && (t3->coe != 0))
				max = t3;
		}

		if (max->index == 0)
			break;
		if (max->coe != 0) {
			printf("%d %d ", max->coe, max->index);
			if (max == head3) {
				head3 = head3->next;
				free(max);

			} else {
				for (find = head3; find->next != max; find = find->next);
				find->next = max->next;
				free(max);

			}

			max = (Nodeptr)malloc(sizeof(struct node));
			max->index = 0;
		}
		t3 = head3;
	}

	printf("%d %d ", t3->coe, t3->index);
}
