#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LNode {
	int base;
	int pwr; // base * x ** pwr
	struct LNode *next;
};

typedef struct LNode *PNode;

PNode expr1, expr2;
PNode prod;

// insert term into linkedlist
void addTerm(int base, int pwr, PNode head) {
	PNode prev = head;
	// find prev->pwr <= pwr && prev->next->pwr > pwr;
	while (prev != NULL && prev->next != NULL && prev->next->pwr >= pwr)
		prev = prev->next;
	if (prev->pwr == pwr) {
		prev->base += base;
	} else {
		PNode term = (PNode)malloc(sizeof(struct LNode));
		term->next = prev->next;
		term->base = base;
		term->pwr = pwr;
		prev->next = term;
	}
}

void printList(PNode head) {
	PNode ptr = head->next;
	while (ptr != NULL) {
		if (ptr->base != 0) {
			printf("%d %d ", ptr->base, ptr->pwr);
		}
		ptr = ptr -> next;
	}
	printf("\n");
}

void input() {
	PNode head = expr1;
	int base, pwr;
	while (scanf("%d %d", &base, &pwr) != EOF) {
		addTerm(base, pwr, head);
		char c = getchar();
		if (c != ' ') {
			head = expr2;
		}
	}
}

void multiply() {
	PNode ptr1 = expr1->next, ptr2 = expr2->next;
	for (; ptr1 != NULL; ptr1 = ptr1->next) {
		for (ptr2 = expr2->next; ptr2 != NULL; ptr2 = ptr2->next) {
			// printf("%d %d * %d %d\n", ptr1->base, ptr1->pwr, ptr2->base, ptr2->pwr);
			addTerm(ptr1->base * ptr2->base, ptr1->pwr + ptr2->pwr, prod);
		}
	}
}

int main() {
	expr1 = (PNode)malloc(sizeof(struct LNode));
	expr2 = (PNode)malloc(sizeof(struct LNode));
	prod = (PNode)malloc(sizeof(struct LNode));
	expr1->base = expr2->base = prod->base = 0;
	expr1->pwr = expr2->pwr = prod->pwr = 2147483647;
	expr1->next = expr2->next = prod->next = NULL;
	
	input();
	// printList(expr1);
	// printList(expr2);
	multiply();
	printList(prod);
	
	
	return 0;
} 

/*
10 80000 2 6000 7 300 5 10 18 0
3 6000 5 20 8 10 6 0
*/



