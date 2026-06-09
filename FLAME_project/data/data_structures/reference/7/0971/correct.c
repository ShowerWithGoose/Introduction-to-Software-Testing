#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int num;
	int dep;
	struct node* l;
	struct node* r;
};

typedef struct node tree;
typedef struct node* treen;
treen p,q,v,root;

void seek_leaf(treen a);

int main(){	
	int n,f1,f2;f1=f2=0;
	scanf("%d",&n);
	while(n--){
		p=(treen)malloc(sizeof(tree));
		scanf("%d",&p->num);
		p->dep=1;
		if(root==NULL){
			root=q=p;
		}
		else{
		 q=root;
			while(q!=NULL){
				v=q;
				if(q->num>p->num){
					q=q->l;
					f1=1;
					f2=0;
				}
				else{
					q=q->r;
					f1=0;
					f2=1;
				}
				p->dep++;
			}
			if(f1==1){
				v->l=p;
			}
			else{
				v->r=p;
			}	
		}
		p->l=p->r=NULL;
	}
	seek_leaf(root);
	return 0;
} 

void seek_leaf(treen a){
	if(a->l!=NULL){
		seek_leaf(a->l); 
	}
	if(a->r!=NULL){
		seek_leaf(a->r);
	}
	if(a->r==NULL&&a->l==NULL){
		printf("%d %d\n",a->num,a->dep);
	}
	return ;
}

