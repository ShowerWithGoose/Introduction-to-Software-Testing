#include<stdio.h>
#include<stdlib.h>
struct node{
	int num,high;
	struct node *left,*right;
};

struct node* insert(int m,struct node *t){
	int h=2;
	struct node *p,*q;
	if(t==NULL){
		t=(struct node *)malloc(sizeof(struct node));
		t->high=1;
		t->num=m;
		t->left=NULL;
		t->right=NULL;
		return t;
	}
	else{
		p=t;
		q=(struct node *)malloc(sizeof(struct node));
		q->num=m;
		q->left=NULL;
		q->right=NULL;
		while(1){
			if(t->left==NULL&&t->num>m){
				q->high=h;
				t->left=q;
				break;
			} 
			else if(t->right==NULL&&t->num<=m){
				q->high=h;
				t->right=q;
				break;
			}
			else if(t->num>m){
				t=t->left;
				h++;
			} 
			else if(t->num<=m){
				t=t->right;
				h++;
			}
		}
		return p;
	}
} 
void print(struct node *t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->num,t->high);
	print(t->left);
	print(t->right);
   } 
}
int main(){
	struct node *head=NULL;
	int n,m,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		head=insert(m,head);
	}
	print(head);
	return 0;
}

