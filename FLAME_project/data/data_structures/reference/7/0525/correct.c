#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct tree{
	int num;
	int high;
	struct tree *lchild,*rchild;
};
struct tree* Insert(struct tree *t,int temp,int i){

	if(t==NULL){
		t=(struct tree*)malloc(sizeof(struct tree));
		t->num=temp;
		t->high=i;
		t->lchild=NULL;
		t->rchild=NULL;

	}
	else if(temp<t->num){
		t->lchild=Insert(t->lchild,temp,i+1);
	}
	else if(temp>=t->num){
		t->rchild=Insert(t->rchild,temp,i+1);
	}

	return t;
}

void printtree(struct tree *t){
	if(t->lchild==NULL&&t->rchild==NULL){
		printf("%d %d\n",t->num,t->high);
	}
	if(t->lchild!=NULL){
		printtree(t->lchild);
	}
	if(t->rchild!=NULL){
		printtree(t->rchild);
	}
}

int main(){
	struct tree *p=NULL;
	int n;
	scanf("%d",&n);
	int temp;
	while(n--){
		scanf("%d",&temp);
		p=Insert(p,temp,1);
	}
	printtree(p);
	return 0;
}
