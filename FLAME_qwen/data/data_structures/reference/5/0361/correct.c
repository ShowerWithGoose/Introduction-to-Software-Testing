#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <tgmath.h>
#include <complex.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>
struct node{
	int a;
	int x;
	struct node* next;
}; 

char num1[100000];
char num2[100000];

struct node* Insert(struct node* Head,struct node* element)
{
	if(Head==NULL)
		Head=element;
	else
	{
		if(Head->x<element->x)
		{
			element->next=Head;
			Head=element;
		}
		else
		{
			struct node* p;
			struct node* prev;
			p=prev=Head;
			while(p!=NULL&&p->x>=element->x)
			{
				prev=p;
				p=p->next;
			}
			if(prev->x==element->x)
			{
				prev->a+=element->a;
			}
			else
			{
				element->next=p;
				prev->next=element;
			}
		}
	}	
	return Head;
}

int main (void)
{	
	struct node* Head1=NULL;
	struct node* Head2=NULL;
	struct node* Head3=NULL;
	gets(num1);
	gets(num2);
	int i,j;
	int flag=1;
	int a1=0;
	int x1=0;
	int num=0;
	
	for(i=0;num1[i];i++)
	{
		for(j=i;num1[j]!=' '&&num1[j]!='\0';j++)
			num=num*10+num1[j]-'0';
		if(flag)
		{
			a1=num;
			num=0;
			flag=0;
		}
		else
		{
			x1=num;
			num=0;
			struct node* element;
			element=malloc(sizeof(struct node));
			element->a=a1;
			element->x=x1;
			element->next=NULL;
			Head1=Insert(Head1,element);
			flag=1;
		}
		i=j;
		if(num1[i]=='\0')
			break;
	}
	
	for(i=0;num2[i];i++)
	{
		for(j=i;num2[j]!=' '&&num2[j]!='\0';j++)
			num=num*10+num2[j]-'0';
		if(flag)
		{
			a1=num;
			num=0;
			flag=0;
		}
		else
		{
			x1=num;
			num=0;
			struct node* element;
			element=malloc(sizeof(struct node));
			element->a=a1;
			element->x=x1;
			element->next=NULL;
			Head2=Insert(Head2,element);
			flag=1;
		}
		i=j;
		if(num2[i]=='\0')
			break;
	}
	struct node* p1;
	struct node* p2;
	struct node* p3;
	p1=Head1;
	p2=Head2;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			struct node* Tmp;
			Tmp=malloc(sizeof(struct node));
			Tmp->a=p1->a*p2->a;
			Tmp->x=p1->x+p2->x;
			Tmp->next=NULL;
			Head3=Insert(Head3,Tmp);
			p2=p2->next;
		}
		p2=Head2;
		p1=p1->next;
	}

	p3=Head3;

	while(p3!=NULL)
	{
		printf("%d %d ",p3->a,p3->x);
		p3=p3->next;
	}
    return 0;
}


