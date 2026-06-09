#include <stdio.h>
#include <stdlib.h>
typedef struct Node* Poly;
struct Node {
	int co;
	int exp;
	Poly Next;
};

void Attach(int c, int e, Poly *Rear) {
	if (c == 0) return;
	Poly P;
	P = (Poly)malloc(sizeof(struct Node));
	P->co = c;
	P->exp = e;
	P->Next = NULL;
	(*Rear)->Next = P;
	*Rear = P;
	return;
}

Poly ReadPoly() {
	char sentence[110] = {};
	char *ptr = sentence;
	Poly p = NULL;
	p = (Poly)malloc(sizeof(struct Node));
	Poly Rear = p;
	int n, c, e, cnt;
	gets(sentence);
	while (1) {
		cnt = 0;
		n = 0;
		while (cnt != 2) {
			if (ptr[n] == ' ' || ptr[n] == '\0') cnt++;
			n++;
		}
		sscanf(ptr, "%d %d", &c, &e);
		Attach(c, e, &Rear);
		if (ptr[n] != '\0') ptr += n;
		else break;
	}
	/*
	while (sscanf(ptr, "%d %d", &c, &e) == 2) {
	Attach(c, e, &Rear);
	}
	 */
	Poly t = p;
	p = p->Next;
	free(t);
	return p;
}

Poly Mult(Poly p1, Poly p2) {
	if (!p1 || !p2) return NULL;
	Poly t1 = p1;
	Poly t2 = p2;
	Poly p = NULL;
	p = (Poly) malloc(sizeof(struct Node));
	p->Next = NULL;
	Poly Rear = p;
	Poly t = NULL;
	int e, c;
	/*先用p1的第一项乘以p2，得到p*/
	while (t2) {
		e = t1->exp + t2->exp;
		c = t1->co * t2->co;
		Attach(c, e, &Rear);
		t2 = t2->Next;
	}
	t1 = t1->Next;
	while (t1) {
		t2 = p2;
		Rear = p;
		while (t2) {
			e = t1->exp + t2->exp;
			c = t1->co * t2->co;
			while (Rear->Next && Rear->Next->exp > e) Rear = Rear->Next;
			if (Rear->Next && Rear->Next->exp == e) {
				if (Rear->Next->co + c) {
					Rear->Next->co += c;
				} else {
					t = Rear->Next;
					Rear->Next = t->Next;
					free(t);
				}
			} else {
				t = (Poly)malloc(sizeof(struct Node));
				t->co = c;
				t->exp = e;
				t->Next = Rear->Next;
				Rear->Next = t;
				Rear = Rear->Next;
			}
			t2 = t2->Next;
		}
		t1 = t1->Next;
	}
	t2 = p;
	p = p->Next;
	free(t2);
	
	return p;
}

void Print(Poly p) {
	if (!p) {
		printf("0 0\n");
		return;
	}
	while (p) {
		printf("%d %d ", p->co, p->exp);
		p = p->Next;
	}
	printf("\n");
}

int main() {
	Poly p1, p2, ResM;
	p1 = ReadPoly();
	p2 = ReadPoly();
	ResM = Mult(p1, p2);
	Print(ResM);
	return 0;
}

