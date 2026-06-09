#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
	int num,depth;
	struct node *llink,*rlink;
}Node;
Node *root,*p,*r;
int deep=1;

void add(Node*,Node*);	//加入树中 
void visit(Node*);		//访问值 
void inorder(Node*);	//中序遍历
int isleave(Node* q){	//判断叶子结点 
	return (q->llink==NULL)&&(q->rlink==NULL);
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		p=(Node*)malloc(sizeof(Node));
		p->num=m;p->llink=NULL;p->rlink=NULL;
		if(i==1)
			root=p,root->depth=deep;
		else
			add(p,root);
	}
	inorder(root);
	return 0;
}

void add(Node *q,Node *root2){
	int flag;
	((q->num)<(root2->num)) ? (flag=0) : (flag=1) ;
	if(flag==0)		//插左
	{
		if(root2->llink==NULL)
			q->depth=deep+1,root2->llink=q;
		else
			deep++,add(q,root2->llink),deep--;
	}
	else
	{
		if(root2->rlink==NULL)
			q->depth=deep+1,root2->rlink=q;
		else
			deep++,add(q,root2->rlink),deep--;
	}
	return;
}

void visit(Node *q){
	if(isleave(q)) 
		printf("%d %d\n",q->num,q->depth);
	return;
}

void inorder(Node* root2){
	if(root2!=NULL)
	{
		inorder(root2->llink);
		visit(root2);
		inorder(root2->rlink);
	}
	return;
}

