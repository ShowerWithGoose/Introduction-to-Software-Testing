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
struct tree *makenode(int x,int d){
	struct tree *p;
	p=(struct tree *)malloc(sizeof(struct tree));
	p->a=x;
	p->h=d;
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
	int n,i,x,d=1;
	struct tree *p,*root=NULL,*tail=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(i==1){
			root=makenode(x,d);
		}
		else{
		 p=root;
		 d=1;
		 while(1){
			if(x<p->a&&p->left!=NULL){
				p=p->left;
				d++;
			}
			else if(x<p->a&&p->left==NULL){
				d++;
				p->left=makenode(x,d);
				break;
			}
			else if(x>=p->a&&p->right!=NULL){
				p=p->right;
				d++;
			}
			else if(x>=p->a&&p->right==NULL){
				d++;
				p->right=makenode(x,d);
				break;
			}
		 }
		}
	}
	vist(root);
	shifang(root);
	return 0;
} 

