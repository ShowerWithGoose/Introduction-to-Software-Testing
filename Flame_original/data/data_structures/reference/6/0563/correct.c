#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct Node{
	int data;
	struct node *next;
};
int Max=100;
struct Node *creatStack();
int isFull(struct Node *headNode);
int isEmpty(struct Node *headNode);
void push(struct Node *headNode,int item);
int pop(struct Node *headNode);
int listlong(struct Node *headNode);
int main(){
	struct Node *headNode=creatStack();
	int order;int num;
	scanf("%d",&order);
	while(order!=-1){
		if(order==1){
			scanf("%d",&num);
			if(isFull(headNode))printf("error ");
			else push(headNode,num);
		}
		else if(order==0){
			if(isEmpty(headNode))printf("error ");
			else printf("%d ",pop(headNode));
		}
		scanf("%d",&order);
	}
	return 0;
}
struct Node *creatStack(){
	struct Node *p=malloc(sizeof(struct Node));
	p->next=NULL;
	return p;
}
int isFull(struct Node *headNode){
	if(listlong(headNode)==Max)return 1;
	else return 0;
}
int listlong(struct Node *headNode){
	int i=0;
	for(i=0;headNode->next!=NULL;i++){
		headNode=headNode->next;
	}
	return i;
}
int isEmpty(struct Node *headNode){
   return headNode->next==NULL;
}
void push(struct Node *headNode,int item){
	struct Node* p;
	p=(struct Node *)malloc(sizeof(struct Node));
	p->data=item;
	p->next=headNode->next;
	headNode->next=p;
}
int pop(struct Node *headNode){
     struct Node *p=headNode->next;
   	 int item=p->data;
   	 headNode->next=p->next;
   	 return item;
}


