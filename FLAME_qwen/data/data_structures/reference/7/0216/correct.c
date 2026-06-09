#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct _S{
	struct _S *lef;
	struct _S *rig;
	int dat;
	int h;
} shu; 
typedef struct{
	shu* root;
} gen;
void insert(gen* s,int n){
	shu* p=(shu*)malloc(sizeof(shu));
	p->dat=n;
	p->lef=NULL;
	p->rig=NULL;
	p->h=1;
	if(s->root==NULL){
		s->root=p;
	}
	else{
		p->h++;
		shu* q=s->root;
		while(q!=NULL){
			if(n<q->dat){
				if(q->lef==NULL){
					q->lef=p;
					return;
				}
				else {
					p->h++;
					q=q->lef;
				}
			}
            else {
				if(q->rig==NULL){
					q->rig=p;
					return; 
				}
				else {
					p->h++;
					q=q->rig;
				}
			}			
		}
	}
	return;
}
void BL(shu* s){
	if(s!=NULL){
		BL(s->lef);
		if(s->lef==NULL&&s->rig==NULL) printf("%d %d\n",s->dat,s->h);
		BL(s->rig);
	}
	return;
}
int main(){
	int n,m;gen g;
	g.root=NULL;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&m);
		insert(&g,m);
	}
	BL(g.root);
	return 0;
}

