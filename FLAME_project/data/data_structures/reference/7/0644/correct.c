#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int count;
	struct tree *lchild;
	struct tree *rchild;
} tre,*trepr;
trepr produce(trepr,int);
void find(trepr,int);
int main(){
	int i=0,n,temp;
	scanf("%d",&n);
	trepr list=NULL;
	while(i++<n){
		scanf("%d",&temp);
		list=produce(list,temp);
	}
	trepr t=list;
	int flo=1;
	find(list,flo);
	return 0;
}
trepr produce(trepr p,int n){
	trepr sum;
	sum=(trepr)malloc(sizeof(tre));
	sum->count=n;
	sum->lchild=sum->rchild=NULL;
	if(p==NULL){
		return sum;
	}else{
		if(n<p->count){
			p->lchild=produce(p->lchild,n);
		}else if(n>=p->count){
			p->rchild=produce(p->rchild,n);
		}
	}
	return p;
}
void find(trepr p,int n){
	if(p->lchild==NULL&&p->rchild==NULL){
		printf("%d %d\n",p->count,n);
	}else{
		if(p->lchild!=NULL){
			find(p->lchild,n+1);
		}
		if(p->rchild!=NULL){
			find(p->rchild,n+1);
		}
	}
}

