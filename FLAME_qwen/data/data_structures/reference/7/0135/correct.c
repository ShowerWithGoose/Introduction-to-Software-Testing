#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

typedef struct list{
	int data;
	int high;
	struct list* lnext;
	struct list* rnext;
}NODE;

NODE *root;
int n0,n1,t,i,high_temp;

NODE *Binary(NODE *p,int item){
	high_temp++;
	if(p==NULL){
		p = (NODE *)malloc(sizeof(NODE));
		p->data = item;
		p->lnext=p->rnext=NULL; 
	}
	else if(item<p->data){
		p->lnext = Binary(p->lnext,item);
	}
	else if(item>=p->data){
		p->rnext = Binary(p->rnext,item);
	}
	p->high = high_temp;
	return p;
}

void print(NODE *p){
	if(p->lnext==NULL&&p->rnext==NULL) printf("%d %d\n",p->data,p->high);
	else{
		if(p->lnext!=NULL) print(p->lnext);
		if(p->rnext!=NULL) print(p->rnext);
	}
}

int main(){
	scanf("%d",&n0);
	n1 = n0;
	while(n1--){
		scanf("%d",&t);
		root = Binary(root,t);
		high_temp=0;
	}
	print(root);
	return 0;
}

