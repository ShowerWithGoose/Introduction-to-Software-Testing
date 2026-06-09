#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int sum[100],sam[100],j=0,w,i,s=0;
int main() {
	char x[100],y[100];
	gets(x);
	for(i=0; x[i]!='\0'; i++) {
		if(x[i]>='0'&&x[i]<='9') {
			sum[j]+=x[i]-'0';
			for(; x[i+1]>='0'&&x[i+1]<='9'; i++) {
				sum[j]=(sum[j])*10+x[i+1]-'0';
			}
			j++;
		}
	}
	gets(y);
	for(i=0; y[i]!='\0'; i++) {
		if(y[i]>='0'&&y[i]<='9') {
			sam[s]+=y[i]-'0';
			for(; y[i+1]>='0'&&y[i+1]<='9'; i++) {
				sam[s]=(sam[s])*10+y[i+1]-'0';
			
			}
			s++;
		}
	}
	struct node {
		int xishu;
		int zhishu;
		struct node*next;
	};
	struct node *p,*r,*list=NULL;
	for(i=0; i<j; i++) {
		p=(struct node *)malloc(sizeof(struct node));
		p->xishu=sum[i];
		i++;
		p->zhishu=sum[i];
		p->next=NULL;
		if(list==NULL) {
			list=p;
		} else {
			r->next=p;
		}
		r=p;
	}
	struct node *p1,*r1,*list1=NULL;
	for(i=0; i<s; i++) {
		p1=(struct node *)malloc(sizeof(struct node));
		p1->xishu=sam[i];
		i++;
		p1->zhishu=sam[i];
		p1->next=NULL;
		if(list1==NULL) {
			list1=p1;
		} else {
			r1->next=p1;
		}
		r1=p1;
	}
	struct node *p2,*r2,*list2=NULL,*pp;
	pp=list1;
	int k,t;
	for(i=0; i<(j+1)/2; i++) {
		for(k=0;k<(s+1)/2;k++)
		{ 
			p2=(struct node *)malloc(sizeof(struct node));
			p2->xishu=(pp->xishu)*(list->xishu);
			p2->zhishu=(pp->zhishu)+(list->zhishu);
			p2->next=NULL;
			pp=pp->next;
			if(list2==NULL) {
				list2=p2;
			} else {
				r2->next=p2;
			}
			r2=p2;
		}
		list=list->next;
		pp=list1;
	}
	struct node *p3=NULL,*p4=NULL,*p5=NULL;
	p3=list2;
	while(p3!=NULL){
		p5=p3;
		p4=p3->next;
		while(p4!=NULL){
			if(p3->zhishu<p4->zhishu){
				t=p3->zhishu;
				p3->zhishu=p4->zhishu;
				p4->zhishu=t;
				t=p3->xishu;
				p3->xishu=p4->xishu;
				p4->xishu=t;
			}
			else if(p3->zhishu==p4->zhishu){
				p3->xishu=p3->xishu+p4->xishu;
				p5->next=p4->next;
			}
			p5=p4;
			p4=p4->next;
		}
		p3=p3->next;
	}
	
	while(list2!=NULL){
		printf("%d %d ",list2->xishu,list2->zhishu);
		list2=list2->next;
	}
	return 0;
}

