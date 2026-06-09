#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct points{
	int data;
	struct points *leftc;
	struct points *rightc;
	int level;
}point;

void creat(point* base,int number){
	if(base->data>number){
		if(base->leftc==NULL){
			base->leftc=(point *)malloc(sizeof(point));
			base->leftc->data=number;
			base->leftc->level=base->level+1;
			base->leftc->leftc=base->leftc->rightc=NULL;
		}
		else{
			creat(base->leftc,number);
		}
	}
	else {
		if(base->rightc==NULL){
			base->rightc=(point *)malloc(sizeof(point));
			base->rightc->data=number;
			base->rightc->level=base->level+1;
			base->rightc->leftc=base->rightc->rightc=NULL;
		}
		else{
			creat(base->rightc,number);
		}
	}
}

void print(point *node){
	if(node->leftc==NULL&&node->rightc==NULL)
		printf("%d %d\n",node->data,node->level);
	else{
		if(node->leftc!=NULL)
			print(node->leftc);
		if(node->rightc!=NULL)
			print(node->rightc);
	}
}

int main() {
	point *head, *item;
	int n,num;
	scanf("%d",&n);
	scanf("%d",&num);
	head=(point *)malloc(sizeof(point));
	head->data =num;
	head->level=1;
	head->rightc=head->leftc=NULL;
	item=head;
	for(n-=1;n>0;n--){
		scanf("%d",&num);
		creat(item,num);
	}
	print(head);	
	return 0;
}

