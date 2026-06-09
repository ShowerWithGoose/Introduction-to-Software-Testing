#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
	int item;
	struct node *link;
}*Nodeptr,Lnode;
Nodeptr top;

void push(int date)//½øÕ» 
{
	Nodeptr p,q;
	q=(Nodeptr)malloc(sizeof(Lnode));
	q->item=date;
	q->link=top;
	top=q;
	
}

void pop()//³öÕ» 
{
	Nodeptr q;
	if(top==NULL){
		printf("error ");
	}
	else{
		q=(Nodeptr)malloc(sizeof(Lnode));
		q=top;
		int date=q->item;
		top=top->link;
		free(q);
		printf("%d ",date);
	}
}

int main()
{
	int n,date;
	while(scanf("%d",&n)!=EOF){
		if(n==-1){
			break;
		}
		else if(n==1){
			scanf("%d",&date);
			push(date);
		}
		else if(n==0){
			pop();
		}
	}
	return 0;
}

