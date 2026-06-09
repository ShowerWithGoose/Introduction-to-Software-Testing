#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct tree{
	int num;
	int cnt;
	struct tree* lp;
	struct tree* rp;
};
typedef struct tree t;
typedef struct tree* pt;
pt s=NULL,p,r;
void visit(pt);
int main(){
	int n,i,a,c=1;
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d",&a);
		r=(pt)malloc(sizeof(t));
		r->num=a;
		r->lp=r->rp=NULL;
		if (s==NULL){
			s=p=r;
			r->cnt=1;	
		}
		else {
			p=s;
			while (1){
				if (a<p->num) {
					if (p->lp==NULL){
						p->lp=r;
						r->cnt=c+1;
						c=1;
						break;
					}
					p=p->lp;
					c++;
				}
				else if (a>=p->num){
					if (p->rp==NULL){
						p->rp=r;
						r->cnt=c+1;
						c=1;
						break;
					}
					p=p->rp;
					c++;
				}
			}
		}
	}
	visit(s);
	return 0;
}

void visit(pt w){
	if (w==NULL) return;
		visit(w->lp);
		visit(w->rp);
	if (w->lp==NULL&&w->rp==NULL){
		printf("%d %d\n",w->num,w->cnt);
	}
}

