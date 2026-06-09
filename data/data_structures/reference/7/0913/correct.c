#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct bst{
	int number,h;
	struct bst *left,*right;
		
}*gen,*p,*q;
void find(struct bst*);

int main(){
	gen=NULL;
	int n,x,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(gen==NULL){
			p=(struct bst*)malloc(sizeof(struct bst));
			p->h=1;
			p->number=x;
			gen=p,q=p;
			p->left=NULL,p->right=NULL;
		}
		else{
			p=(struct bst*)malloc(sizeof(struct bst));
			p->number=x,p->left=NULL,p->right=NULL;
			q=gen,j=1;
			while(q!=NULL){
				if(x<q->number){
			    	if(q->left==NULL){
			    		q->left=p;
			    		p->h=++j;
			    		break;
			    	}
			    	else{
			    		q=q->left;
			    		j++;
					}
		    	}
		    	else if(x>=q->number){
		    		if(q->right==NULL){
		    			q->right=p;
		    			p->h=++j;
		    			break;
					}
					else{
						q=q->right;
						j++;
					}
		    	}
			}	
		}
	}
	find(gen);
	
	return 0;
}

void find(struct bst *t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->number,t->h);
		}
		find(t->left);
		find(t->right);
	}
}
