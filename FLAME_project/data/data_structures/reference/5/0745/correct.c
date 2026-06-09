#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define M 1000005
#define ll long long
#define ull unsigned long long
struct node
{
	long long num;
	long long index;
	struct node *next;
};
int main()
{
	long long a,b;char ch;
	struct node *list_1=NULL,*list_2,*p,*q,*r=NULL,*temp,*ptr,*o;
	do
	{
		scanf("%lld%lld%c",&a,&b,&ch);
		if(list_1==NULL)
		{
			list_1 = p = (struct node * )malloc(sizeof(struct node));
			p->index=b;  p->num=a;  p->next=NULL;
		}
		else 
		{		
		p->next = (struct node * )malloc(sizeof(struct node));
		p=p->next;
		p->num=a;  p->index=b;
		p->next=NULL;	
        }
	}while(ch!='\n') ;//¶àÏîÊ½1 
	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		for(q=list_1;q!=NULL;q=q->next)
		{	
			if(r==NULL)
	    	{
	    		r = (struct node * )malloc(sizeof(struct node));
				r->num=q->num*a;  r->index=q->index+b;  r->next=NULL;
		    }
		    else
		    {		    	
  			temp = (struct node * )malloc(sizeof(struct node));
			temp->num=a*q->num;  temp->index=b+q->index; temp->next=NULL;
			for(ptr=r;ptr->next!=NULL;ptr=ptr->next)
			{
				if((ptr->index)==(temp->index)) 	
					break;
				if(ptr->index>temp->index)
				{	
					if(ptr->next!=NULL)
					{	o=ptr->next;
					   if((o->index)<(temp->index)) 
					   break;
					}
				}	 
			}
			if(ptr->index==temp->index)
					ptr->num+=temp->num;
			else
				{
					temp->next = ptr->next;
					ptr->next = temp;
				}
				temp=temp->next;
	     	} 
		}
	}
	for(ptr=r;ptr!=NULL;ptr=ptr->next)
	{
		if(ptr->num!=0)
		printf("%d %d ",ptr->num,ptr->index);
	}
	return 0;
}



