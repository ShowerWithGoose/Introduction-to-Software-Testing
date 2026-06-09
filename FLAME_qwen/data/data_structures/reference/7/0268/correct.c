#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
#define stmalloc(p) (struct p*)malloc(sizeof(struct p))

st tree{
	int num;
	st tree* le;
	st tree* ri;
	int ht;
	int ljud;
	int rjud;
}*t,*p;

void put(st tree* t){
	if(t->ljud!=1&&t->rjud!=1){
		pr("%d %d\n",t->num,t->ht);
	}
	else{
		if(t->ljud==1) put(t->le);
		if(t->rjud==1) put(t->ri);
	}
	return ;
}

int main(){
	int i,tem,rech=0,n;
	t=stmalloc(tree);
	p=stmalloc(tree);
	in(n);
	in(t->num);
	t->ht=1;
	p=t;
fr(i,0,n-1){
	rech=1;
	p=t;
	in(tem);
	A:
	while(tem<p->num){
		if(p->ljud==1){
			p=p->le;
			rech++;
			goto A;
		}
		else{
			p->le=stmalloc(tree);
			p->ljud=1;
			p=p->le;
			p->num=tem;
			p->ht=rech+1;
			tem--;
			break;
		}
	}
	while(tem>=p->num){
		if(p->rjud==1){
			p=p->ri;
			rech++;
			goto A;
		}
		else{
			p->ri=stmalloc(tree);
			p->rjud=1;
			p=p->ri;
			p->num=tem;
			p->ht=rech+1;
			break;
		}
	}
}
put(t);
return 0;
}

