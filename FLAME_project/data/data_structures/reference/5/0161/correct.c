#include<stdio.h>
#include<stdlib.h>

struct x{
	long long num,exp;
	struct x *next;
};
typedef struct x term;
typedef struct x *termptr;

termptr in(termptr head,long long a,long long b){
	termptr p,q,r;
	r=(termptr)malloc(sizeof(term));
	r->num=a;
	r->exp=b;
	r->next=NULL;
	if(head==NULL)
	return r;
	for(p=head;p!=NULL&&p->exp>b;q=p,p=p->next);
	if(p!=NULL&&p->exp==b){
		p->num=p->num+a;
		return head;
	}
	else if(p==head){
		r->next=head;
		return r;
	}
	else{
		q->next=r;
		r->next=p;
		return head;
	}
}
int main()
{
	long long n,m,i=0;
	termptr p,q,list=NULL,head=NULL;
	while(scanf("%lld%lld",&n,&m)!=EOF){
		i++;
		q=(termptr)malloc(sizeof(term));
		q->num=n;
		q->exp=m;
		q->next=NULL;
		if(list==NULL)
		list=p=q;
		p->next=q;
		p=q;
		if(i==1) list->next=NULL; 
		if(getchar()=='\n') break;
	}
	while(scanf("%lld%lld",&n,&m)!=EOF){
		for(p=list;p!=NULL;p=p->next)
		head=in(head,n*p->num,m+p->exp);
		if(getchar()=='\n') break;
	}
	for(p=head;p!=NULL;p=p->next)
	printf("%lld %lld ",p->num,p->exp);
	return 0;
}

