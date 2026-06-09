#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define L(type) memset((type*)malloc(sizeof(type)),0,sizeof(type))
struct tree{
	int data;
	struct tree *l,*r;
};
void B(struct tree *R,int h){
	if(R->l==NULL&&R->r==NULL){
		printf("%d %d\n",R->data,h);
	}else{
		if(R->l!=NULL){
			B(R->l,h+1);
		}
		if(R->r!=NULL){
			B(R->r,h+1);
		}
	}
}
int main(){
	struct tree *R,*p;
	R=L(struct tree);
	int n,i,t;
	scanf("%d",&n);
	scanf("%d",&(R->data));
	for(i=1;i<n;i++){
		p=R;
		scanf("%d",&t);
		while(1){
			if(t>=p->data){
				if(p->r==NULL){
					p->r=L(struct tree);
					p->r->data=t;
					break;
				}else{
					p=p->r;
				}
			}else{
				if(p->l==NULL){
					p->l=L(struct tree);
					p->l->data=t;
					break;
				}else{
					p=p->l;
				}
			}
		}
	}
	B(R,1);
	return 0;
}

