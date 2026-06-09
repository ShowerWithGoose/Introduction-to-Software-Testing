#include<stdio.h>
#include<stdlib.h>
struct list{
	int no;
	int exp;
	struct list* next;
};
typedef struct list* L;
int main(){
	int a,n,time=0,k=0,l1,l2;
	L pp,qq,p,p2,head=NULL,headd=NULL,listo=NULL;
	while(1){
		scanf("%d %d",&a,&n);
		qq=(L)malloc(sizeof(struct list));
		qq->no=a;
		qq->exp=n;
		qq->next=NULL;
		if(head==NULL)
			head=pp=qq;
		else
			pp->next=qq;
		pp=qq;
		time++;
		if(getchar()=='\n')
			break;
	}
	p=head;
	while(1){
		scanf("%d %d",&a,&n);
		qq=(L)malloc(sizeof(struct list));
		qq->no=a;
		qq->exp=n;
		qq->next=NULL;
		if(headd==NULL)
			headd=pp=qq;
		else
			pp->next=qq;
		pp=qq;
		k++;
		if(getchar()=='\n')
			break;
	}
	p2=headd;
	qq=(L)malloc(sizeof(struct list));
	qq->no=0;
	qq->exp=2147483647;
	pp=(L)malloc(sizeof(struct list));
	pp->no=0;
	pp->exp=0;
	pp->next=NULL;
	qq->next=pp;
	listo=qq;
	for(l1=0;l1<time;l1++){
		for(l2=0,p2=headd;l2<k;l2++){
			a=(p->no)*(p2->no);
			n=(p->exp)+(p2->exp);
			p2=p2->next;
			pp=listo;
			while(pp!=NULL){
				if(pp->exp==n){
					pp->no+=a;
					break;
					}
				else if(pp->exp>n&&pp->next->exp<n){
					qq=(L)malloc(sizeof(struct list));
					qq->no=a;
					qq->exp=n;
					qq->next=pp->next;
					pp->next=qq;
					break;
				}
				pp=pp->next;
			}
		}
		p=p->next;
	}
	for(qq=listo;qq!=NULL;qq=qq->next){
		if(qq->no!=0){
			printf("%d %d ",qq->no,qq->exp);
		}
	}
	return 0;
}

