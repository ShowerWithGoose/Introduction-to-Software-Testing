#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct stack{
	int xishu;
	int zhishu;
	struct stack*next;
}dxs;
typedef dxs* pdxs;
void insert(pdxs head,pdxs a);
void stackprint(pdxs head);

pdxs head1,head2,head3;
pdxs rear; 
int main(){
	rear = (pdxs)malloc(sizeof(dxs));
	rear->xishu =-2;
	rear->zhishu = -2;
	head1 = (pdxs)malloc(sizeof(dxs));
	int a , b;
	char c; 
	pdxs temp;
	temp = head1;
	while(1){
		scanf("%d%d",&a,&b);
		temp->xishu = a;
		temp->zhishu = b;	
		c = getchar();
		if(c!=' '){
			break;
		}
		pdxs d = (pdxs)malloc(sizeof(dxs));
		temp->next = d;
		temp = d;
	}//scanf对空格与换行的识别是相同的，这就倒置了我这里 scanf("%d %d",&a,&b);无法起到换行的作用 
	temp->next = NULL;
	//head1 的建立 
	head2 = (pdxs)malloc(sizeof(dxs));
	temp = head2;
	while(1){
		scanf("%d%d",&a,&b); 
		temp->xishu = a;
		temp->zhishu = b;
		c = getchar();
		if(c!=' '){
			break;
		}
		pdxs d = (pdxs)malloc(sizeof(dxs));
		temp->next = d;
		temp = d;
	
	}
	temp->next = NULL;
	//head2的建立
	head3 = (pdxs)malloc(sizeof(dxs));
	temp = head2;
	pdxs temp3 = head3;
	head3->xishu = -1;
	head3->zhishu=-1;
	while(temp!=NULL){
		pdxs a ;
		a = (pdxs)malloc(sizeof(dxs));
		a->xishu = head1->xishu *temp->xishu;
		a->zhishu = head1->zhishu+temp->zhishu;
		temp3->next= a;
		temp3 = a;
		temp = temp->next;
	}
	temp3->next = rear;
	//head3的建立
	if(head1->next==NULL){
		stackprint(head3);
		return 0;
	}
	temp = head1->next;
	while(1){
		pdxs temp2;
		temp2 = head2;
		while(1){
		pdxs a ;
		a = (pdxs)malloc(sizeof(dxs));
		a->xishu = temp->xishu *temp2->xishu ;
		a->zhishu = temp->zhishu+temp2->zhishu;
	 	insert(head3,a);
	 	if(temp2->next==NULL)break;
	 	else temp2 = temp2->next;
		}
		if(temp->next==NULL){
			break;
		}
		else
		temp = temp->next;
	} 
	stackprint(head3);	
	return 0;
}
void insert(pdxs head,pdxs a){
	pdxs temp;
	temp = head;
	while((temp->next->zhishu)>(a->zhishu)){
		temp = temp->next;
	}
	if(temp->next->zhishu==a->zhishu){
		temp->next->xishu += a->xishu;
	}
	else{
		a->next = temp->next;
		temp->next = a;
	}
}
void stackprint(pdxs head){
	pdxs temp;
	temp = head->next;
	while(temp!=rear){
		printf("%d %d ",temp->xishu,temp->zhishu);
		temp = temp->next;
	}
}

