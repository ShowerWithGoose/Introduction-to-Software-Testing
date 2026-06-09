#include <stdio.h>
#include <stdlib.h>
struct number{
	int num;
	int high;
	struct number *lchild,*rchild; 
};
struct number *head=NULL;
struct number *insertNum(int n,struct number *p){
	static int h=1;
	if(p==NULL){
		p=(struct number *)malloc(sizeof(struct number));
		p->num=n;
        p->high=h;
		p->lchild=p->rchild=NULL; 
		h=1;
	}
	else{
			if(n>=p->num){
				h++;
				p->rchild=insertNum(n,p->rchild);
			}
			else{
				h++;
				p->lchild=insertNum(n,p->lchild);
			} 
	}
	return p;
}
void print(struct number *p){
	if(p==NULL){
		return;
	}
	else if(p->lchild==NULL&&p->rchild==NULL){
		    printf("%d %d\n",p->num,p->high);
	}
	else{
    	print(p->lchild);
    	print(p->rchild);
	}
}
int main(){
	int t,i=0,xin;
	scanf("%d",&t);
	for(i=0;i<t;i++){
	    scanf("%d",&xin);
	    head =insertNum(xin,head);
	}
	print(head);
	return 0;
} 

