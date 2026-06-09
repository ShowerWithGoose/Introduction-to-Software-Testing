#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long

struct tree{
	int date;
	int height;
	struct tree *left;
	struct tree *right;
};
void f(struct tree*t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->date,t->height);
		}
		f(t->left);
		f(t->right);
	} 
}

int main(){
	int i,j,k;
	int n; 
	scanf("%d",&n);
	struct tree *root=NULL,*p=NULL,*q;
	p=(struct tree*)malloc(sizeof(struct tree));
	scanf("%d",&p->date);
	p->left=NULL;
	p->right=NULL;
	p->height=1;
	root=p;
	int check;
	for(i=1;i<n;i++){
		scanf("%d",&check);
		for(j=2,q=root;;j++){
			if(check<q->date){
				if(q->left==NULL){
					p=(struct tree*)malloc(sizeof(struct tree));
					p->date=check;
					p->left=NULL;
					p->right=NULL;
					p->height=j;
					q->left=p;
					break;
				}
				else{
					q=q->left;
				}
			}
			else if(check>=q->date){
				if(q->right==NULL){
					p=(struct tree*)malloc(sizeof(struct tree));
					p->date=check;
					p->left=NULL;
					p->right=NULL;
					p->height=j;
					q->right=p;
					break;
				}
				else{
					q=q->right;
				}
			}
		}
	}
	f(root);
}

