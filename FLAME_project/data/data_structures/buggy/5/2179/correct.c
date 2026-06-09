#include <string.h>
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
struct a{
		long long xi;
		long long zhi;
		struct a*next;
	};
typedef struct a*aap;
typedef struct a aa;
aap f(aap head,long long xi,long long zhi){
	aap r=NULL;
	r=(aap)malloc(sizeof(aa));
	r->xi=xi;r->zhi=zhi;
	r->next=NULL;
	if(head==NULL){
		return r;
	}
	aap p=NULL;
	aap q=NULL;
	for(p=head;p!=NULL&&p->zhi>zhi;q=p,p=p->next);
	if(p==head){
		r->next=p;
		head=r;
	}
	if(p!=NULL&&p->zhi==zhi){
		p->xi+=xi;
	}
	else{
		q->next=r;
		r->next=p;
	}
	return head;
}
int main(){
	long long xi,zhi;
	aap x1=NULL,x2=NULL;char c;
	while(1){
		scanf("%lld%lld",&xi,&zhi);
		c=getchar();
		x1=f(x1,xi,zhi);
		if(c!=' ') break;
	}
	aap g;
	while(scanf("%lld%lld",&xi,&zhi)!=EOF){
		for(g=x1;g!=NULL;g=g->next){
				x2=f(x2,(g->xi)*xi,(g->zhi)+zhi);
			}
	}
	for(g=x2;g!=NULL;g=g->next){
		if(g->xi!=0){
			printf("%lld %lld ",g->xi,g->zhi);
		}
	}
} 

