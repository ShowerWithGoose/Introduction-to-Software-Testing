#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct result {
	int xi;
	int zhi;
};

struct mul {
	int xi;
	int zhi;
	struct mul *next;
};

typedef struct mul multi,*multp;

struct result a[1000];

char c;

int cmp (const void * a, const void * b) {

	if((*(struct result *)a).zhi>(*(struct result *)b).zhi) return -1;
	else return 1;
}

int main () {
	int n,m;
	multp list1=NULL,list2=NULL,list3=NULL,p,q,r,t;
	while(c!='\n') {
		scanf("%d%d%c",&n,&m,&c);
		p=(multp)malloc(sizeof(multi));
		p->next=NULL;
		p->xi=n;
		p->zhi=m;

		if(list1==NULL) {
			list1=q=p;
		} else q->next=p;
		q=p;
	}
	c='a';

	while(c!='\n') {
		scanf("%d%d%c",&n,&m,&c);
		p=(multp)malloc(sizeof(multi));
		p->next=NULL;
		p->xi=n;
		p->zhi=m;

		if(list2==NULL) {
			list2=q=p;
		} else q->next=p;
		q=p;
	}
	for(p=list1; p!=NULL; p=p->next) {
		for(q=list2; q!=NULL; q=q->next) {
			r=(multp)malloc(sizeof(multi));
			r->next=NULL;
			r->xi=p->xi*q->xi;
			r->zhi=p->zhi+q->zhi;
			if(list3==NULL) {
				list3=t=r;
			} else t->next=r;
			t=r;
		}
	}

	for(r=list3; r->next!=NULL; r=r->next) {
		for(p=r,q=r->next; q!=NULL;) {
			if(r->zhi==q->zhi) {

				r->xi+=q->xi;
				p->next=q->next;
				q=q->next;
				continue;
			}
			p=p->next;
			q=q->next;
		}
	}
	 
	

	int i=0;
	for(r=list3; r!=NULL; r=r->next,i++) {
		if(r->xi==0) {
			i--;
			continue;
		}
		a[i].xi=r->xi;
		a[i].zhi=r->zhi;
	}

	qsort(a,i,sizeof(struct result),cmp);

	for(int j=0; j<i; j++) {

		printf("%d %d ",a[j].xi,a[j].zhi);
	}

	return 0;
}

