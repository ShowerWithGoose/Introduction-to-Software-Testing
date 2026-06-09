#include <stdio.h>
#include <stdlib.h>
#define SZ 100
typedef struct n {
	int data;
	struct n* next;
} node;
typedef node* stack;
int cnt = 0;
stack push(stack s,int i);
stack pop(stack s);
stack release(stack head);
int main() {

	int ord;
	stack num;
	num=NULL;
	scanf("%d",&ord);
	while(1){
		switch(ord){
			case 1:{
				int i;
				scanf("%d",&i);
				num=push(num,i);
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
	scanf("%d",&ord);	
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
stack push(stack s,int i){
	if(cnt==SZ){
		printf("error ");
		return s;
	}
	node* current;
	current=(node*)malloc(sizeof(node));
	current->data=i;
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
	node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}



