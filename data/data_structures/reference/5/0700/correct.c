#include<stdio.h>
#include<stdlib.h>
struct node {
	int xishu;
	int zhishu;
	struct node *next;
};
typedef struct node* Nodeptr;
typedef struct node Node;

int main() {

	int a1, n1, a2=0, n2=0;
	char c;
	Nodeptr head1, head2;
	Nodeptr p1, p2, q1, q2, p0=NULL;
	head1 = p1 = NULL;
	head2 = NULL;
	p1=NULL;

	do {
		scanf("%d%d%c", &a1, &n1, &c);
		q1 = (Nodeptr)malloc(sizeof(Node));
		q1->xishu = a1;
		q1->zhishu = n1;
		q1->next = NULL;
		if (head1 == NULL) {
			head1 = p1 = q1;
		}
		else {
			p1->next = q1;
			p1 = p1->next;
		}

	} while (c != '\n');


	do {
		scanf("%d%d%c", &a1, &n1, &c);
		for (p1 = head1; p1 != NULL; p1 = p1->next) {
			a2 = a1 * p1->xishu;
			n2 = n1 + p1->zhishu;

			q2 = (Nodeptr)malloc(sizeof(Node));
			q2->xishu = a2;
			q2->zhishu = n2;
			q2->next = NULL;

			if(head2 == NULL) {
				head2 = p2 = q2;
			}
			else {
				for (p2 = head2; p2 != NULL; p0 = p2, p2 = p2->next) {
					if (q2->zhishu > p2->zhishu) {
						if (p2 == head2) {
							q2->next = head2;
							head2 = q2;
							break;
						}
						else {
							q2->next = p2;
							p0->next = q2;
							break;
						}
					}
					else if (q2->zhishu == p2->zhishu) {
						p2->xishu += q2->xishu;
						break;
					}

				}
				if (p2 == NULL) {
					p0->next = q2;
				}
			}
		}
	} while (c != '\n');

	for (p2 = head2; p2 != NULL; p2 = p2->next) printf("%d %d ", p2->xishu, p2->zhishu);
	printf("\n");



	return 0;
}

