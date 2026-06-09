#include<stdio.h>
#include<stdlib.h>
struct lian{
	int dd;
	struct lian *next;
};
struct tou{
	int v;
	struct lian *link;
};
int dui[100]={0};
int head=0,rail=0;
int j=0,m=0,n=0;
struct tou tu[100]={0};
void sc0(struct lian *t,int s){
	while(t->next!=NULL&&t->next->dd!=s){
		if(t->next==NULL){
			break;
		}
		else t=t->next;
	}
	if(t->next!=NULL&&t->next->next!=NULL){
		t->next=t->next->next;	
	}
	else if(t->next!=NULL) t->next=NULL;
	
}
void SC1(struct lian *t,int s){
	while(t!=NULL){
		sc0(tu[t->dd].link,s);
		if(t->next!=NULL){
			t=t->next;
		}
		else break;
	}
}

void cr(struct lian *l,int k){
	if(l->next==NULL){
		struct lian *p;
		p=(struct lian *)malloc(sizeof(struct lian ));
		p->dd=k;
		p->next=NULL;
		l->next=p;
	}
	else cr(l->next,k);
}
void px(struct lian *q){
	struct lian *p0=q;
	struct lian *q0=q;
	for(p0=q;p0!=NULL;p0=p0->next){
		for(q0=p0->next;q0!=NULL;q0=q0->next){
			if(q0->dd<p0->dd){
				int temp=p0->dd;
				p0->dd=q0->dd;
				q0->dd=temp;
			}
		}
	}
}
void print(struct lian *l,int p,int vi[]){
	if(vi[p]==0){
		printf("%d ",p);
		vi[p]=1;
	}
	if(l!=NULL&&vi[l->dd]==0){
		printf("%d ",l->dd);
		vi[l->dd]=1;
		print(tu[l->dd].link,l->dd,vi);
	}
	else if(l==NULL){
		return;
	}
	print(l->next,p,vi);
}
void rd(struct lian *l,int v[],int i){
	if(v[i]!=2){
		dui[rail++]=i;
		v[i]=2;
	}
	if(v[l->dd]!=2){
		dui[rail++]=l->dd;
		v[l->dd]=2;
	}
	if(l->next!=NULL){
		rd(l->next,v,i);
	}
}
void pt(struct lian *l,int v[],int i){
	rd(l,v,i);
	while(head<rail){
		printf("%d ",dui[head]);
		rd(tu[dui[head]].link,v,dui[head]);
		head++;
	}
}
int main(){
	int p=0,q=0,sc=0;
	int vi[100]={0};
	scanf("%d %d",&m,&n);
	int i=0;
	for(i=0;i<n;i++){
		scanf("%d %d",&p,&q);
		tu[p].v=p;
		tu[q].v=q;
		if(tu[p].link==NULL){
			tu[p].link=(struct lian*)malloc(sizeof(struct lian));
			tu[p].link->dd=q;
			tu[p].link->next=NULL;
		}
		else if(tu[p].link!=NULL){
			cr(tu[p].link,q);
		}
		if(tu[q].link==NULL){
			tu[q].link=(struct lian*)malloc(sizeof(struct lian));
			tu[q].link->dd=p;
			tu[q].link->next=NULL;
		}
		else if(tu[q].link!=NULL){
			cr(tu[q].link,p);
		}		
	}
	scanf("%d",&sc);
	/*for(i=0;i<m;i++){
		if(tu[i].link!=NULL){
			px(tu[i].link);
			print1(tu[i].link);
		}

	}*/
	for(i=0;i<m;i++){
		px(tu[i].link);
	}
	for(i=0;i<m;i++){
		print(tu[i].link,i,vi);
	}
	printf("\n");
	for(i=0;i<m;i++){
		vi[i]=1;
	}
	pt(tu[0].link,vi,0);
	printf("\n");
	SC1(tu[sc].link,sc);
	tu[sc].link=NULL;
	
	for(i=0;i<m;i++){
		vi[i]=0;
	}
	vi[sc]=10;
	for(i=0;i<m;i++){
		print(tu[i].link,i,vi);
	}
	printf("\n");
	for(i=0;i<m;i++){
		vi[i]=1;
	}
	vi[sc]=2;
	pt(tu[0].link,vi,0);	
	return 0;
}

