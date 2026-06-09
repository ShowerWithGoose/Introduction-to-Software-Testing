#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct aa{
	int data;
	int ceng;
	struct aa *left;
	struct aa *right;
}*list,*p,*q;

void output(struct aa *a){
	if(a->left!=NULL){
		output(a->left);
	}
	if(a->left==NULL&&a->right==NULL){
		printf("%d %d\n",a->data,a->ceng);
	}
	if(a->right!=NULL){
		output(a->right);
	}
}

int main(){
	int n,i,m,j=1;
	scanf("%d",&n);
	scanf("%d",&m);
	list=(struct aa *)malloc(sizeof(struct aa *));
	list->data=m;
	list->ceng=1;
	list->left=list->right=NULL;
	for(i=1;i<n;i++){
		p=list;
		scanf("%d",&m);
		q=(struct aa *)malloc(sizeof(struct aa *));
	    q->data=m;
	    q->left=q->right=NULL;
	    j=2;
	    while(1){
	    	if(m>=p->data){
	    		if(p->right!=NULL){
	    			p=p->right;
	    			j++;
				}
				else{
					p->right=q;
					q->ceng=j;
					break;
				}
			}
			else{
				if(p->left!=NULL){
	    			p=p->left;
	    			j++;
				}
				else{
					p->left=q;
					q->ceng=j;
					break;
				}
			}
		}
	}
	output(list);
}

