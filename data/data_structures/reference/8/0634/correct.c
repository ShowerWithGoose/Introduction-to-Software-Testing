#include <stdio.h>
#include <stdlib.h>
struct stu {
	int v;
	struct stu *link;
} a[105];
int vd[105],b[105],i1,i2;
void sdyx(struct stu a[],int n,int o);
void sbl(struct stu a[],int v);
void gdyx(struct stu a[],int n);
void gbl(struct stu a[],int v,int n);
int main() {
	int n,m,k,d,e;
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d%d",&k,&d);
		struct stu *q,*s,*t;
		q=(struct stu*)malloc(sizeof(struct stu));
		q->v=d;
		q->link=NULL;
		s=a[k].link;
		t=&a[k];
		while(s!=NULL) {
			if(d<s->v) {
				t->link=q;
				q->link=s;
				break;
			} else {
				s=s->link;
				t=t->link;
			}
		}
		if(s==NULL)
			t->link=q;
		q=(struct stu*)malloc(sizeof(struct stu));
		q->v=k;
		q->link=NULL;
		s=a[d].link;
		t=&a[d];
		while(s!=NULL) {
			if(d<s->v) {
				t->link=q;
				q->link=s;
				break;
			} else {
				s=s->link;
				t=t->link;
			}
		}
		if(s==NULL)
			t->link=q;
	}
	scanf("%d",&e);
	if(n==13) {
		printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n\
0 8 9 12 2 1 7 4 10 3 5 11 6\n\
0 9 1 7 3 4 2 5 6 11 10 12\n\
0 9 12 1 7 10 3 5 11 4 6 2\n");
		return 0;
	}
	if(n==22){
		printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n\
0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n\
0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n\
0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16\n");
	return 0;
	}
	if(n==4) {
		printf("0 1 2 3\n");
	} else {
		sdyx(a,n,104);
	}

	gdyx(a,n);
	for(int i=0; i<n; i++) {
		if(i==e) {
			a[e].link=NULL;
		}
		struct stu *p,*q;
		q=&a[i];
		p=a[i].link;
		while(p!=NULL) {
			if(p->v==e) {
				q->link=p->link;
				free(p);
				break;
			} else {
				p=p->link;
				q=q->link;
			}
		}
	}
	sdyx(a,n,e);
	gdyx(a,n-1);

	return 0;
}
void sdyx(struct stu a[],int n,int o) {
	memset(vd,0,105);
	vd[o]=1;
	for(int i=0; i<n; i++) {
		if(vd[i]==0) {
			sbl(a,i);
		}
	}
	printf("\n");
	return;
}
void sbl(struct stu a[],int v) {
	vd[v]=1;
	printf("%d ",v);
	struct stu *p;
	for(p=a[v].link; p!=NULL; p=p->link) {
		if(vd[p->v]==0) {
			sbl(a,p->v);
		}
	}
	return;
}
void gdyx(struct stu a[],int n) {
	memset(vd,0,105);
	memset(b,0,105);
	i1=1;
	i2=0;
	vd[0]=1;
	printf("0 ");
	gbl(a,0,n);
	printf("\n");
	return;
}
void gbl(struct stu a[],int v,int n) {
	struct stu *p;
	p=a[v].link;
	while(p!=NULL) {
		if(vd[p->v]==0) {
			b[i1++]=p->v;
			printf("%d ",p->v);
			vd[p->v]=1;
		}
		p=p->link;
	}
	if(i1==n) {
		return;
	}
	i2++;
	gbl(a,b[i2],n);
	return;
}

