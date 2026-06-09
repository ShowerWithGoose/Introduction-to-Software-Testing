#define  _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct link {
	struct link* llink;
	struct link* rlink;
	int num;
	int h;
}T;
typedef struct {
	T* root;
}Root;
T* q; int hi = 1;
T* insert(T* a, int m,int hi) {
	if (a == NULL) {
		q = (T*)malloc(sizeof(T));
		q->h = hi;
		q->llink = NULL;
		q->rlink = NULL;
		q->num = m;
		a = q;
	}
	else {
		if (m < a->num) {
			a->llink = insert(a->llink, m, hi + 1);
		}
		else a->rlink = insert(a->rlink, m, hi + 1);
	}
	return a;
}
void print(T* a) {
	if(a!=NULL)
	{print(a->llink);
	if (a->llink == NULL && a->rlink == NULL) printf("%d %d\n", a->num, a->h);
	print(a->rlink); }
}
int main()
{
	int n; int m;
	Root r;
	r.root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {	
		scanf("%d", &m);
		r.root=insert(r.root, m,hi);
	}
	print(r.root);
	return 0;
}
