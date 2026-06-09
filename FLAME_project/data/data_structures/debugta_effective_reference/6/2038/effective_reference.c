#include <stdio.h>
#include <stdlib.h>
int flag;
struct node {
	int data;
	struct node* next;
};
struct node*push(struct node*head,int data) {
	struct node*new1=(struct node*)malloc(sizeof(struct node));
	new1->data=data;
	new1->next=head->next;
	head->next=new1;
	flag++;
	return head;
}
void pop(struct node*head) {
	if(head->next==NULL) {
		printf("error ");
	} else {
		struct node* p=head->next;
		printf("%d ",p->data);
		head->next=p->next;
		free(p);
		flag--;
	}

}
int main() {
	int n,i;
	char ch;
	struct node*head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	while(scanf("%d%c",&n,&ch)!=EOF) {
		if(n==1) {
			scanf("%d%c",&i,&ch);
			if(flag>=100){
				printf("error ");
			}
			else{
				head=push(head,i);
			}
		} else {
			if(n==0) {
				pop(head);
			}
			if(n==-1)break;
		}
	}
}

