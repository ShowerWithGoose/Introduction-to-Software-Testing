#include <stdio.h>
#include <stdlib.h>
struct tree{
	int num;
	struct tree *lch;
	struct tree *rch;
	int height;
};
typedef struct tree TREE;
typedef struct tree* TREEE;
void judge(TREEE a,TREEE b,int hei){
	if(a->num>=b->num){
		if(b->rch!=NULL){
			judge(a,b->rch,hei+1);
		}else{
			b->rch=a;
			a->height=hei+1;
		}
		
	}else{
		if(b->lch!=NULL){
			judge(a,b->lch,hei+1);
		}else{
			b->lch=a;
			a->height=hei+1;
		}
	}
}
void print(TREEE a){
	if(a!=NULL){
		if(a->lch==NULL&&a->rch==NULL){
			printf("%d %d\n",a->num,a->height);
		}
		print(a->lch);
		print(a->rch);
	}
}
TREEE a[1000];
TREEE head;
int main(){
	int i;
	a[0]=(TREEE)malloc(sizeof(TREE));
	a[0]->lch=a[0]->rch=NULL;
	scanf("%d",&i);
	scanf("%d",&a[0]->num);
	a[0]->height=1;
	int tmp=1;
	for(tmp=1;tmp<i;tmp++){
		a[tmp]=(TREEE)malloc(sizeof(TREE));
		a[tmp]->lch=a[tmp]->rch=NULL;
		scanf("%d",&a[tmp]->num);
		judge(a[tmp],a[0],1);
	}
	print(a[0]);
	return 0;
}

