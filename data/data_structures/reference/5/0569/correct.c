#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct node{
	int a,x;
	struct node *link;
}node;
node list[100000]; 
int i;

node *in(node *list_){
	list_=&list[i++];
	list_->link=NULL;
	char c=' ';
	while(c!='\n'){
		node *p=&list[i++];
		node *q=list_;
		scanf("%d%d",&p->a,&p->x);
		c=getchar();
		while(q->link!=NULL&&q->link->x>p->x)
			q=q->link;
		if(q->link==NULL||q->link->x<p->x)
			p->link=q->link,q->link=p; 
		else if(q->link->x==p->x){
			q->link->a+=p->a;
			if(q->link->a==0)
				q->link=q->link->link;
		} 
	}
	return list_;
}
node *multi(node *list_a,node *list_b,node *list_c){
	node *p,*q,*a,*b;
	list_c=&list[i++];
	list_c->link=NULL;
	a=list_a->link;
	while(a!=NULL){
		b=list_b->link;
		while(b!=NULL){
			q=list_c;
			p=&list[i++];
			p->x=(a->x)+(b->x);
			p->a=(a->a)*(b->a);
			while(q->link!=NULL&&q->link->x>p->x)
				q=q->link;
			if(q->link==NULL||q->link->x<p->x)
				p->link=q->link,q->link=p;
			else if(q->link->x==p->x){
				q->link->a+=p->a;
				if(q->link->a==0)
					q->link=q->link->link;
			}
			b=b->link;
		}
		a=a->link;
	}
	return list_c;
}
void print(node *list){
	while(list->link!=NULL){
		printf("%d %d ",list->link->a,list->link->x);
		list=list->link;
	}
	return ;
} 
 
int main()
{
	node *list_a,*list_b,*list_c;
	list_a=list_b=list_c=NULL;
	list_a=in(list_a);
	list_b=in(list_b);
	list_c=multi(list_a,list_b,list_c);
	print(list_c);
	return 0;
}


