#include <stdio.h>
#include <stdlib.h>
struct node{
	int xishu;
	int zhishu;
	struct node *next;
}; 

int main()
{
	int a,n;
	char c;
	struct node *head,*head1,*p,*q,*p0,*r;
	head1 = head = p = NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q = (struct node*)malloc(sizeof(struct node));
		q->xishu = a,q->zhishu = n,q->next = NULL;
		if(head == NULL)
			head = p = q;
		else 
		{
			p->next = q;
			p = p->next;
		}
	}while(c!='\n');
	
	do{
		scanf("%d%d%c",&a,&n,&c);
		
		for(r = head;r!=NULL;r=r->next){
		q = (struct node*)malloc(sizeof(struct node));
		q->xishu = a*r->xishu;
		q->zhishu = n+r->zhishu;
		q->next = NULL;
		
		if(head1 == NULL)
			head1 = p = q;
		else{
			
			for(p = head1;p!=NULL;p0=p,p = p->next){
				if(p->zhishu < q->zhishu){
					if(p==head1){
						q->next = head1;
						head1 = q;
						break;
					}
					else{
						q->next = p;
						p0->next = q;
						break;
					}
				}
				else if(q->zhishu == p->zhishu){
					p->xishu+=q->xishu;
					break;
					}
				}
			if(p==NULL)
				p0->next = q;
			}
		}
	
	}while(c!='\n');
	
	for(p=head1;p!=NULL;p=p->next)
		printf("%d %d ",p->xishu,p->zhishu);
	return 0;
}

