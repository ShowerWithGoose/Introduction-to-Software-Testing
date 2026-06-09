#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct tree{
	int number;
	int deep;
	struct tree *lchild,*rchild; 
};

void search(struct tree *T){
	if(T!=NULL){
		if(T->lchild==NULL && T->rchild==NULL)
			printf("%d %d\n",T->number,T->deep);
		search(T->lchild);
		search(T->rchild); 
	}
}

int main()
{
	int n,i,num,dp,front,rear;
	struct tree *T=NULL,*p,*q,*c,*queue[50];
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",&num);
		if(T==NULL){
			T=(struct tree*)malloc(sizeof(struct tree));
			T->number=num;
			T->lchild=NULL;
			T->rchild=NULL;
			T->deep=1;
			continue;
		}
		dp=1;
		p=T;
		while(p!=NULL){
			dp++;
			if(num<p->number){
				q=p;
				p=p->lchild;
				continue;
			}
			if(num>=p->number){
				q=p;
				p=p->rchild;
				continue;
			}
		}
		c=(struct tree*)malloc(sizeof(struct tree));
		c->number=num;
		c->lchild=NULL;
		c->rchild=NULL;
		c->deep=dp;
		if(num<q->number)
			q->lchild=c;
		else if(num>=q->number)
			q->rchild=c;
	}

	search(T);

	return 0;
}


