#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int N=0;


int main()
{
	struct node 
	{
		int x1,y1,x2,y2;
		int len;
		struct node *link;
	} *list=NULL,*p,*q,*m,*t,*last;
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->link=NULL;
		p->len=1;
		scanf("%d%d%d%d",&p->x1,&p->y1,&p->x2,&p->y2);
		if(list==NULL)
		{
			list=m=p;
		}
		else 
		{
			m->link=p;
			m=p;
		}
	}
	last=(struct node*)malloc(sizeof(struct node));
	last->link=list;
	
			int maxlen=0;
			int mx1=0,my1=0;
				int flag=0;
			for(q=list;q!=NULL;q=q->link)
			{
			
				for(t=q->link,m=q;t!=NULL;m=m->link,t=t->link)
				{
					if(t==q) continue;
					else{
						if((q->x2==t->x1) && (q->y2==t->y1))
						{
							q->len=(q->len+t->len);
							q->x2=t->x2;
							q->y2=t->y2;
							m->link=t->link;
							
							flag=1;
						
						} else if((q->x1==t->x2) && (q->y1==t->y2))
						{
							q->len=(q->len+t->len);
							q->x1=t->x1;
							q->y1=t->y1;
							m->link=t->link;
							
							flag=1;
						} 			
				}
				}
				if(flag) {flag=0;q=last;}
				
			}
			for(q=list;q!=NULL;q=q->link)
			{
				if(q->len>maxlen)
				{
					maxlen=q->len;
					mx1=q->x1;
					my1=q->y1;
				}
			}
			printf("%d %d %d",maxlen,mx1,my1);
		
		m=list;
		

		return 0;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

