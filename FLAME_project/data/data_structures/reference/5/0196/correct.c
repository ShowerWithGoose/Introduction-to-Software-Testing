#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int xs,cs;
	struct node *link;
}Node,*Nodep;
Nodep list=NULL,head=NULL;
int main()
{
	char c;Nodep p,q,p0,q0;
	int a,x;
	do{
		scanf("%d%d%c",&a,&x,&c);
	//	printf("%d %d%c",a,x,c);
        p=(Nodep)malloc(sizeof(Node));
        p->xs=a;p->cs=x;p->link=NULL;
        if(list==NULL)
        {
        	list=p;
        	q=p;
		}
		else 
		{
			q->link=p;
			q=p;
		}
	}while(c!='\n');
	do{
		scanf("%d%d%c",&a,&x,&c);
		for(p=list;p!=NULL;q=p,p=p->link)
		{
			//printf("%d %d ",p->xs*a,p->cs+x);
		    if(head==NULL)
		    {
		    	p0=(Nodep)malloc(sizeof(Node));
			    p0->cs=p->cs+x;p0->xs=p->xs*a;p0->link=NULL;
			    head=q0=p0;
			}
			else {
				for(q0=p0=head;p0!=NULL;q0=p0,p0=p0->link)
				if(p0->cs<(x+p->cs))
				{
					//printf("tou\n");
					if(p0==head)
					{
						p0=(Nodep)malloc(sizeof(Node));
						p0->cs=x+p->cs;p0->xs=a*p->xs;
						p0->link=head;
						head=p0;
					}
					else
					{
						p0=(Nodep)malloc(sizeof(Node));
						p0->cs=x+p->cs;p0->xs=a*p->xs;
						p0->link=q0->link;
						q0->link=p0;
					}
					break;
				}
				else if(p0->cs==(x+p->cs))
				{
					//printf("chong\n");
					p0->xs+=a*p->xs;break;
				}
				if(p0==NULL) 
				{
					p0=(Nodep)malloc(sizeof(Node));
					p0->cs=x+p->cs;p0->xs=a*p->xs;
				//	printf("%d %d\n",q0->xs,q0->cs);
					q0->link=p0;
					p0->link=NULL;
				}
			}
		
		}
	}while(c!='\n');
	for(p=head;p!=NULL;p=p->link)
	printf("%d %d ",p->xs,p->cs);
 } 

