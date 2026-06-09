#include<stdio.h>
#include<stdlib.h>
struct node{
	int xishu;
	int cishu;
	struct node* next;
	struct node* fore;
};
void add(struct node*,int,int);
void lprintf(struct node* list);
int main(){
	int a[1000][5]={{0}},i=1,j=1,cs,xs;
	struct node* list=(struct node*)malloc(sizeof(struct node));
	list->cishu=list->xishu=0;
	list->fore=list->next=NULL;
	do{
		scanf("%d%d",&a[i][1],&a[i][2]);
		i++;
		
	}while(getchar()!='\n');
	do{
		scanf("%d%d",&xs,&cs);
		for(j=1;j<i;j++){
			add(list,xs*a[j][1],cs+a[j][2]);
		}
	}while(getchar()!='\n');
	lprintf(list);
	return 0;
}
void add(struct node* list,int xs,int cs){
	struct node* first=list;
	struct node* p=(struct node*)malloc(sizeof(struct node));
	for(;first->fore!=NULL;first=first->fore);
	for(;first->cishu>cs;first=first->next){
		if(first->next==NULL){
			first->next=p;
			p->fore=first;
			p->next=NULL;
			p->cishu=cs;
			p->xishu=xs;
			return;
		}
	}
	if(first->cishu==cs){
		first->xishu+=xs;
		return;
	}
	p->cishu=cs;
	p->xishu=xs;
	p->next=first;
	p->fore=first->fore;
	if(first->fore!=NULL)first->fore->next=p;
	first->fore=p;
}
void lprintf(struct node* list){
	struct node *p=list;
	for(;p->fore!=NULL;p=p->fore);
	for(;p!=NULL;p=p->next)if(p->xishu!=0)printf("%d %d ",p->xishu,p->cishu);
}

