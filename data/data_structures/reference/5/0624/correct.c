#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

typedef struct item{
	int an;
	int n;
	struct item*link;
} ITEM;
void voice(ITEM*p){
	if(p==NULL)return;
	voice(p->link);
	printf("%d %d ",p->an,p->n);
}
int main(){
	char ch;
	int a,b;
	ITEM*p,*q=NULL,*r1,*r2,*r3=NULL,*r;
	do{
		scanf("%d%d",&a,&b);
		p=malloc(sizeof(ITEM));
		p->link=q;
		p->an=a;
		p->n=b;
		q=p;
	}while(getchar()!='\n');
	r1=p,q=NULL;
	do{
		scanf("%d%d",&a,&b);
		p=malloc(sizeof(ITEM));
		p->link=q;
		p->an=a;
		p->n=b;
		q=p;
	}while(getchar()!='\n');
	r2=p;
	while(r1!=NULL){
		for(p=r2;p!=NULL;p=p->link){
			a=r1->an*p->an,b=r1->n+p->n;
			if(r3==NULL)r3=malloc(sizeof(ITEM)),r3->an=a,r3->n=b,r3->link=NULL;
			else {
				for(q=r3;q!=NULL&&b>q->n;q=q->link)r=q;
				if(q==r3)r3=malloc(sizeof(ITEM)),r3->an=a,r3->n=b;
				else if(q==NULL)q=r->link=malloc(sizeof(ITEM)),q->an=a,q->n=b,q->link=NULL;
				else {
					if(b==q->n)q->an+=a;
					else q=malloc(sizeof(ITEM)),q->an=a,q->n=b,q->link=r->link,r->link=q;
				}
			}
		}
		r1=r1->link;
	}
	voice(r3);
	return 0;
}

