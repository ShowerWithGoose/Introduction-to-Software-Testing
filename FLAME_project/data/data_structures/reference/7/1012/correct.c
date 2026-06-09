#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct Tree{
	int data;
	struct Tree* lchild;
	struct Tree* rchild;
}node;
node* root;
int i,n,num,count=1;
node* insert(node* p,int num){
	if(p==NULL)
	{
		p=(node*)malloc(sizeof(node));
		p->data=num;
		p->lchild=p->rchild=NULL;
	}
	else if(num<p->data)
		p->lchild=insert(p->lchild,num);
	else if(num>=p->data)
		p->rchild=insert(p->rchild,num);
	return p;
}
void order(node* p){
	int temp=count;
	if(p!=NULL){
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			printf("%d %d\n",p->data,count);
		}
		count++;
		order(p->lchild);
		count=temp;
		count++;
		order(p->rchild);
		count=temp;
	}	
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		root=insert(root,num);
	}
	order(root);
	return 0;
}

