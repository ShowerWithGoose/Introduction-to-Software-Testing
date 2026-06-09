#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct node{
	int num;
	int exp;
	struct node *next;
};

int main()
{
	int len1=0,len2=0;
	char ch;
	struct node *list1 = NULL, *p = NULL, *r = NULL;
	do{
		r = (struct node *)malloc(sizeof(struct node));
		
		scanf("%d%d%c",&r->num,&r->exp,&ch);
		len1++;
		if(list1 == NULL)
		{
			list1 = p = r;
			list1->next = NULL;
		}
		else 
		{
			p->next = r;
			p = p->next;
			p->next = NULL;
		}
		
	}while(ch != '\n');	
	char c;
	struct node *list2 = NULL, *p1 = NULL, *r1 = NULL;
	do{
		r1 = (struct node *)malloc(sizeof(struct node));
		
		len2++;
		scanf("%d%d%c",&r1->num,&r1->exp,&c);
		if(list2 == NULL)
		{
			list2 = p1 = r1;
			list2->next = NULL;
		}
		else 
		{
			p1->next = r1;
			p1 = p1->next;
			p1->next = NULL;
			
		}
	}while(c != '\n');
	struct node *p0 = NULL, *p2 = NULL, *p3 = NULL, *r2 = NULL;
	int i;
	for(i=0,p0=list1,p2=list1;i<len1;i++)
	{
		p3 = list2;
		int tmp = p0->num;
		int tmp2 = p0->exp;
		p2->num = p0->num * p3->num;
		p2->exp = p0->exp + p3->exp;
		p3 = p3->next;
		int j;
		for(j=1;j<len2;j++)
		{
			r2 = (struct node *)malloc(sizeof(struct node));
			r2->num = tmp * p3->num;
			r2->exp = tmp2 + p3->exp;
			r2->next = p2->next;
			p2->next = r2;
			p3 = p3->next;
			p2 = p2->next;
		}
		p2 = p2->next;
		p0 = p2;
	}
	
	struct node *r3 = list1, *p4 = list1;
	while(r3 != NULL)
	{
		for(p4 = r3;p4 != NULL;)
		{
			p4 = p4->next;
			if(p4 != NULL && r3!= NULL)
			{
				if(r3->exp == p4->exp)
			{
				r3->num = r3->num + p4->num;
				p4->num = 0;
				p4->exp = 0;
			}	
			}
		
		}
		r3 = r3->next;
	}
	
	struct node *r4 = list1, *p5 = list1;
	for(r4 = list1;r4!=NULL;)
	{
		for(p5=r4;p5!=NULL;){
			if(p5 != NULL && r4 != NULL)
			{
				if(r4->exp < p5->exp)
			{
				int temp = r4->exp;
				int temp1= r4->num;
				r4->exp = p5->exp;
				r4->num = p5->num;
				p5->exp = temp;
				p5->num = temp1;
			}
			p5 = p5->next;
			}
			
		}
		r4 = r4->next;
	}
	struct node *k = list1;
	while(k != NULL)
	{
		if(k->num != 0)
			printf("%d %d ",k->num,k->exp);
		k = k->next;
	}
	
	return 0;
}




