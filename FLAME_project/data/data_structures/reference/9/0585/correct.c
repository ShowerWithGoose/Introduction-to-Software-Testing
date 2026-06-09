#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define jfb struct line
struct line {
	int l1;
	int l2;
	int c1;
	int c2;
	int count;
	jfb *next
};
int main() {
	int n,max=0;
	int ans=0;
	int a,b,c,d,m1,m2;
	struct line *head, *p,*q,*p0,*xx;
	head=p=NULL;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		ans=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		q=(jfb*)malloc(sizeof(jfb));
		q->l1=a;
		q->l2=b;
		q->c1=c;
		q->c2=d;
		q->count=1;
		q->next=NULL;
		if(head==NULL) head=p=q;
		else {
			for(p=head; p!=NULL; p0=p,p=p->next) {
				if(q->l1==p->c1&&q->l2==p->c2) {
					p->c1=q->c1;
					p->c2=q->c2;
					p->count++;

					ans++;
				}
				if(q->c1==p->l1&&q->c2==p->l2) {
					p->l1=q->l1;
					p->l2=q->l2;
					p->count++;
					ans++;
				}
			}
			if(ans==0) p0->next=q;
			if(ans==2) {
				for(p=head; p!=NULL; p0=p,p=p->next) {
					if(q->l1==p->l1&&q->l2==p->l2) {
						xx=p;
						if(p==head) head=p->next;
						else p0->next=p->next;
						break;
					}
				}
				for(p=head; p!=NULL; p0=p,p=p->next) {
					if(q->c1==p->c1&&q->c2==p->c2) {
						p->c1=xx->c1;
						p->c2=xx->c2;
						p->count=p->count+xx->count-1;
					}
				}
			}
		}
	}
	for(p=head; p!=NULL; p=p->next) {
		if(p->count>max) {
			max=p->count;
			m1=p->l1;
			m2=p->l2;
		}
	}
	printf("%d %d %d",max,m1,m2);
}
