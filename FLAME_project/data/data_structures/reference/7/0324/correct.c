#include<stdio.h>

struct node{
	int a;
	struct node *left,*right;
};

struct node *insert(int t,struct node *p){
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		p->left=NULL, p->right=NULL, p->a=t;
	}
	else if(t<p->a)	p->left=insert(t,p->left);
	else if(t>=p->a)	p->right=insert(t,p->right);
	return p;
}

int cont=0;
void pre(struct node *p){
	cont++;
	if(p!=NULL){
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->a,cont);
		pre(p->left);
		pre(p->right);		
	}
	cont--;
}

int main(){
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *p=(struct node *)malloc(sizeof(struct node));
	head->left=NULL, head->right=NULL, p=head;
	int n,t,i;
	scanf("%d%d",&n,&head->a);
	for(i=0;i<n-1;i++){
		scanf("%d",&t);
		head=insert(t,head);
	}
	pre(head);
	return 0;
}

