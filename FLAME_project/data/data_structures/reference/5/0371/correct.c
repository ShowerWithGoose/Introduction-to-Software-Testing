#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int Get_num();
char Get_c();

struct LinkList
{
	int a;
	int mi;
	struct LinkList* next;
};

int main()
{
	//Get the first line
	struct LinkList* head1 = (struct LinkList*)malloc(sizeof(struct LinkList));
	head1 -> next = NULL;
	struct LinkList* p1;
	p1 = head1;
	p1 -> a = Get_num();
	p1 -> mi = Get_num();
	while(Get_c() != '\n')
	{
		struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
		s -> a = Get_num();
		s -> mi = Get_num();
		p1 -> next = s;
		s -> next = NULL;
		p1 = s;
	}
	p1 = head1;
	//Get the second line
	struct LinkList* head2 = (struct LinkList*)malloc(sizeof(struct LinkList));
	head2 -> next = NULL;
	struct LinkList* p2;
	p2 = head2;
	p2 -> a = Get_num();
	p2 -> mi = Get_num();
	while(Get_c() != '\n')
	{
		struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
		s -> a = Get_num();
		s -> mi = Get_num();
		p2 -> next = s;
		s -> next = NULL;
		p2 = s;
	}
	p2 = head2;
	//calculate
	struct LinkList* head3 = (struct LinkList*)malloc(sizeof(struct LinkList));
	head3 -> next = NULL;
	struct LinkList* p3;
	p3 = head3;
	while(p1 != NULL)
	{
		p2 = head2;
		while(p2 != NULL)
		{
			p3 -> a = p1 -> a * p2 -> a;
			p3 -> mi = p1 -> mi + p2 -> mi;
			struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
			s -> next = NULL;
			p3 -> next = s;
			p3 = s;
			p2 = p2 -> next;
		}
		p1 = p1 -> next;
	}
	p3 = head3;
	p3 = head3;
	//Sort from big to small
	struct LinkList* pn;
	pn = p3 -> next;
	while(pn -> next != NULL)
	{
		pn = p3 -> next;
		if(p3 -> mi < pn -> mi)
		{
			//printf("?1\n");
			struct LinkList* s = (struct LinkList*)malloc(sizeof(struct LinkList));
			s -> a = p3 -> a;
			s -> mi = p3 -> mi;
			p3 -> a = pn -> a;
			p3 -> mi = pn -> mi;
			pn -> a = s -> a;
			pn -> mi = s -> mi;
			free(s);
			p3 = head3;
			pn = p3 -> next;
			continue;
		}
		else if(p3 -> mi == pn -> mi)
		{
			//printf("?2\n");
			p3 -> a = p3 -> a + pn -> a;
			p3 -> next = pn -> next;
			pn = p3 -> next; 
			continue;
		}
		p3 = p3 -> next;
		pn = pn -> next;
	}
	p3 = head3;
	while(p3 != NULL)
	{
		if(p3 -> next != NULL)
			printf("%d %d ", p3 -> a, p3 -> mi);
		p3 = p3 -> next;
	}
	return 0;
}

int Get_num()
{
	int num;
	scanf(" %d", &num);
	return num;
}

char Get_c()
{
	char c;
	scanf("%c", &c);
	return c;
}



