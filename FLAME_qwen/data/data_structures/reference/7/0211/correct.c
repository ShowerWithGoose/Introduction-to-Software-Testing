#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define uint unsigned int
#define uchar unsigned char

struct tree{
	int num;
	struct tree* lchild;
	struct tree* rchild;
};

void creattree(struct tree* list, int n);
void searchtree(struct tree* list, int deep);

int main(){
	int n;
	struct tree* list;
	list=(struct tree*)malloc(sizeof(struct tree));
	list->num = 0;
	list->lchild =list->rchild =NULL;
	scanf("%d",&n);
	creattree( list, n );
	searchtree( list , 1 ); 
	return 0;
}

void creattree(struct tree* list, int n){
	struct tree* p=list,*q;
	int i,num;
	scanf("%d",&num);
	list->num =num;
	for(i=0;i<n-1;i++){
		scanf("%d",&num);
		p=list;
		start:
		if(num< p->num ){
			if(p->lchild ==NULL){
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =num;
				q->lchild =q->rchild =NULL;
				p->lchild =q;
			}
			else{
				p=p->lchild ;
				goto start;
			}
		}
		else{
			if(p->rchild ==NULL){
				q=(struct tree*)malloc(sizeof(struct tree));
				q->num =num;
				q->lchild =q->rchild =NULL;
				p->rchild =q;
			}
			else{
				p=p->rchild ;
				goto start;
			}
		} 
	}
	
	
}

void searchtree(struct tree* list , int deep){
	if(list->lchild ==NULL && list->rchild ==NULL){
		printf("%d %d\n",list->num ,deep);
	}
	else{
		if(list->lchild != NULL){
			searchtree(list->lchild  , deep+1 );
		}
		if(list->rchild !=NULL ){
			searchtree(list->rchild  , deep+1 );
		}
	}
}



