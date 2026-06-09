#include<stdio.h>
#include<stdlib.h>

struct tree{
	int a;
	struct tree*lc;
	struct tree*rc;
};

void f(struct tree *,int);

int main()
{
	int n,m=0;
	scanf("%d",&n);
	scanf("%d",&m);
	struct tree *p;
	struct tree *start=(struct tree*)malloc(sizeof(struct tree));
	start->a=m;
	start->lc=NULL;
	start->rc=NULL;
	n--;
	while(n--){
		scanf("%d",&m);
		struct tree *q=(struct tree*)malloc(sizeof(struct tree));
		q->a=m;
		q->lc=NULL;
		q->rc=NULL;
		p=start;
		while(1){
			if(q->a<p->a){
				if(p->lc!=NULL){
					p=p->lc;
				}
				else{
					p->lc=q;
					break;
				}
			}
			else if(q->a>=p->a){
				if(p->rc!=NULL){
					p=p->rc;
				}
				else{
					p->rc=q;
					break;
				}
			}
		}
	}
	f(start,0);
}

void f(struct tree*start,int t)
{
	t++;
	if(start->lc==NULL&&start->rc==NULL){
		printf("%d %d\n",start->a,t);
		return;
	}
	else{
		if(start->lc!=NULL){
			f(start->lc,t);
		}
		if(start->rc!=NULL){
			f(start->rc,t);
		}
		return;
	}
}

