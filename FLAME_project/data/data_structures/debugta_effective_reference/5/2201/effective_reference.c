#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	long long coefficient;
	long long exponent;
	struct Term* next;
}Term;

int main() {
	Term* p1 = NULL;
	Term* i = NULL;
	Term* p2 = NULL;
	Term* j = NULL;
	
	char ch = ' ';
	while (ch == ' ') {
		if (!p1)
			p1 = i = (Term*)malloc(sizeof(Term));
		else
			i = i->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(i->coefficient), &(i->exponent));
		i->next = NULL;
		ch = getchar();
	}
	ch = ' ';
	while (ch == ' ') {
		if (!p2)
			p2 = j = (Term*)malloc(sizeof(Term));
		else
			j = j->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(j->coefficient), &(j->exponent));
		j->next = NULL;
		ch = getchar();
	}

	long long coefficient;
	long long exponent;

	Term* k = p1;
	Term* l;

	Term* p3 = (Term*)malloc(sizeof(Term));
	p3->coefficient = 0;
	p3->exponent = -1;
	p3->next = NULL;

	Term* prev;
	Term* curr;

	while (k) {
		l = p2;
		while (l) {
			prev = p3;
			curr = p3->next;

			coefficient = k->coefficient * l->coefficient;
			exponent = k->exponent + l->exponent;

			while (curr) {
				if (curr->exponent <= exponent) break;
				curr = curr->next;
				prev = prev->next;
			}

			if (!curr) {
				prev = prev->next = (Term*)malloc(sizeof(Term));
				prev->coefficient = coefficient;
				prev->exponent = exponent;
				prev->next = curr;
			}

			else if (curr->exponent == exponent) {
				curr->coefficient += coefficient;
			}

			else {
				prev = prev->next = (Term*)malloc(sizeof(Term));
				prev->coefficient = coefficient;
				prev->exponent = exponent;
				prev->next = curr;
			}
			l = l->next;
		}
		k = k->next;
	}

	Term* m = p3->next;
	free(p3);
	while (m) {
		if (m->coefficient) printf("%d %d ", m->coefficient, m->exponent);
		m = m->next;
	}

	return 0;
}
