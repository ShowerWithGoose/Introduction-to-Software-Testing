#include<stdio.h>
#include<stdlib.h>
struct tree{
	int x0;
	int f0;
	struct tree *left,*right;
}*begin,*q,*p;
struct tree* fond(int x,int f){
	struct tree *p;
	p=(struct tree*)malloc(sizeof(struct tree));
	p->f0=f;
	p->x0=x;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void freetree(struct tree *ptr){
	if(ptr!=NULL){
		freetree(ptr->left);
		freetree(ptr->right);
		free(ptr);
	}
	return;
}
void print(struct tree *ptr){
	if(ptr->left==NULL&&ptr->right==NULL){
		printf("%d %d\n",ptr->x0,ptr->f0);
		return;
	}
	else{
		if(ptr->left!=NULL){
			print(ptr->left);
		}
		if(ptr->right!=NULL){
			print(ptr->right);
		}
	}
	return;
}
int main(){
	int n,i=0,x;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(i==0){
			begin=fond(x,1);
		}
		else{
			for(q=begin;q!=NULL;){
				p=q;
				if(x>=q->x0){
					q=q->right;
				}
				else{
					q=q->left;
				}
			}
			if(x>=p->x0){
				p->right=fond(x,(p->f0)+1);
			}
			else{
				p->left=fond(x,(p->f0)+1);
			}
		}
	}
	print(begin);
	freetree(begin);
	return 0;
}

