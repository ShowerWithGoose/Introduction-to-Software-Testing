#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	int high;
	struct tree *left,*right;
}; 

typedef struct tree t;
typedef struct tree *tint;

void print(tint a);

int main()
{
	int n,x,h;
	scanf("%d",&n);
	tint p,q,root=NULL;
	for(int i=0;i<n;++i){
		scanf("%d",&x);
		h=1;
		p=(tint)malloc(sizeof(t));
		p->data=x;p->left=NULL;p->right=NULL;
		if(root==NULL){
			p->high=1;
			root=p;
			continue;
		}
		q=root;
		while(q!=NULL){
			h++;
			if(x<q->data){
				if(q->left==NULL){
					p->high=h;
					q->left=p;
					break;
				}
				else q=q->left ; 
			}
			else{
				if(q->right==NULL){
					p->high=h;
					q->right=p;
					break;
				}
				else q=q->right ; 
			}
		}
	}
	print(root);
	return 0;
}

void print(tint a)
{
	if(a){
		if(a->left ==NULL&&a->right ==NULL) printf("%d %d\n",a->data ,a->high );
	    else{
	    	print(a->left );print(a->right );
		}
	}
	
}

