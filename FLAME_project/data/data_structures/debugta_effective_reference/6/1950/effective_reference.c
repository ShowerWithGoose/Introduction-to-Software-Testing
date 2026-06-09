#include <stdio.h>
#include <stdlib.h>
#define SZ 100
typedef struct n {
	int data;
	struct n* next;
} node;
typedef node* stack;
int cnt = 0;
stack push(stack s,int num);
stack pop(stack s);
stack release(stack head);
int main() {

	int op;
	stack num;
	num=NULL;
	scanf("%d",&op);
	while(1){
		switch(op){
			case 1:{
				int num;
				scanf("%d",&num);
				num=push(num,num);
				break;
			}
			case 0:{				
				num=pop(num);
				break;
			}
			case -1:{
				goto H;
			}
			
			
		}
	scanf("%d",&op);	
	}
	/*node* current=num;
	while(current!=NULL){
		printf("%d ",current->data);
		current=current->next;
	}*/
	
H:
	release(num);
	return 0;
}
stack push(stack s,int num){
	if(cnt==SZ){
		printf("error ");
		return s;
	}
	node* current;
	current=(node*)malloc(sizeof(node));
	current->data=num;
	if(s==NULL){		
		current->next=NULL;
		s=current;
	}
	else{
		current->next=s;
		s=current;
	}
	cnt++;
	return s;
}
stack pop(stack s){
	if(cnt==0){
		printf("error ");
		return s;
	}
	else{
		node* current=s;
		s=s->next;
		printf("%d ",current->data);
		free(current);
	}
	cnt--;
	return s;
}
stack release(stack head) {
	node* oprate;
	while (head != NULL) {
		oprate = head;
		head = head->next;
		free(oprate);
	}
	return head;
}



