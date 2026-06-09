#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct multi{
	struct multi *former;
	int a;
	int x;
	struct multi *next;
}list;
struct basic{
	int b;
	int c;
}x1[10],x2[10];
int main(){
	int i=0,n=0,m=0,j=0,k;
	char d;
	do{
		scanf("%d %d",&x1[i].b,&x1[i].c);
		i++;
		n++;
		d=getchar();
	}while(d==' ');
	i=0;
	do{
		scanf("%d %d",&x2[i].b,&x2[i].c);
		i++;
		m++;
		d=getchar();
	}while(d==' ');
	list *lll=NULL,*p=NULL,*q,*r;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			k=(x2[i].c)+(x1[j].c);
			if(p!=NULL){
				for(p=lll;p->next!=NULL&&k<p->x;p=p->next){
				}
				if(p->next==NULL){
					if(k<p->x){
						q=(list*)malloc(sizeof(list));
						p->next=q;
						q->former=p;
						p=q;
						p->x=k;
				        p->a=(x2[i].b)*(x1[j].b);
				        p->next=NULL;
					}else{
						if(k==p->x){
						    p->a=p->a+(x2[i].b)*(x1[j].b);
					    }if(k>p->x){
						    q=(list*)malloc(sizeof(list));
						    r=p->former;
						    q->next=r->next;
						    q->former=r;
						    r->next=q;
						    q->x=k;
						    q->a=(x2[i].b)*(x1[j].b);
					        p->former=q;
					    }}
				}else{
					if(k==p->x){
						p->a=p->a+(x2[i].b)*(x1[j].b);
					}if(k>p->x){
						q=(list*)malloc(sizeof(list));
						r=p->former;
						q->next=r->next;
						q->former=r;
						r->next=q;
						q->x=k;
						q->a=(x2[i].b)*(x1[j].b);
						p->former=q;
					}
				}
			}else{
				p=(list*)malloc(sizeof(list));
				lll=p;
				p->x=k;
				p->a=(x2[i].b)*(x1[j].b);
				p->next=NULL;
				p->former=NULL;
			}
		}
	}for(p=lll;p!=NULL;p=p->next){
		printf("%d %d ",p->a,p->x);
	}
	return 0;
} 

