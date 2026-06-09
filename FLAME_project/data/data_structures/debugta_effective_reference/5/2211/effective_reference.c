#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct PolyNode{
	int coe;
	int exp;
	struct PolyNode *next;
} Node, *NodePtr;

NodePtr InsertFirst(int coe, int exp, NodePtr head);
void InsertNode(int coe, int exp, NodePtr p_previous);
NodePtr UpdatePoly(NodePtr head, int coe, int exp);
NodePtr InitPoly();
NodePtr MultPoly(NodePtr head1, NodePtr head2);

int main(void)
{
	NodePtr head1 = InitPoly();
	NodePtr head2 = InitPoly();
	
	NodePtr head = MultPoly(head1, head2);
	
	NodePtr r = head;
	while(r != NULL){
		printf("%d %d ", r->coe, r->exp);
		r = r->next;
	}
	printf("\n");
	
	return 0;
}

NodePtr InsertFirst(int coe, int exp, NodePtr head)
{
	NodePtr r = (NodePtr)malloc(sizeof(Node));
	
	r->coe = coe;
	r->exp = exp;
	r->next = head;
	
	return r;
}

void InsertNode(int coe, int exp, NodePtr p_previous)
{
	NodePtr p_insert = (NodePtr)malloc(sizeof(Node));
	
	p_insert->coe = coe;
	p_insert->exp = exp;
	p_insert->next = p_previous->next;
	
	p_previous->next = p_insert;
}

NodePtr UpdatePoly(NodePtr head, int coe, int exp)
{
	NodePtr head_new = head;
	NodePtr p_current = NULL;
	NodePtr p_previous = NULL;
	
	if(head == NULL){
		head_new = InsertFirst(coe, exp, head);
		return head_new;
	}
	
	for(p_current = head; p_current != NULL; p_previous = p_current, p_current = p_current->next){
		if(exp == p_current->exp){  //merge
			p_current->coe += coe;
			break;
		}
		else if(exp > p_current->exp){  //insert
			if(p_current == head)
				head_new = InsertFirst(coe, exp, head);
			else
				InsertNode(coe, exp, p_previous);
			break;
		}	
	}
	
	if(p_current == NULL)  //insert at tail
		InsertNode(coe, exp, p_previous);
	
	return head_new;
}

NodePtr InitPoly()
{
	char c = ' ';
	int coe_in;
	int exp_in;
	
	NodePtr head = NULL;
	NodePtr p_previous = NULL;
	int flag = 0;
	
	while(c != '\n'){
		scanf("%d%d", &coe_in, &exp_in);
		if(flag == 0){
			head = InsertFirst(coe_in, exp_in, NULL);
			p_previous = head;
			flag = 1;
		}
		else{
			InsertNode(coe_in, exp_in, p_previous);
			p_previous = p_previous->next;
		}
		c = getchar();
	}
	
	return head;
}

NodePtr MultPoly(NodePtr head1, NodePtr head2)
{
	NodePtr head = NULL;
	NodePtr p1 = head1;
	NodePtr p2 = head2;
	
	int coe = 0;
	int exp = 0;
	
	while(p1 != NULL){
		while(p2 != NULL){
			coe = p1->coe * p2->coe;
			exp = p1->exp + p2->exp;
			head = UpdatePoly(head, coe, exp);
			
			p2 = p2->next;
		}
		p2 = head2;
		p1 = p1->next;
	}
	
	return head;
}

