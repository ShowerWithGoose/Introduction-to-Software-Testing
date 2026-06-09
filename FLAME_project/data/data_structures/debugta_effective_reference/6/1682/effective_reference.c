#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define S scanf
#define P printf
#define L long long
struct node{
	int data;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr top;
void initStack(){
	top=NULL;
}
void push(int item){
	Nodeptr p;
	p=(Nodeptr)malloc(sizeof(Node));
		p->data=item;
		p->link=top;
		top=p;
}
void pop(){
	Nodeptr p;
	int item;
	if(top==0){
		P("error ");
	}
	else{
		p=top;
		item=top->data;
		top=top->link;
		free(p);
		P("%d ",item);
	}
}
int main(){
	int n,j;
	initStack();
	while(S("%d",&n)!=-1){
		if(n==1){
			S("%d",&j);
			push(j);
		}
		else if(n==0) pop();
		else break;
	}
	return 0;
}

