#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long

typedef struct Node {
	int xs,zs;
	struct Node *next;
} node,*list;

typedef struct Num{
	int xs,zs,ok;
}num; 

num n[1000];

int cmp(const void* a,const void* b) 
{
	node *c=(node*)a,*d=(node*)b;
	if(c->zs<d->zs)	return 1;
	if(c->zs>d->zs)	return -1;
	return 0;
}

list buildlist() {//¶Áµ½»Ø³µÍ£ 
	int a,b;
	char c;
	list head=NULL,p,q=NULL;
	while(scanf("%d%d%c",&a,&b,&c)) {

		p=(list)malloc(sizeof(node));
		p->xs =a;
		p->zs =b;
		p->next =NULL;
		if(head==NULL) {
			head=q=p;
		} else {
			q->next =p;
			q=p;
		}
		if(c=='\n') {
			p->next =NULL;
			break;
		}
	}
	return head;
}

int main() {
	int i=0,j,k;
	list h1=buildlist(),h2=buildlist();
	list p1,p2;
	for(p1=h1;p1!=NULL;p1=p1->next ){
		for(p2=h2;p2!=NULL;p2=p2->next ){
			n[i].xs =p1->xs *p2->xs ;
			n[i].zs =p1->zs +p2->zs ;
			i++;
		}
	}
	for(j=0;j<i;j++)
	{
		if(n[j].ok )continue;
		for(k=j+1;k<i;k++){
			if(n[k].ok)continue;
			if(n[k].zs ==n[j].zs )
			{
				n[j].xs+=n[k].xs ;
				n[k].ok =1;
			}
		}
	}
	qsort(n,i,sizeof(num),cmp);
	for(j=0;j<i;j++){
		if(n[j].ok ==0){
			printf("%d %d ",n[j].xs ,n[j].zs );
		}
	}
	return 0;
}

