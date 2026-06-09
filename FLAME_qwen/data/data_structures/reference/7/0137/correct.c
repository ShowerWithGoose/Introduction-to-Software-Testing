#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct mode{
	struct mode* lchild,*rchild;
	int xs;
	int gao;
}shu;
struct mode* qinkong();
struct mode* jianshu();
struct mode* bianli(struct mode*);
shu *p=NULL,*root=NULL,*q=NULL;
int main(){
    int n,m,op,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    	scanf("%d",&m);
    	j=1;
    	if(root==NULL){
    		p=jianshu();
    		p->xs=m;
    		p->gao=j;
		}
		else{
			p=root;
			while(p!=NULL){
				j++;
				if(p->xs>m){
					q=p;
					p=p->lchild;
					op=1;
				}
				else{
					q=p;
					p=p->rchild;
					op=2;
				}
			}
			p=jianshu();
			p->gao=j;
			p->xs=m;
			if(op==1){
				q->lchild=p;
			}
			else{
				q->rchild=p;
			}
			
		}
	}
	bianli(root);
	return 0;
} 
struct mode* jianshu(){
	struct mode* r;
	r=(struct mode*)malloc(sizeof(struct mode));
	r->lchild=NULL;
	r->rchild=NULL;
	r->xs=0;
	if(root==NULL){
	root=r;
	}
	return r;
}
struct mode* bianli(struct mode* t){
	struct mode *zhan[1005],*h;
    int number=-1;
    if(t!=NULL)
	while(t!=NULL||number!=-1){
		for(;t!=NULL;t=t->lchild){
			zhan[++number]=t;
		}
		t=zhan[number--];
		if(t->lchild==NULL&&t->rchild==NULL)
		printf("%d %d\n",t->xs,t->gao);
		h=t;
		t=t->rchild;
		free(h);
	}
    return 0;
}


