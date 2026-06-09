#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct LNode {
	int coe;
	int index;
	struct LNode *next;
};
typedef struct LNode *PNode;
//PNode p;

int main()
{
	int m,n,tmp;
	char c;
	PNode head1 = (PNode)malloc(sizeof(struct LNode));
	PNode p1 = head1;
	PNode head2 = (PNode)malloc(sizeof(struct LNode));
	PNode p2 = head2;
	PNode p3 = (PNode)malloc(sizeof(struct LNode));
	do
	{
		scanf("%d%d%c",&m,&n,&c);
		p1 -> coe = m;
		p1 -> index = n;
		if(c != '\n'){
			PNode temp = (PNode)malloc(sizeof(struct LNode));
			p1 -> next = temp;
			p1 = p1 -> next;
		}else{
			p1->next = NULL;
		}
	}while(c != '\n');
//	p1=NULL;
//	for(p1 = head1 ; p1 != NULL ; p1 = p1->next)
//		{
//			printf("%d %d\n", p1->coe, p1->index);
//		}
	do
	{
		scanf("%d%d%c",&m,&n,&c);
		for(p1 = head1 ; p1 != NULL ; p1 = p1->next)
		{
			p2 -> coe = m*p1 -> coe;
			p2 -> index = n+p1 -> index;
			if(c == '\n' && p1->next == NULL){
				p2->next = NULL;
			}
			else{
				PNode temp = (PNode)malloc(sizeof(struct LNode));
				p2 -> next = temp;
				p2 = p2 -> next;
			}
		}
	}while(c != '\n');
	
//		for(p2 = head2 ; p2 != NULL ; p2 = p2->next)
//		{
//			printf("%d %d\n", p2->coe, p2->index);
//		}
//	p2=NULL;
	for(p2 = head2 ; p2 != NULL ; p2 = p2 -> next)
	{
		PNode pp2 = p2;
		for(p3 = p2 -> next ; p3 != NULL ; p3 = p3 -> next)
		{
			if(p2 -> index < p3 -> index)
			{
				tmp = p2 -> index;
				p2 -> index = p3 -> index;
				p3 -> index = tmp;
				tmp = p2 -> coe;
				p2 -> coe = p3 -> coe;
				p3 -> coe = tmp;
				pp2 = pp2 -> next;
			}
			else if(p2 -> index == p3 -> index)
			{
				p2 -> coe = p2 -> coe + p3 -> coe;
				pp2->next = p3->next;
//				free(p3);
//				del(p3);
			}else{
				pp2 = pp2 -> next;	
			}
		}
	}
	for(p2=head2; p2!=NULL; p2=p2->next)
    printf("%d %d ", p2->coe,p2->index);
    printf("\n");
	return 0;
} 

