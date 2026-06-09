#include<stdio.h>
#include<stdlib.h>
struct st{
	int coe;
	int pow;
	struct st *next;
};
typedef struct st Node;
typedef struct st *Nodeptr;
int main()
{
	Nodeptr list_a = NULL, list_b = NULL, p, q;
	Nodeptr list_ans = NULL, ans_p, ans_q, find, p0;
	char c;
	int coe, pow;
	int i, j;
	while( scanf("%d%d", &coe, &pow) ) {
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe = coe;
		q->pow = pow;
		q->next = NULL;
		if( list_a==NULL )
			list_a = p = q;
		else {
			p->next = q;
			p = p->next;
		}
		if( (c=getchar())=='\n' ) break;
	}
	while( scanf("%d%d", &coe, &pow)!=EOF ) {
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe = coe;
		q->pow = pow;
		q->next = NULL;
		if( list_b==NULL )
			list_b = p = q;
		else {
			p->next = q;
			p = p->next;
		}
	}
	ans_q = (Nodeptr)malloc(sizeof(Node));
	list_ans = ans_p = ans_q;
	list_ans->next = NULL;
	for( p=list_a; p!=NULL; p=p->next ) {
		for( q=list_b; q!=NULL; q=q->next ) {
			p0=list_ans, ans_p=list_ans->next;
			while( 1 ) {
				if( ans_p!=NULL && ans_p->pow == (p->pow + q->pow) ) {
					ans_p->coe += p->coe * q->coe;
					break;
				}
				else if( ans_p==NULL || ans_p->pow < (p->pow + q->pow) ) {
					ans_q = (Nodeptr)malloc(sizeof(Node));
					ans_q->pow = p->pow + q->pow;
					ans_q->coe = p->coe * q->coe;
					ans_q->next = ans_p;
					p0->next = ans_q;
					break;
				}
				p0 = p0->next;
				ans_p = ans_p->next;
			}
		}
	}
	for( ans_p=list_ans->next; ans_p!=NULL; ans_p=ans_p->next ) {
		if( ans_p->coe == 0 ) continue;
		printf("%d %d ", ans_p->coe, ans_p->pow);
	}
	return 0;
}


