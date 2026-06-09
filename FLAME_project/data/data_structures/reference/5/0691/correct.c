#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int xi;
	int zhi;
	struct node* next;
}node;
int main() 
{
	node*p,*q,*h1=NULL,*h2=NULL,*h3=NULL,*i,*j;
	int a,b;
	char c;
	do{
		scanf("%d%d%c",&a,&b,&c);
		p=(node*)malloc(sizeof(node));
		p->xi=a;
		p->zhi=b;
		p->next=NULL;
		if(h1==NULL)
		{
			h1=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
	}while(c!='\n');
    //for(p=h1;p!=NULL;p=p->next) printf("%d ",p->xi);
    do{
		scanf("%d%d%c",&a,&b,&c);
		p=(node*)malloc(sizeof(node));
		p->xi=a;
		p->zhi=b;
		p->next=NULL;
		if(h2==NULL)
		{
			h2=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
	}while(c!='\n');
	//for(p=h2;p!=NULL;p=p->next) printf("%d ",p->xi);
	int x,z;
	for(i=h1;i!=NULL;i=i->next)
	{
		for(j=h2;j!=NULL;j=j->next)
		{
			x=i->xi*j->xi;
			z=i->zhi+j->zhi;
			//如果能在已有链表中找到指数相同的，就把系数加上去
			//如果在已有链表中没有指数相同的，就创建一个这样的空间，插到由大到小合理的位置上
			int count=0;
			for(p=h3;p!=NULL;p=p->next)
			{
				if(p->zhi==z)
				{
					count=1;
					p->xi+=x;
					break;
				}
			} 
			if(count==0)
			{
				p=(node*)malloc(sizeof(node));
				p->xi=x;
				p->zhi=z;
				p->next=NULL;
				if(h3==NULL)
				{
					h3=p;
				}
				else
				{
					if(z>h3->zhi)
					{
						p->next=h3;
						h3=p;
					}
					else
					{
						for(q=h3;q->next!=NULL;q=q->next)
				     	{
						   if(q->zhi>z&&q->next->zhi<z)
						   {
							p->next=q->next;
						    q->next=p;
							break;
						    }
					    }
					    if(q->next==NULL)
					    { 
						 q->next=p;
					    }
					}
					
				}
			}
		}
	}
	for(p=h3;p!=NULL;p=p->next) printf("%d %d ",p->xi,p->zhi);

	return 0;
}


