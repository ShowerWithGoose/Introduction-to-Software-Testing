#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	long long coefficient;
	long long exponent;
	struct Term* next;
}Term;

int main() {
	Term* p_head = NULL;
	Term* p = NULL;
	Term* q_head = NULL;
	Term* q = NULL;
	
	char ch = ' ';
	while (ch == ' ') {
		if (!p_head)
			p_head = p = (Term*)malloc(sizeof(Term));
		else
			p = p->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(p->coefficient), &(p->exponent));
		p->next = NULL;
		ch = getchar();
	}
	ch = ' ';
	while (ch == ' ') {
		if (!q_head)
			q_head = q = (Term*)malloc(sizeof(Term));
		else
			q = q->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(q->coefficient), &(q->exponent));
		q->next = NULL;
		ch = getchar();
	}

	long long coefficient;
	long long exponent;

	Term* p1 = p_head;
	Term* p2;

	Term* r_head = (Term*)malloc(sizeof(Term));
	r_head->coefficient = 0;
	r_head->exponent = -1;
	r_head->next = NULL;

	Term* s;
	Term* curr;

	while (p1) {
		p2 = q_head;
		while (p2) {
			s = r_head;
			curr = r_head->next;

			coefficient = p1->coefficient * p2->coefficient;
			exponent = p1->exponent + p2->exponent;

			while (curr) {
				if (curr->exponent <= exponent) break;
				curr = curr->next;
				s = s->next;
			}

			if (!curr) {
				s = s->next = (Term*)malloc(sizeof(Term));
				s->coefficient = coefficient;
				s->exponent = exponent;
				s->next = curr;
			}

			else if (curr->exponent == exponent) {
				curr->coefficient += coefficient;
			}

			else {
				s = s->next = (Term*)malloc(sizeof(Term));
				s->coefficient = coefficient;
				s->exponent = exponent;
				s->next = curr;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	Term* r = r_head->next;
	free(r_head);
	while (r) {
		if (r->coefficient) printf("%d %d ", r->coefficient, r->exponent);
		r = r->next;
	}

	return 0;
}
