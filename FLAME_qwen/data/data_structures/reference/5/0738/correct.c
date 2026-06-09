#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

typedef struct multi {
	int num;
	int x;
	struct multi *next;
} LinkList;

LinkList *creat() {
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	char s;
	while(1) {
		node=(LinkList*)malloc(sizeof(LinkList));
		scanf("%d %d%c",&node->num,&node->x,&s);
		end->next=node;
		end=node;
		if(s=='\n')break;
	}
	end->next=NULL;
	return head;
}

//void release(LinkList *list) {
//	LinkList *node=list->next;
//	while(node!=NULL) {
//		printf("%d %d ",node->num,node->x);
//		node=node->next;
//	}
//	printf("\n");
//}

void release(LinkList *list) {
	LinkList *node=list->next;
	if(node->next==NULL){
		printf("%d %d ",node->num,node->x);
	}else{
		release(node);
		printf("%d %d ",node->num,node->x);
	}
}

LinkList *cheng(LinkList *line1,LinkList *line2) {
	LinkList *node1=line1->next,*node2=line2->next;
	LinkList *head,*node,*end;
	head=(LinkList*)malloc(sizeof(LinkList));
	end=head;
	while(node1!=NULL) {
		node2=line2->next;
		while(node2!=NULL) {
			node=(LinkList*)malloc(sizeof(LinkList));
			node->num=node1->num*node2->num;
			node->x=node1->x+node2->x;
			end->next=node;
			end=node;
			node2=node2->next;
		}
		node1=node1->next;
	}
	end->next=NULL;
	return head;
}

void delet(LinkList *list) {
	LinkList *i,*j,*k;
	i=list->next;
	while(i!=NULL) {
		j=i;
		while(j->next!=NULL) {
			if(i->x==j->next->x) {
				i->num+=j->next->num;
				k=j->next;
				j->next=j->next->next;
				free(k);
			}else{
				j=j->next;
			}
			
		}
		i=i->next;
	}
}

void swap(int a,int b) {
	int temp=a;
	a=b;
	b=temp;
}

void BubbleSort(struct student *head){
	LinkList *cur,*tail;
	cur=head;
	tail=NULL; 
	if(cur==NULL||cur->next==NULL){
		return;
	}
	while(cur!=tail){
		while(cur->next!=tail){
			if(cur->x>cur->next->x){
				int temp=cur->x;
				cur->x=cur->next->x;
				cur->next->x=temp;
				long temp1=cur->num;
				cur->num=cur->next->num;
				cur->next->num=temp1;
			}
			cur=cur->next;
		}
		tail=cur;
		cur=head;
	}
	
}

int main() {
	LinkList *line1,*line2,*ans;
	line1=creat();
	line2=creat();
	ans=cheng(line1,line2);
	delet(ans);
	BubbleSort(ans);
	release(ans);
	return 0;
}




