#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stack{
	int a;
	struct stack *node;
};
typedef struct stack Node;
typedef struct stack *Nodeptr;
int x[110];
int main()
{
	Nodeptr head=NULL,p,r,q;
	int n,num,m=0,temp1,temp2;
	while(1){
		scanf("%d",&n);
		if(n==1){
			scanf("%d",&num);
			if(head==NULL){
				r=(Nodeptr)malloc(sizeof(Node));
				r->a=num;
				r->node=NULL;
				head=r;
			}
			else{
				r=(Nodeptr)malloc(sizeof(Node));
				r->a=num;
				r->node=head;
				head=r;
			}
		}
		else if(n==0){
			if(head!=NULL){
			x[m++]=head->a;
			q=head;
			head=head->node;
			free(q);
			}
			else if(head==NULL){
				x[m++]=0;
			}
		}
		if(n==-1) break;
	}
	for(int i=0;i<m;i++){
		if(x[i]==0) printf("error ");
		else printf("%d ",x[i]);
	}
}


