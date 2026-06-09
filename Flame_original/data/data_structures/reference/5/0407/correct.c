#include<stdio.h>
#include<string.h>

struct node{
	int a;
	int b;
	struct node *next;
};

int main()
{
	struct node *list1,*list2,*p,*r,*s,*t;
	list1=NULL;
	list2=NULL;
	int x,y,x2,y2;
	char c;
	do{
		scanf("%d%d%c",&x,&y,&c);
		r=(struct node*)malloc(sizeof(struct node));
		r->a=x;
		r->b=y;
		r->next=NULL;
		if(list1==NULL) list1=r;
		else p->next=r;
		p=r;		
	}while(c!='\n');
	
	do{
		scanf("%d%d%c",&x,&y,&c);
		for(t=list1;t!=NULL;t=t->next)
		{
			r=(struct node*)malloc(sizeof(struct node));
			x2=x*(t->a);
			y2=y+(t->b);
			r->a=x2;
			r->b=y2;
			r->next=NULL;
			if(list2==NULL) list2=r;
			else
			{
				for(s=list2;s!=NULL;p=s,s=s->next)
				{
					if((r->b)==(s->b))
					{
						s->a+=r->a;
						break;
					}
					else if((r->b)>(s->b))
					{
						if(s==list2)
						{
							r->next=list2;
							list2=r;
						}
						else
						{
							r->next=s;
							p->next=r;
						}
						break;
					}	
				}
				if(s==NULL) p->next=r;
			}
		}
			
	}while(c!='\n');
		
	for(t=list2;t!=NULL;t=t->next)
	{
		printf("%d %d ",t->a,t->b);
	}
	return 0;
}

