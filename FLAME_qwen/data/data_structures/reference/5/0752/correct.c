#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
typedef struct NODE{
	int num;
	int power;
	struct NODE *next;
}node,*nodeAdd;
nodeAdd init(void){
	nodeAdd temp=(nodeAdd)malloc(sizeof(node));
	temp->next=NULL;
	temp->power=INT_MAX;
	return temp;
}
void push(nodeAdd p,int _num,int _power){
	nodeAdd temp=(nodeAdd)malloc(sizeof(node));
	temp->next=p->next;
	temp->num=_num;
	temp->power=_power;
	p->next=temp;
	return;
}
void pushAns(nodeAdd p,int _num,int _power){
	nodeAdd temp;
	for(temp=p;!(temp->next==NULL||temp->next->power<_power);temp=temp->next);
	if(temp->power==_power){
		temp->num+=_num;
		return;
	}
	nodeAdd newNode=(nodeAdd)malloc(sizeof(node));
	newNode->num=_num;
	newNode->power=_power;
	newNode->next=temp->next;
	temp->next=newNode;
	return;
}
void display(nodeAdd p){
	for(nodeAdd temp=p->next;temp!=NULL;temp=temp->next){
		printf("%d %d ",temp->num,temp->power);
	}
	printf("\n");
}
void input(nodeAdd p){
	int tempNum,tempPower;
	while(~scanf("%d%d",&tempNum,&tempPower)){
		push(p,tempNum,tempPower);
		char c;
		if((c=getchar())=='\n'){
			break;
		}
	}
}
int main() {
	nodeAdd a=init();
	nodeAdd b=init();
	nodeAdd answer=init();
	input(a);
	input(b);
	for(nodeAdd list1=a->next;list1!=NULL;list1=list1->next){
		for(nodeAdd list2=b->next;list2!=NULL;list2=list2->next){
			pushAns(answer,list1->num*list2->num,list1->power+list2->power);
		}
	}
	display(answer);
    return 0;
}












