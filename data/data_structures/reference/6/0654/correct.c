#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
struct node* top=NULL;
int main(){
	int n,m,k;
	while(1){
		scanf("%d",&n);
		if(n==1) {
		scanf("%d",&m);	
		    struct node* p;
		    p=(struct node*)malloc(sizeof(struct node));
			p->data=m;
			p->link=top;
			top=p;
	}
	else if(n==0){
		if(top!=NULL){
		k=top->data;
		top=top->link;
		printf("%d ",k);			
		}
		else{
			printf("error ");
		}
	}
	else if(n==-1){
		return 0;
	}
}
}

