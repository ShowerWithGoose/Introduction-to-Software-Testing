#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dxs{
	int xs;
	int zs;
	struct dxs *link;
};
int main(){
	struct dxs *a=NULL,*b=NULL,*p,*q,*r,*s,*list=NULL,*k,*l;
	int x,z;
	char pd;
	do{
		scanf("%d%d%c",&x,&z,&pd);
		p=(struct dxs*)malloc(sizeof(struct dxs));
		p->xs=x;
		p->zs=z;
		p->link=NULL;
		if(a==NULL){
			a=p;
			q=p;
		}
		else{
		    q->link=p;
		    q=q->link;
		}
	}while(pd!='\n');
	do{
		scanf("%d%d%c",&x,&z,&pd);
		p=(struct dxs*)malloc(sizeof(struct dxs));
		p->xs=x;
		p->zs=z;
		p->link=NULL;
		if(b==NULL){
			b=p;
			q=p;
		}
		else{
		    q->link=p;
		    q=q->link;
		}
	}while(pd!='\n');
	p=a;
	r=a->link;
	q=b;
	s=b->link;
	while(p!=NULL&&q!=NULL){
		if(list==NULL){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=p->xs*q->xs;
			k->zs=p->zs+q->zs;
			k->link=NULL;
			list=k;
			l=k;
			while(r==NULL&&q!=NULL){
				q=q->link;
				r=p->link;
			}
			while(s==NULL&&p!=NULL&&q!=NULL){
				p=p->link;
				s=q->link;
			}
		}
		else if(p->zs+s->zs > q->zs+r->zs){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=p->xs*s->xs;
			k->zs=p->zs+s->zs;
			k->link=NULL;
			l->link=k;
			l=l->link;
			s=s->link;
			while(s==NULL&&p!=NULL){
				p=p->link;
				s=q->link;
			}
		}
		else if(p->zs+s->zs < q->zs+r->zs){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=q->xs*r->xs;
			k->zs=q->zs+r->zs;
			k->link=NULL;
			l->link=k;
			l=l->link;
			r=r->link;
			while(r==NULL&&q!=NULL){
				q=q->link;
				r=p->link;
			}
		}
		else if(p->zs+s->zs==q->zs+r->zs){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=q->xs*r->xs+p->xs*s->xs;
			k->zs=q->zs+r->zs;
			k->link=NULL;
			l->link=k;
			l=l->link;
			s=s->link;
			r=r->link;
			while(s==NULL&&p!=NULL){
				p=p->link;
				s=q->link;
			}
			while(r==NULL&&q!=NULL&&p!=NULL){
				q=q->link;
				r=p->link;
			}
		}
	}
	if(p!=NULL){
		while(s!=NULL){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=p->xs*s->xs;
			k->zs=p->zs+s->zs;
			k->link=NULL;
			l->link=k;
			l=l->link;
			s=s->link;
		}
	}
	if(q!=NULL){
		while(r!=NULL){
			k=(struct dxs*)malloc(sizeof(struct dxs));
			k->xs=q->xs*r->xs;
			k->zs=q->zs+r->zs;
			k->link=NULL;
			l->link=k;
			l=l->link;
			r=r->link;
		}
	}
	l=list;
	k=list;
	while(k->link!=NULL){
		r=list;
		while(r->link!=NULL){
			if(r->zs < r->link->zs){
				x=r->xs;
				z=r->zs;
				r->xs=r->link->xs;
				r->zs=r->link->zs;
				r->link->xs=x;
				r->link->zs=z;
			}
			else if(r->zs==r->link->zs){
				r->xs=r->xs+r->link->xs;
				r->link=r->link->link;
			}
			r=r->link;
		}
		k=k->link;
	}
	while(l->link!=NULL){
		printf("%d %d ",l->xs,l->zs);
		p=l->link;
		free(l);
		l=p;
	}
	printf("%d %d\n",l->xs,l->zs);
	return 0;
}

