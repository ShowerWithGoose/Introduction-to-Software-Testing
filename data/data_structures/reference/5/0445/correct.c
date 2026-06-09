#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node {
	long long a;
	long long powe;
	struct node* succ;
}Node, *muil;
void inital(muil x, muil y) {
	muil start1 = x;
	muil start2 = y; 
	long long c, d;
	while(scanf("%lld%lld", &c, &d)) {
		x->a = c;
		x->powe = d;
		muil k = (muil)malloc(sizeof(Node));
		x->succ = k;
		k->a = -1;
		k->powe = -1;
		k->succ = NULL;
		if (getchar() == '\n') break;
		x = x->succ; 
	}
	while(scanf("%lld%lld", &c, &d)) {
		y->a = c;
		y->powe = d;
		muil k = (muil)malloc(sizeof(Node));
		y->succ = k;
		k->a = -1;
		k->powe = -1;
		k->succ = NULL;
		if (getchar() == '\n') break;
		y = y->succ;
	}
	return;
}
int search(muil start, muil q, long long pa, long long ppowe) {
	int color = 0;
	while((start != q)) {
		muil t = start->succ;
		if ((start->succ != q) && (start->powe) > ppowe && (t->powe) < ppowe) {
			color = 1;
			muil inser = (muil)malloc(sizeof(Node));
			start->succ = inser;
			inser->succ = t;
			inser->powe = ppowe;
			inser->a = pa;
			return color;
		}
		else if (start->powe == ppowe) {
			color = 1;
			start->a = (start->a) + pa;
			return color;
		}else if (t->powe == ppowe){
			color = 1;
			t->a = (t->a) + pa;
			return color;
		}
		start = t;
	}
	return color;
}
void muilt(muil q, muil x, muil y) {
	muil start1 = x;
	muil start2 = y;
	muil start3 = q;
	while((y->a) >= 0 && (y->powe) >= 0) {
		if ((x->a) == -1 && (x->powe) == -1) {

			x = start1;
			y = y->succ;
		}
		if ((y->a) == -1 && (y->powe) == -1) {
			q = NULL;
			break;
		}
		long long pa = (x->a) * (y->a);
		long long ppowe = (x->powe) + (y->powe);
		if (search(start3, q, pa, ppowe) == 0) {
			q->a = pa;
			q->powe = ppowe;
			muil t = (muil)malloc(sizeof(Node)); 
			q->succ = t;
			t->succ = NULL;
			t->powe = -1;
			t->a = -1;
			q = q->succ;
		}
		x = x->succ;
	}
	q = start3;
/*	while(q != NULL) {
		printf("%lld %lld ", q->a, q->powe);
		q = q->succ;
	}*/
	return;
}
int main() {
	Node list1, list2, ans;
	muil x = &list1;
	muil y = &list2;
	inital(x, y);
	muil q = &ans;
	q->a = -1;
	q->powe = -1;
	q -> succ = NULL;
	muilt(q, x, y);
	while((q) != NULL && (q -> powe) >= 0 && (q -> a )>=0 ) {
		printf("%lld %lld ", q->a, q->powe);
		q = q->succ;
	}
	return 0;
}

