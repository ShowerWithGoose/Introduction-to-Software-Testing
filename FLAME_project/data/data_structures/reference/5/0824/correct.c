#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#define  PR printf
typedef long long LL;

struct node{
	int a;
	int pow;
	struct node *next;
};
typedef struct node *Ndptr;
typedef struct node Node;



int main()
{
	int b,n;
	char c;
	Ndptr head1,head2, p, q, m, u,t;
	Ndptr e,anshead;
	head1=(Ndptr)malloc(sizeof(Node));
	head1->next = NULL;
	p=head1;
	do{
		scanf("%d%d%c",&b,&n,&c);
		q = (Ndptr)malloc(sizeof(Node));
		q->a = b;
		q->pow = n;
		q->next = NULL;
		
		p->next = q;
		p = p->next;
		
	}while(c!='\n');
	p->next = NULL;
	
	head2=(Ndptr)malloc(sizeof(Node));
	head2->next = NULL;
	p=head2;
	anshead = NULL;
	do{
		scanf("%d%d%c",&b,&n,&c);
		q = (Ndptr)malloc(sizeof(Node));
		q->a = b;
		q->pow = n;
		q->next = NULL;
		
		p->next=q;
		p=p->next;
		
		for(u=head1->next;u!=NULL;u=u->next)
		{
			
			e=(Ndptr)malloc(sizeof(Node));
			e->a=q->a * u->a;
			e->pow = q->pow +u->pow;
			e->next =NULL;
			if(anshead==NULL)
			{
				anshead = m = e;
				//printf("%d %d %d %d\n",e->a,e->pow,m->a,m->pow);
				
			}
			else{
				for(m=anshead;m!=NULL;t=m,m=m->next)
				{
					if(e->pow>m->pow)
					{
						if(m==anshead)
						{
							e->next=m;
							anshead=e;
							//printf("%d %d %d %d\n",e->a,e->pow,m->a,m->pow);
							break;
						}
						else{
							e->next=m;
							t->next=e;
							//printf("%d %d %d %d\n",e->a,e->pow,m->a,m->pow);
							break;
						}
					}
					if(e->pow==m->pow){
						
						m->a=e->a + m->a;
						//printf("%d %d %d %d\n",e->a,e->pow,m->a,m->pow);
						break;
					}
				}	
				if(m==NULL)
				{
					t->next=m=e;
					//printf("%d %d %d %d\n",e->a,e->pow,m->a,m->pow);
				}	
			}
			
		}
	}while(c!='\n');
	
	e->next = NULL;
	
	for(p=anshead;p!=NULL;p=p->next)
	{
		printf("%d %d ",p->a,p->pow);
	}
	return 0;
}

