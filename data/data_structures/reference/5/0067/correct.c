#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define pf printf
#define sc scanf
#define N 10005
struct node{
	int num;
	int index;
	struct node *next;
};
int main()
{
	struct node *head1 = NULL,*head2 = NULL,*p,*q,*p1,*q1;
	char c;
	do{
		int num1,index1;
		p = (struct node*)malloc(sizeof(struct node));
		sc("%d%d%c",&num1,&index1,&c);	p->num = num1;	p->index = index1;
		p->next = NULL;
		if(head1 == NULL) head1 = q = p;
		else{
			q->next = p;
			q = p;
		}

	}while(c != '\n');
	char c1; 
	do{
		int num2,index2,num1,index1;
		sc("%d%d%c",&num1,&index1,&c1);
		//相乘插入第二个链表 
		for(p1 = head1;p1 != NULL;p1 = p1->next){
			num2 = num1 * p1->num;
			index2 = index1 + p1->index;
			
			p = (struct node*)malloc(sizeof(struct node));
			p->num = num2;
			p->index = index2;
			p->next = NULL;
			
			if(head2 == NULL)	head2 = q = p;
			else{//按顺序建立链表 
				for(q = head2;q != NULL;q1 = q,q = q->next) {
					if(p->index > q->index){
						if(q==head2){
							p->next = head2;
							head2 = p;
							break;
						}
						else{//将p插入q前 
							p->next = q;
							q1->next = p;
							break;
						}
					}
					else if(p->index == q->index){
						q->num += p->num;break;
					}
				}
				if(q == NULL) {
					q1->next = p;
				}
			}
		}
	}while(c1 != '\n');
	
	
	for(p = head2;p != NULL;p = p->next) pf("%d %d ",p->num,p->index);


	return 0;
}


