#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE{
	int data;
	struct NODE *link;
}node;

int main(){
	int x,flag=0,n=0;
	node *p,*top=NULL;
	while(scanf("%d",&x)!=EOF){
		if(x==1){
			flag=1;
			continue;
		}
		
		if(flag==1){
			if(n==100){
				printf("error ");
				continue;
			}
			p=(node*)malloc(sizeof(node));
			p->data=x;
			if(top==NULL){
				top=p;
				n++;
			}
			else{
				p->link=top;
				top=p;
				n++;
			}
			flag=0;
		}
		
		if(x==0){
			if(n==0){
				printf("error ");
				continue;
			}
			else{
			printf("%d ",top->data);
			p=top;
			top=top->link;
			free(p);
			n--;}
		}
		
		if(x==-1){
			break;
		}
	}
	return 0;
}

