#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct list{
	long long xi,zhi;
	struct list* next;
};
struct node{
	long long xi,zhi;
	struct node *l,*r;
};

struct list* a=NULL;
struct list* b=NULL;
struct node* c=NULL;
struct list* sta=NULL;
struct list* stb=NULL;
struct node* stc=NULL;
void newNode(struct node* temp,int n){
	if(n==0){
		temp->l=(struct node*)malloc(sizeof(struct node));
		temp=temp->l;
	}else{
		temp->r=(struct node*)malloc(sizeof(struct node));
		temp=temp->r;		
	}
	temp->l=temp->r=NULL;
	temp->xi=temp->zhi=0;
}
void insert(long long xi,long long zhi,struct node* temp){
	struct node* emm=NULL;
	if(temp->xi==0 && temp->zhi==0){
		temp->xi=xi;
		temp->zhi=zhi;
	}else if(zhi==temp->zhi){
		temp->xi+=xi;
	}else if(zhi<temp->zhi){
		if(temp->l==NULL){
			newNode(temp,0);
			temp=temp->l;
			temp->xi=xi;temp->zhi=zhi;
		}else if(temp->l->zhi>=zhi){
			insert(xi,zhi,temp->l);
		}else{
			emm=temp->l;
			newNode(temp,0);
			temp->l->l=emm;
			temp->l->xi=xi;temp->l->zhi=zhi;
		}
	}else{
		if(temp->r==NULL){
			newNode(temp,1);
			temp=temp->r;
			temp->xi=xi;temp->zhi=zhi;			
		}else if(zhi>=temp->r->zhi){
			insert(xi,zhi,temp->r);
		}else{
			emm=temp->r;
			newNode(temp,1);
			temp->r->r=emm;
			temp->r->xi=xi;temp->r->zhi=zhi;
		}
	}
	return;
}

void findNode(struct node *temp){
	if(temp->r!=NULL){
		findNode(temp->r);
	}
	printf("%lld %lld ",temp->xi,temp->zhi);
	if(temp->l!=NULL){
		findNode(temp->l);
	}
	return;
}
int main(){
	a=(struct list*)malloc(sizeof(struct list));
	b=(struct list*)malloc(sizeof(struct list));
	c=(struct node*)malloc(sizeof(struct node));
	sta=a,stb=b,stc=c;
	c->l=c->r=NULL;c->xi=c->zhi=0;
	
	long long xiNum,zhiNum;
	char ch;
	
	while(1){
		scanf("%lld%lld",&xiNum,&zhiNum);
		a->xi=xiNum;a->zhi=zhiNum;
		if((ch=getchar())=='\n')break;
		a->next=(struct list*)malloc(sizeof(struct list));
		a=a->next;
	}
	a->next=NULL;
	a=sta;
	while(1){
		scanf("%lld%lld",&xiNum,&zhiNum);
		b->xi=xiNum;b->zhi=zhiNum;
		if((ch=getchar())=='\n')break;
		b->next=(struct list*)malloc(sizeof(struct list));
		b=b->next;
	}
	b->next=NULL;
	b=stb;
	while(a!=NULL){
		while(b!=NULL){
			xiNum=a->xi * b->xi;
			zhiNum=a->zhi + b->zhi;
			insert(xiNum,zhiNum,stc);
			b=b->next;			
		}
		b=stb;
		a=a->next;
	}
	findNode(stc);
	
	return 0;
}

