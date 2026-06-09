#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct list{ //typedef struct list{}LIST,*PLIST; 
	int coe;
	int index;
	struct list*next;
};

int main()
{
	int x,y,a,b;
	char z;
	struct list*first=NULL,*second=NULL,*p=NULL,*r=NULL,*q=NULL,*s=NULL,*t=NULL;
	do
	{
		scanf("%d%d%c",&x,&y,&z);
		r=(struct list*)malloc(sizeof(struct list));
		r->coe=x;
		r->index=y;
		r->next=NULL;
		if(first==NULL)
		{
			first=p=r;
		}
		else
		{
			p->next=r;
			p=p->next;
		}
	}while(z!='\n');
	do{
		scanf("%d%d%c",&x,&y,&z);
	    for(p=first;p!=NULL;p=p->next)
	    {
	    	a=x*p->coe;
	    	b=y+p->index;
	    	q=(struct list*)malloc(sizeof(struct list));
	    	q->coe=a;
	    	q->index=b;
	    	q->next=NULL;
	    	if(second==NULL)
	    	second=s=q;
	    	else
	    	{
	    		for(s=second;s!=NULL;t=s,s=s->next)
	    		{
	    			if(q->index>s->index)
	    			{
	    				if(s==second)
	    				{
	    					q->next=second;
	    					second=q;
	    					break;
						}
						else
						{
							q->next=s;
							t->next=q;
							break;
						}
					}
					else if(q->index==s->index)
					{
						s->coe+=q->coe;
						break;
					}
					//printf("%g\n",s);
				}
	    	if(s==NULL)
	    	{
	    		t->next=q;
			}
			}
		}
		
		
	}while(z!='\n');
	for(p=second;p!=NULL;p=p->next)
	{
		printf("%d %d ",p->coe,p->index);
	}
	return 0;
 } 

