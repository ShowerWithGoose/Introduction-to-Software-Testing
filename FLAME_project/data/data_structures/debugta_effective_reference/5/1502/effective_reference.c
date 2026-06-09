#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct PolyNode{
	int coe;
	int exp;
	struct PolyNode *next;
} Node, *NodePtr;

NodePtr InsertFirst(int coe, int exp, NodePtr headResult);
void InsertNode(int coe, int exp, NodePtr last);
NodePtr UpdatePoly(NodePtr headResult, int coe, int exp);
NodePtr InitPoly();
NodePtr MultPoly(NodePtr head1, NodePtr head2);

int main(void)
{
	NodePtr head1 = InitPoly();
	NodePtr head2 = InitPoly();
	
	NodePtr headResult = MultPoly(head1, head2);
	
	NodePtr p = headResult;
	while(p != NULL){
		printf("%d %d ", p->coe, p->exp);
		p = p->next;
	}
	printf("\n");
	
	return 0;
}

NodePtr InsertFirst(int coe, int exp, NodePtr headResult)
{
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	
	p->coe = coe;
	p->exp = exp;
	p->next = headResult;
	
	return p;
}

void InsertNode(int coe, int exp, NodePtr last)
{
	NodePtr p_insert = (NodePtr)malloc(sizeof(Node));
	
	p_insert->coe = coe;
	p_insert->exp = exp;
	p_insert->next = last->next;
	
	last->next = p_insert;
}

NodePtr UpdatePoly(NodePtr headResult, int coe, int exp)
{
	NodePtr head_new = headResult;
	NodePtr p_current = NULL;
	NodePtr last = NULL;
	
	if(headResult == NULL){
		head_new = InsertFirst(coe, exp, headResult);
		return head_new;
	}
	
	for(p_current = headResult; p_current != NULL; last = p_current, p_current = p_current->next){
		if(exp == p_current->exp){  //merge
			p_current->coe += coe;
			break;
		}
		else if(exp > p_current->exp){  //insert
			if(p_current == headResult)
				head_new = InsertFirst(coe, exp, headResult);
			else
				InsertNode(coe, exp, last);
			break;
		}	
	}
	
	if(p_current == NULL)  //insert at tail
		InsertNode(coe, exp, last);
	
	return head_new;
}

NodePtr InitPoly()
{
	char c = ' ';
	int coe;
	int exp;
	
	NodePtr headResult = NULL;
	NodePtr last = NULL;
	int flag = 0;
	
	while(c != '\n'){
		scanf("%d%d", &coe, &exp);
		if(flag == 0){
			headResult = InsertFirst(coe, exp, NULL);
			last = headResult;
			flag = 1;
		}
		else{
			InsertNode(coe, exp, last);
			last = last->next;
		}
		c = getchar();
	}
	
	return headResult;
}

NodePtr MultPoly(NodePtr head1, NodePtr head2)
{
	NodePtr headResult = NULL;
	NodePtr p = head1;
	NodePtr q = head2;
	
	int coe = 0;
	int exp = 0;
	
	while(p != NULL){
		while(q != NULL){
			coe = p->coe * q->coe;
			exp = p->exp + q->exp;
			headResult = UpdatePoly(headResult, coe, exp);
			
			q = q->next;
		}
		q = head2;
		p = p->next;
	}
	
	return headResult;
}

