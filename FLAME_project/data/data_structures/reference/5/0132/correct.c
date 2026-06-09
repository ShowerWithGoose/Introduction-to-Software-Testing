#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct num{
	int an;
	int xn;
	struct num *next;
}num,*pnum;

int main()
{
	//freopen("damn.txt","r",stdin);//
	
	pnum p,q;
	int a0,x0;
	
	pnum start1=NULL,start2=NULL,ans=NULL;
	
	while(1)//多项式1 
	{
		scanf("%d %d",&a0,&x0);
		
		q=(pnum)malloc(sizeof(num));
		q->next=NULL;
		
		q->an=a0;q->xn=x0;
		if(start1==NULL)
		{
			start1=q;
		}
		else p->next=q;
		
		p=q;
		
		if(getchar()=='\n') break;
	}
	while(1)//多项式2 
	{
		scanf("%d %d",&a0,&x0);
		
		q=(pnum)malloc(sizeof(num));
		q->next=NULL;
		
		q->an=a0;q->xn=x0;
		if(start2==NULL)
		{
			start2=q;
		}
		else p->next=q;
		
		p=q;
		
		if(getchar()=='\n') break;
	}
	
	pnum p1=start1,p2=start2;
	
	p=NULL;q=NULL;
	
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			q=(pnum)malloc(sizeof(num));
			q->next=NULL;
			
			q->an=(p1->an)*(p2->an);
			q->xn=(p1->xn)+(p2->xn);
			
			if(ans==NULL)
			{
				ans=q;
			}
			else p->next=q;
			
			p=q;
			
			p2=p2->next;
		}
		p1=p1->next;
		p2=start2; 
	}
	
	p=NULL;q=NULL;
	pnum front=NULL;
	p=ans;q=ans->next;
	
	while(1)
	{
		int flag=0;
		
		front=NULL;p=ans;q=ans->next;
		
		while(q!=NULL)
		{
			if(p->xn<q->xn)
			{
				if(front==NULL)
				{
					ans=q;
					p->next=q->next;
					q->next=p;
				}
				else
				{
					front->next=q;
					p->next=q->next;
					q->next=p;
				}
				
				front=p;
				p=q;
				q=q->next;
				flag=1;
			}
			else if(p->xn==q->xn)
			{
				q->an+=p->an;
				front->next=q;
				free(p);
				
				p=q;
				q=q->next;
				flag=1;
			}
			else
			{
				front=p;
				p=q;
				q=q->next;
			}
		}
		if(flag==0) break;
	}
	
	p=ans;
	while(p!=NULL)
	{
		printf("%d %d ",p->an,p->xn);
		p=p->next;
	}
	
	
	
	return 0;
}





