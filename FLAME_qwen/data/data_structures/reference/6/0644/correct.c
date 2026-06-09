#include <stdio.h>
#include <stdlib.h>
typedef struct item{
	int i;
	struct item *next;
	struct item *last;
}item,*itempr;
int n;
int main(){
	itempr rear;
	rear=(itempr)malloc(sizeof(item));
	rear->next=NULL;
	rear->last=NULL;
	while(1){
		scanf("%d",&n);
		//printf("%d\n",n);
		if(n==-1){
			break;
		}else if(n==1){
			itempr p;
			p=(itempr)malloc(sizeof(item));
			scanf("%d ",&p->i);
			//printf("%d\n",p->i);
			p->last=rear;
			p->next=NULL;
			rear->next=p;
			rear=p;
		
		}else if(n==0){
			if(rear->last==NULL){
			    printf("error ");
			}else{
				printf("%d ",rear->i);
				rear=rear->last;
				rear->next=NULL;
			}
		}
	}
	return 0;
}

