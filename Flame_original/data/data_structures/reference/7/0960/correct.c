#include<stdio.h>
typedef struct node{
int data,depth,height;
struct node *l,*r;	
}bt;
bt* btins(bt *p,int item); 
int btdep(bt *p);
void bthei(bt*p,bt*prior);


int main(){
	int n,i,a[105];
	bt *p=NULL;

	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		p=btins(p,a[i]);
	}	
	btdep(p);
	p->height=1;
	bthei(p,p);

	btprint(p);
	return 0;
} 

bt* btins(bt *p,int item){//bct插入 
 	if(p==NULL){
 		p=(bt*)malloc(sizeof(bt));
 		p->data=item;
 		p->l=p->r=NULL;
 	}
 	else if(item<p->data){
 		p->l=btins(p->l,item);
 	}
 	else if(item>=p->data){
 		p->r=btins(p->r,item);
 	}
 	else{
 		//do something;
 	}
 	return p;
 } 
 
int btdep(bt *p){//求树高度 
 	if(p==NULL){
 		return 0;
 	}
 	else{
 		p->depth=btdep(p->l)+1;
 		if(btdep(p->l)<btdep(p->r))
 		p->depth=btdep(p->r)+1;
 		return p->depth;
 	}
 }
 
void bthei(bt*p,bt*prior){
	if(p->height!=1)
 		p->height=prior->height+1;
 		if(p->l!=NULL){
 			bthei(p->l,p);
 		}
 		if(p->r!=NULL){
 			bthei(p->r,p);
 		}
 		return;
 }
 
 void btprint(bt *p){///类似遍历 
  if(p==NULL)return;
	if(p->depth==1){
		printf("%d %d\n",p->data,p->height);
		return;
	}
	else{
		btprint(p->l);
		btprint(p->r);
	}
	return;
}

