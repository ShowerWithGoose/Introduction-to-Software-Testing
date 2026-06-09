#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int m,n;
	struct _node* next;
}Node;
Node produce_list(void)
{
	int i;
	Node *list = NULL, *p = NULL, *t = NULL;
	for (i = 0; i < 300; i++)
	{
		t = (Node *)malloc(sizeof(Node));
		scanf("%d%d", &t->m, &t->n);
		if (getchar() == '\n')
		{
			if (i == 0)
			{
				list = p = t;
				p->next = NULL;
				break;
			}
			p->next = t;
			p = p->next;
			p->next = NULL;
			break;
		}
		if (list == NULL)
		{
			list = p = t;
			continue;
		}
		else
		{
			p->next = t;
			p = p->next;
		}
	}
	return *list;
}
void multi(Node *a,Node *b){
	Node *c,*p,*q,*r,*s;
	for(p=a;p!=NULL;p=p->next){
		for(q=b;q!=NULL;q=q->next){
			r=(Node*)malloc(sizeof(Node));
			r->m=p->m*q->m;
			r->n=p->n+q->n;
			if(p==a && q==b){
				c=r;
				r->next=NULL;
			}else{
				for(s=c;s->next!=NULL && r->n<s->next->n;s=s->next);
				if(s->next==NULL){
					s->next=r;
					r->next=NULL;
				}else{
					if(s->next->n==r->n){
						s->next->m+=r->m;
						free(r);
					}else{
						r->next=s->next;
						s->next=r;
					}
				}
			}	
		}
	}
	for(s=c;s!=NULL;s=s->next){
		printf("%d %d ",s->m,s->n);
	}
}
int main()
{
	Node a,b;
	a=produce_list();
	b=produce_list();
	
	
	multi(&a,&b);
	return 0;
}

