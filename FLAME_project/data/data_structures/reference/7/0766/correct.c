#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *llink,*rlink;
}BTNode,*BTREE;
BTREE T;
int time=1;
void InBt(int n)
{
	BTREE p,q;
	p=(BTREE)malloc(sizeof(BTNode));
	p->num=n;
	p->llink=NULL;
	p->rlink=NULL;
	if(T==NULL)
		T=p;
	else{
		q=T;
		while(1){
			if(n<q->num){
				if(q->llink==NULL){
					q->llink=p;
					break;
				}
				else
					q=q->llink;
			}else{
				if(q->rlink==NULL){
					q->rlink=p;
					break;
				}else
					q=q->rlink;
			}
		}
	}
}
void JUDGE(BTREE t)
{
	if(t->llink!=NULL){
		time++;
		JUDGE(t->llink);
	}
	if(t->rlink!=NULL){
		time++;
		JUDGE(t->rlink);
	}
	if(t->llink==NULL&&t->rlink==NULL){
		printf("%d %d\n",t->num,time);
//		time--;
	}
	time--;
}
int main()
{
	int n;
	int scan;
	scanf("%d",&n);
	while(n){
		scanf("%d",&scan);
		InBt(scan);
		n--;
	}
	JUDGE(T);
}



