#include<stdio.h>
#include<stdlib.h>

struct Node{
	int coe;
	int pow;
	struct Node *next;
};


int main()
{
	int a,n;
	char c;
	int i;
	int h=1,xi[5000]={0},zhi[5000]={0};

	struct Node *head,*p,*q,*p0;
	head=p=NULL;
	
	do{
		scanf("%d%d%c",&a,&n,&c);
		xi[h]=a;
		zhi[h]=n;
		h++;
	}while(c!='\n');
	
	//printf("%d",h);
	scanf("%d%d%c",&a,&n,&c);
	if(c=='\n')
	{
	for(i=1;i<h;i++)
	{
	printf("%d %d ",a*xi[i],n+zhi[i]);
	//printf("just one");
	}
	}
	else
	{
		

		for(i=1;i<h;i++)
		{
		q=(struct Node *)malloc(sizeof(struct Node));
		q->coe=a*xi[i];
		q->pow=n+zhi[i];
		q->next=NULL;
		if(head==NULL)
		head=p=q;
		else 
		{
			p->next=q;
			p=p->next;
		}
		}
	
	do{
		scanf("%d%d%c",&a,&n,&c);
		for(i=1;i<h;i++)
		{
		//printf("%d",i);
		q=(struct Node *)malloc(sizeof(struct Node));
		q->coe=a*xi[i];
		q->pow=n+zhi[i];
		q->next=NULL;
		for(p=head;p!=NULL;p0=p,p=p->next)
		{
			if(q->pow>p->pow)
			{
				if(p==head)
				{
					q->next=head;
					head=q;
					break;
				}
				else
				{
					q->next=p;
					p0->next=q;
					break;
				}
			}
			else if(q->pow==p->pow)
			{
				p->coe+=q->coe;
				break;
			}
			
		}
		if(p==NULL)
		p0->next=q;
	}
	
	}while (c!='\n');
	
	
	for(p=head;p!=NULL;p=p->next)
         printf("%d %d ",p->coe,p->pow);
    
}
}



