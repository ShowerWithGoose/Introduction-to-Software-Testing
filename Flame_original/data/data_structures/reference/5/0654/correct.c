//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//struct Px{
//	int coe;
//	int index;
//	struct Px *next;
//	struct Px *link;
//}; 
//struct Px *p;
//struct Px *q;
//char c;
//struct Px* multiple(struct Px *,struct Px*);
//struct Px* plus(struct Px*,struct Px*);
//
//
//int main(){
//struct Px *list=NULL;
//struct Px *liste=NULL;
//struct Px *listm;
//	while(1){
//	q=(struct Px*)malloc(sizeof(struct Px));
//	q->link=NULL;
//	q->next=NULL;
//	scanf("%d%d%c",&q->coe,&q->index,&c);
//	if(c!='\n'){
//	if(list==NULL){
//		list=q;
//		p=q;
//	}
//	else{
//		p->link=q;
//		p->next=q;
//		p=q;
//	}	
//	}
//    else if(c=='\n') {
//    p->link=q;
//    p->next=q;
//	p=q;	
//	break;	
//	}
//	}
//	
//	while(1){
//    q=(struct Px*)malloc(sizeof(struct Px));
//	q->link=NULL;
//	q->next=NULL;
//	scanf("%d%d%c",&q->coe,&q->index,&c);
//	if(c!='\n'){
//		listm=multiple(list,q);
//		liste=plus(listm,liste);
//		
//	}
//	else {
//	listm=multiple(list,q);
//	liste=plus(listm,liste);
//	break;	
//	}
//	}
//for(p=liste;p!=NULL;p=p->link){
//	printf("%d %d ",p->coe,p->index);
//}	
//}
//
//
//struct Px* multiple(struct Px* listfunction,struct Px* q){
//	struct Px* r;
//	struct Px* s; 
//	for(r=listfunction;r!=NULL;r=r->link){
//	r->coe=(r->coe)*(q->coe);
//	r->index=(r->index)+(q->index);	
//	}
//return listfunction;
//}
//
//
//struct Px* plus(struct Px* listfunction, struct Px* listfunction0){
//struct Px* r;
//struct Px* t;
//struct Px* t0;
//	if(listfunction0==NULL){
//		return listfunction;
//	}
//	else{
//		for(r=listfunction;r!=NULL;r=r->link){
//			for(t=listfunction0;t!=NULL;t0=t,t=t->link){
//				if(r->index > t->index){
//					t0->link=r;
//					r->link=t;
//					break;
//				}
//				else if(r->index==t->index){
//					t->coe+=r->coe;
//					break;
//				}
//			}
//		}
//		return listfunction0;
//	}
//}这个办法用单项乘再加，但在乘的过程中，list会被改变，无法持续进行
//应考虑用两个链表存多项式，并存入新链表（边存边建）
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Px{
	int coe;
	int index;
	struct Px* link;
}; 
struct Px *P1;
struct Px *P2;
struct Px *p0;
struct Px *P;
char c;
struct Px *q;
struct Px *p; 
struct Px *i;
struct Px *j; 
int main(){
	while(1){
	q=(struct Px*) malloc (sizeof(struct Px));
	q->link=NULL;
	scanf("%d%d%c",&q->coe,&q->index,&c);
	if(c!='\n'){
	if(P1==NULL){
		P1=q;
		p=q;
	}
	else{
		p->link=q;
		p=q;
	}	
	}
    else if(P1!=NULL){
    p->link=q;
	p=q;	
	break;	
	}
	else if(P1==NULL){//注意输入第二种也有两种 
		P1=q;
		p=q;
		break;
	}
	}//第一个多项式 
	
	while(1){
    struct Px* q=(struct Px*)malloc(sizeof(struct Px));
	q->link=NULL;
	scanf("%d%d%c",&q->coe,&q->index,&c);
	if(c!='\n'){
	if(P2==NULL){
		P2=q;
		p=q;
	}
	else{
		p->link=q;
		p=q;
	}	
	}
    else if(P2!=NULL){
    p->link=q;
	p=q;	
	break;	
	}
	else if(P2==NULL){
		P2=q;
		p=q;
		break;
	}
	}//第二个多项式
	
struct Px*	q0=(struct Px*)malloc(sizeof(struct Px));
	q0->link=NULL;
	q0->index=(P1->index)+(P2->index);
	q0->coe=(P1->coe)*(P2->coe);
	P=q0;
	
struct Px*q1=(struct Px*)malloc(sizeof(struct Px));
	q1->link=NULL;
	if(P2->link!=NULL){
	q1->index=(P1->index)+(P2->link->index);
	q1->coe=(P1->coe)*(P2->link->coe);
	P->link=q1;		
	}
	else {
	printf("%d %d ",P->coe,P->index);	
	return 0;
	}
	

	
	for(i=P1;i!=NULL;i=i->link){
		for(j=P2;j!=NULL;j=j->link){
			if(!(i==P1 && (j==P2 || j==P2->link))){
			struct Px*	q2=(struct Px*)malloc(sizeof(struct Px));
				q2->link=NULL;
				q2->index=(i->index)+(j->index);
	            q2->coe=(i->coe)*(j->coe);
			for(p=P;p!=NULL;p0=p,p=p->link){
				if(q2->index==p->index) {
				p->coe+=q2->coe;
				break;
				}
				else if(q2->index>p->index){
					p0->link=q2;
					q2->link=p;
					break;
				}
			}
			if(p==NULL){//p0指向最后一个 
				p0->link=q2;
			}		
			}
		}
	}
	for(p=P;p!=NULL;p=p->link){
		printf("%d %d ",p->coe,p->index);
	}
}

