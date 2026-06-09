#include <stdio.h>
#include <stdlib.h>

struct node{
	int number,floor;
	struct node *left,*right;
}*head,*p,*q;

void put(struct node *);

int main()
{
	int i,n;
	scanf("%d",&n);
	
	head=(struct node *)malloc(sizeof(struct node));
	head->left=NULL;  head->right=NULL;  head->floor=1;
	scanf("%d",&head->number);
	
	for(i=2;i<=n;i++){
		q=(struct node *)malloc(sizeof(struct node));
		q->number=0;  q->left=NULL;  q->right=NULL;  q->floor=2;
		scanf("%d",&q->number);
		
		p=head;
		while(1){
			if(q->number<p->number){
				if(p->left!=NULL) p=p->left;
				else{
					p->left=q; break;
				}
			}
			else{
				if(p->right!=NULL) p=p->right;
				else{
					p->right=q; break;
				}
			}
			q->floor++;
		}
		
	}
	
	p=head;
	put(p);
	return 0;
}

void put(struct node *hold)
{
	if(hold->left==NULL&&hold->right==NULL){
		printf("%d %d\n",hold->number,hold->floor);
		return;
	}
	
	if(hold->left!=NULL) put(hold->left);
	if(hold->right!=NULL) put(hold->right);
}

