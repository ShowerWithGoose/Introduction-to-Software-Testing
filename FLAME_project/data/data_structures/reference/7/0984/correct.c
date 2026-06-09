#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int a;
	int h;
//	struct tree *front;
	struct tree *left;
	struct tree *right;
};
struct tree *makenode(int d,int high){
	struct tree *p;
	p=(struct tree *)malloc(sizeof(struct tree));
	p->a=d;
	p->h=high;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void vist(struct tree *p){
	if(p->left==NULL&&p->right==NULL){
		printf("%d %d\n",p->a,p->h);
	}
	else{
		if(p->left!=NULL){
			vist(p->left);
		}
		if(p->right!=NULL){
			vist(p->right);
		}
	}
}
void shifang(struct tree *p){
	if(p->left!=NULL){
		shifang(p->left);
		p->left=NULL;
	}
	if(p->right!=NULL){
		shifang(p->right);
		p->right=NULL;
	}
	free(p);
}
int main()
{
	int x,i,d,high=1;
	struct tree *q,*first=NULL,*tail=NULL;
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		scanf("%d",&d);
		if(i==1){
			first=makenode(d,high);
		}
		else{
		 q=first;
		 high=1;
		 while(1){
			if(d<q->a&&q->left!=NULL){
				q=q->left;
				high++;
			}
			else if(d<q->a&&q->left==NULL){
				high++;
				q->left=makenode(d,high);
				break;
			}
			else if(d>=q->a&&q->right!=NULL){
				q=q->right;
				high++;
			}
			else if(d>=q->a&&q->right==NULL){
				high++;
				q->right=makenode(d,high);
				break;
			}
		 }
		}
	}
	vist(first);
	shifang(first);
	return 0;
} 

