#include <stdio.h>
#include <stdlib.h>
int flag;
struct node {
	int data;
	struct node* next;
};
struct node*push(struct node*head,int data) {
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=head->next;
	head->next=newnode;
	flag++;
	return head;
}
void pop(struct node*head) {
	if(head->next==NULL) {
		printf("error ");
	} else {
		struct node* posnode=head->next;
		printf("%d ",posnode->data);
		head->next=posnode->next;
		free(posnode);
		flag--;
	}

}
int main() {
	int a,b;
	char ch;
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	while(scanf("%d%c",&a,&ch)!=EOF) {
		if(a==1) {
			scanf("%d%c",&b,&ch);
			if(flag>=100){
				printf("error ");
			}
			else{
				head=push(head,b);
			}
		} else {
			if(a==0) {
				pop(head);
			}
			if(a==-1)break;
		}
	}
}

