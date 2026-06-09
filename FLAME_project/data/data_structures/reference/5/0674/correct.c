#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

typedef struct multi_result
{
	int zs;
	int xs;
	struct multi_result *next;
}multi;

typedef struct input
{
	int z;
	int x; 
}ip; 

multi *mlist(multi *a,multi *b);

multi *head[100],*body,*cyclic,*list_result,process;

ip a[100],b[100];

int main()
{
	int i,j,num_1 = 0,num_2 = 0;
	char c;
	
	scanf("%d%d", &a[num_1].x, &a[num_1].z);
	num_1++; 
	while((c = getchar())!='\n')
	{
		scanf("%d%d", &a[num_1].x, &a[num_1].z);
		num_1++;
	}
	scanf("%d%d", &b[num_2].x, &b[num_2].z);
	num_2++; 
	while((c = getchar())!='\n')
	{
		scanf("%d%d", &b[num_2].x, &b[num_2].z);
		num_2++;
	}
	for(j = 0;j<num_1;j++)
	{
	    head[j]=(multi*)malloc(sizeof(multi));
	    head[j]->zs = a[j].z+b[0].z;
	    head[j]->xs = a[j].x*b[0].x;
	    head[j]->next=NULL;
	    cyclic=head[j];
	    
	    for (i=1; i<num_2; i++)
		{
	        body=(multi*)malloc(sizeof(multi));
		    body->zs = a[j].z+b[i].z;
		    body->xs = a[j].x*b[i].x;       
	        body->next=NULL; 
	        cyclic->next=body;
	        cyclic=cyclic->next;
	    }
	}
	
	list_result = mlist(head[0],head[1]);
	for(j = 2;j<num_1;j++)
		list_result = mlist(list_result,head[j]);
		
		
	while(list_result->next!=NULL)
	{
		printf("%d %d ", list_result->xs, list_result->zs);
		list_result = list_result->next;
	}
	printf("%d %d ", list_result->xs, list_result->zs);	
	return 0;
}

multi *mlist(multi *a,multi *b)
{
	multi *c,*p=a,*q=b,*r;
	c = a;
	r = a;
	p = a -> next;
	while(p!=NULL&&q!=NULL)
	{
		if(p->zs>q->zs)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else if(p->zs==q->zs)
		{
			r->next = p;
			r = p;
			r->xs = p->xs+q->xs;
			p = p->next;
			q = q->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	r->next = p?p:q;
	return c;
}

