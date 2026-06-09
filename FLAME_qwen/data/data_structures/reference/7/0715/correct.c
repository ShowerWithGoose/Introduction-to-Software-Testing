#include<stdio.h>
#include<stdlib.h>

struct tree{
	int num;
	struct tree *l,*r; 
};

struct tree *getin(struct tree *p,int num){
	struct tree *ptr;
	if(p==NULL){
		ptr=(struct tree*)malloc(sizeof(struct tree));
		ptr->num=num;
		ptr->l=NULL;
		ptr->r=NULL;
		return ptr;
	}
	else if(num<p->num){
		p->l=getin(p->l,num);
		return p;
	}
	else{
		p->r=getin(p->r,num);
		return p;
	}
}

void printleaf(struct tree *p,int high){
	if(p->l!=NULL)
	printleaf(p->l,high+1);
	if(p->r!=NULL)
	printleaf(p->r,high+1);
	if(p->l==NULL&&p->r==NULL)
	printf("%d %d\n",p->num,high);
}

int main()
{
	struct tree *p=NULL;
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int num;scanf("%d",&num);
		p=getin(p,num);
	}
	printleaf(p,1);
	return 0;
}

