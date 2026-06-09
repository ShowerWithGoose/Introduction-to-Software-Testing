#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
		int data;
		int hang;
		struct node*lchild,*rchild;
	};
int a[100];
struct node*p=NULL,*r=NULL,*rr=NULL;
struct node* f(struct node*p,int data,int hang){
	if(p==NULL){
		p=(struct node*)malloc(sizeof(struct node));
	    p->data=data;
	    p->hang=hang;
	    p->lchild=NULL;
	    p->rchild=NULL;
	    r=p;
	}
	else if(data<p->data){
		hang++;
		p->lchild=f(p->lchild,data,hang);
	}
	else if(data>=p->data){
		hang++;
		p->rchild=f(p->rchild,data,hang);
	}
	return p;
}
void g(struct node*p){
	if(p!=NULL){
		/*if(p->lchild!=NULL){
			g(p->lchild);
		}
		if(p->rchild!=NULL){
			g(p->rchild);
		}*/
		if(p->lchild==NULL&&p->rchild==NULL){
			printf("%d %d\n",p->data,p->hang);
		} 
		g(p->lchild);
		g(p->rchild);
	}
}
int main (){
	int n,i,w;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		w=1;
		p=f(p,a[i],w);
	}
	g(p);
	/*for(i=1;i<=n;i++){
		p=(struct node*)malloc(sizeof(struct node));
		p->data=a[i];
		p->hang=w;
		if(r==NULL){
			r=p;rr=r;
		}
		else if(p->data<r->data){
			while(r->lchild!=NULL){
				r=r->lchild;
			}
		}
	}*/
	return 0;
}

