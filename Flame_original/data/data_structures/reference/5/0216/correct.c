#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct _dxs{
	int xs;
	int zs;
	struct _dxs *link;
} dxs; 
typedef dxs *dxsp;
int main(){
	dxsp list1,list2,list3,p,q;int flag=1;
	list1=(dxsp)malloc(sizeof(dxs));
	list2=(dxsp)malloc(sizeof(dxs));
	list3=(dxsp)malloc(sizeof(dxs));
	p=list1;p->link=NULL;
	while(flag){
		q=(dxsp)malloc(sizeof(dxs));
		scanf("%d %d",&q->xs,&q->zs);
		p->link=q;p=q;
		if(getchar()=='\n') flag=0;
	}
	p=list2;p->link=NULL;
	while(!flag){
		q=(dxsp)malloc(sizeof(dxs));
		scanf("%d %d",&q->xs,&q->zs);
		p->link=q;p=q;
		if(getchar()=='\n') flag=1;
	}
	p=list3;p->link=NULL;
	for(dxsp i=list1->link;i!=NULL;i=i->link){
		for(dxsp j=list2->link;j!=NULL;j=j->link){
			int f=1;
			q=(dxsp)malloc(sizeof(dxs));
			q->xs=i->xs*j->xs;
			q->zs=i->zs+j->zs;
			q->link=NULL; 
			for(dxsp m=list3,k=list3->link;k!=NULL;k=k->link,m=m->link){
				if(k->zs<q->zs){
					m->link=q;q->link=k;f=0;break;
				}
				else if(k->zs==q->zs){
					k->xs+=q->xs;f=0;break;
				}
			}
			if(f) {
			p->link=q;
			p=q;} 
		}		
	}
	for(dxsp i=list3->link;i!=NULL;i=i->link){
		if(i->xs==0) continue;
		printf("%d %d ",i->xs,i->zs);
	}
	return 0;
}




