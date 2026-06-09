#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ll long long
#define ull unsigned long long
#define db double
#define pr printf
#define sf scanf
#define rt return
#define gcr getchar
#define pcr putchar
#define pi 3.14159265
#define sw switch
#define brk break
#define ctn continue
#define sc(x) scanf("%d",&x)
#define ef else if
#define slf(x) scanf("%lf",&x)
#define pf(x) printf("%d\n",x)//\n
#define max(a,b) ((a)>=(b)?(a):(b))//可修改>=or>
#define min(a,b) ((a)<=(b)?(a):(b))
#define sl strlen
#define PR printf("\n");
#define For(n) for(int i=0;i<n;++i)
#define New(p) p=(node*)malloc(sizeof(node))
#define itn int
#define fsf fscanf
#define fpr fprintf

typedef struct node {
	int k;
	int e;
	struct node *next;
} node;

node *create(node a[], int n) {
	node *head, *p, *pre;
	New(head);
	head->next = NULL;
	pre = head;
	For(n) {
		New(p);
		p->k = a[i].k;
		p->e = a[i].e;
		p->next = NULL;
		pre->next = p;
		pre = p;
	}
	rt head->next;
}

void prt(node *L) {
	node *p = L;
	while (p != NULL) {
		if (p->k != 0) {
			pr("%d %d ", p->k, p->e);
		}
		p = p->next;
	}
	PR
}

void sort(node *C) {
	int k, e;
	node *p, *q;
	for (p = C; p; p = p->next) {
		for (q = p; q != NULL; q = q->next) {
			if (p->e < q->e) {
				//swap data area
				k = p->k;
				e = p->e;
				p->k = q->k;
				p->e = q->e;
				q->k = k;
				q->e = e;
			}
		}
	}
}

void sum(node *C) {
	//if e1==e2 del 2，k1+=k2
	node *pre, *q, *p;
	for (p = C; p; p = p->next) {
		for (q = p->next; q != NULL; q = q->next) {
			if (p->e == q->e) {
				p->k += q->k;
				q->k = 0;
				//printf("h ");
			}
		}
	}
//	for (p = C; p != NULL; p = p->next) {
//		for (pre = p, q = pre->next; pre != NULL; q = q->next) {
//			if (p->e == q->e) {
//				p->k += q->k;
//				q = q->next;
//				pre->next = q;
//			}
//		}
//	}
}

int main() {
	node L[200];
	node L2[200];
	int cnt1 = 0, cnt2 = 0;
	char c;
	for (int i = 0; 1; ++i) {
		sf("%d%d%c", &L[i].k, &L[i].e, &c) ;
		cnt1++;
		if (c == '\n')
			brk;
	}

	for (int i = 0; 1; ++i) {
		sf("%d%d%c", &L2[i].k, &L2[i].e, &c);
		cnt2++;
		if (c == '\n')
			brk;
	}
	//For(cnt2)pr("%d %d ", L2[i].k, L2[i].e);
	node *A = create(L, cnt1);
	node *B = create(L2, cnt2);
//	prt(A);
//	prt(B);
	//success
	//k相乘，e相加，双层遍历
	node *A0 = A;
	node *B0 = B;
	node *C = NULL;
	node *p, *pre;
	New(C);
	C->next = NULL;
	pre = C;
	for (A = A0; A; A = A->next) {
		for (B = B0; B; B = B->next) {
			New(p);
			p->k = (A->k * B->k);
			p->e = (A->e + B->e);
			pre->next = p;
			p->next = NULL;
			pre = p;
		}
	}
	C = C->next;
	//prt(C);
	sum(C);
	sort(C);
	prt(C);

}























