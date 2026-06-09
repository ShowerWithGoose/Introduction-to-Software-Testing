#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
#define FEqual(a,b,eps) (fabs((a)-(b))<(eps)) 

struct node{
	int num;
	struct node* l;
	struct node* r;
};

struct node* insert(struct node* p, int num){
	if(p==NULL){
		p=(struct node*)malloc(sizeof(struct node));
		p->num=num;
		p->l=NULL;
		p->r=NULL;
		return p;
	}
	if(num<p->num){
		p->l=insert(p->l, num);
	}else{
		p->r=insert(p->r, num);
	}
	return p;
}

void preorder(struct node* p, int depth){
	if (p!=NULL){
		if(p->l==NULL&&p->r==NULL){
			printf("%d %d\n", p->num, depth);
			return;
		}
		preorder(p->l, depth+1);
		preorder(p->r, depth+1);
	}
}

int n, temp;
struct node* root=NULL;
int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		scanf("%d", &temp);
		root=insert(root, temp);
	}
	preorder(root, 1);
	return 0;
}



