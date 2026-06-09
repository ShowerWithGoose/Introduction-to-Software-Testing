#include<stdio.h> 
#include<string.h> 
#include<stdlib.h>
struct num{
	int x;
	int z;
	struct num *next;
};
int main()
{
	int a,b,i,j,xn=0,yn=0;
	char c;
	struct num *p,*q,*first=NULL,*tail,*f=NULL,*t,*p2,*f2=NULL,*t2,*k,*g;
	while(1){
		scanf("%d%d",&a,&b);
		scanf("%c",&c);
		p=(struct num *)malloc(sizeof(struct num));
		p->x=a;
		p->z=b;
		p->next=NULL;
		if(first==NULL)
		  first=tail=p;
		else{
			tail->next=p;
			tail=tail->next; 
		}
		xn++;
		if(c=='\n')
		  break;
	}
	while(1){
		scanf("%d%d",&a,&b);
		scanf("%c",&c);
		q=(struct num *)malloc(sizeof(struct num));
		q->x=a;
		q->z=b;
		q->next=NULL;
		if(f==NULL)
		  f=t=q;
		else{
			t->next=q;
			t=t->next; 
		}
		yn++;
		if(c=='\n')
		  break;
	}
	p=first;
	q=f;
	int js=0;
	while(1){
		p2=(struct num *)malloc(sizeof(struct num));
		p2->x=(p->x)*(q->x);
		p2->z=(p->z)+(q->z);
		js++;
		p2->next=NULL;
		if(f2==NULL)
		  f2=t2=p2;
		else{
			t2->next=p2;
			t2=t2->next; 
		}
		if(q->next==NULL&&p->next!=NULL){
			p=p->next;
			q=f;
		}
		else if(p->next==NULL&&q->next==NULL){
			break;
		}
		else{
			q=q->next;
		}
	}
	int tp,tk=0;
	p2=f2;
	for(i=0;i<js-1;js++){
	  p2=f2;
	  tk=0;
	  while(p2->next!=NULL){
		if((p2->z)<(p2->next->z)){
			tp=p2->x;
			p2->x=p2->next->x;
			p2->next->x=tp;
			tp=p2->z;
			p2->z=p2->next->z;
			p2->next->z=tp;
			tk++;
		}
		p2=p2->next;
	  }	
	  if(tk==0)
	    break;
	}
	p2=f2;	
	while(p2->next!=NULL){
		if(p2->z==p2->next->z){
			p2->x=p2->x+p2->next->x;
			k=p2->next;
			p2->next=k->next;
			free(k);
		}
		else
		  p2=p2->next;
	}
	p2=f2;
	while(p2!=NULL){
		printf("%d %d ",p2->x,p2->z);
		g=p2;
		p2=p2->next;
		free(g);
	}
	printf("\n");
	p=first;
	while(p!=NULL){
		g=p;
		p=p->next;
		free(g);
	}
	q=f;
	while(q!=NULL){
		g=q;
		q=q->next;
		free(g);
	}
	return 0;
} 

