#include <stdio.h>
#include <stdlib.h>

typedef struct Term
{
	long long coefficient;
	long long exponent;
	struct Term* next;
}Term;

int main() {
	Term* head1 = NULL;
	Term* tail1 = NULL;
	Term* head2 = NULL;
	Term* tail2 = NULL;
	
	char ch = ' ';
	while (ch == ' ') {
		if (!head1)
			head1 = tail1 = (Term*)malloc(sizeof(Term));
		else
			tail1 = tail1->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(tail1->coefficient), &(tail1->exponent));
		tail1->next = NULL;
		ch = getchar();
	}
	ch = ' ';
	while (ch == ' ') {
		if (!head2)
			head2 = tail2 = (Term*)malloc(sizeof(Term));
		else
			tail2 = tail2->next = (Term*)malloc(sizeof(Term));
		scanf("%lld%lld", &(tail2->coefficient), &(tail2->exponent));
		tail2->next = NULL;
		ch = getchar();
	}

	long long coefficient;
	long long exponent;

	Term* p1 = head1;
	Term* p2;

	Term* dummyHead = (Term*)malloc(sizeof(Term));
	dummyHead->coefficient = 0;
	dummyHead->exponent = -1;
	dummyHead->next = NULL;

	Term* prev;
	Term* curr;

	while (p1) {
		p2 = head2;
		while (p2) {
			prev = dummyHead;
			curr = dummyHead->next;

			coefficient = p1->coefficient * p2->coefficient;
			exponent = p1->exponent + p2->exponent;

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
			p2 = p2->next;
		}
		p1 = p1->next;
	}

	Term* head = dummyHead->next;
	free(dummyHead);
	while (head) {
		if (head->coefficient) printf("%d %d ", head->coefficient, head->exponent);
		head = head->next;
	}

	return 0;
}
