#include<stdio.h>
#include<stdlib.h>
struct list{
	int no;
	int exp;
	struct list* next;
};
typedef struct list* L;
int main(){
	int pp,qq,i1=0,i2=0,l1,l2;
	L p,q,p1,p2,list1=NULL,list2=NULL,listo=NULL;
	while(1){
		scanf("%d %d",&pp,&qq);
		q=(L)malloc(sizeof(struct list));
		q->no=pp;
		q->exp=qq;
		q->next=NULL;
		if(list1==NULL)
			list1=p=q;
		else
			p->next=q;
		p=q;
		i1++;
		if(getchar()=='\n')
			break;
	}
	p1=list1;
	while(1){
		scanf("%d %d",&pp,&qq);
		q=(L)malloc(sizeof(struct list));
		q->no=pp;
		q->exp=qq;
		q->next=NULL;
		if(list2==NULL)
			list2=p=q;
		else
			p->next=q;
		p=q;
		i2++;
		if(getchar()=='\n')
			break;
	}
	p2=list2;
	q=(L)malloc(sizeof(struct list));
	q->no=0;
	q->exp=2147483647;
	p=(L)malloc(sizeof(struct list));
	p->no=0;
	p->exp=0;
	p->next=NULL;
	q->next=p;
	listo=q;
	for(l1=0;l1<i1;l1++){
		for(l2=0,p2=list2;l2<i2;l2++){
			pp=(p1->no)*(p2->no);
			qq=(p1->exp)+(p2->exp);
			p2=p2->next;
			p=listo;
			while(p!=NULL){
				if(p->exp==qq){
					p->no+=pp;
					break;
					}
				else if(p->exp>qq&&p->next->exp<qq){
					q=(L)malloc(sizeof(struct list));
					q->no=pp;
					q->exp=qq;
					q->next=p->next;
					p->next=q;
					break;
				}
				p=p->next;
			}
		}
		p1=p1->next;
	}
	for(q=listo;q!=NULL;q=q->next){
		if(q->no!=0){
			printf("%d %d ",q->no,q->exp);
		}
	}
	return 0;
}

