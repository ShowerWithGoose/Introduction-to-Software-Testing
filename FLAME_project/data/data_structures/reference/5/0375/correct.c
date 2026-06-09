#include <stdio.h>
#include <stdlib.h>
struct Node{
	int coe;
	int pow;
	int flag;
	struct Node *next;
};
int main(){
	int a, b;
	char c;
	struct Node *head, *p, *q, *r, *m, *n;
	head = NULL;
	do{
		scanf("%d%d%c", &a, &b, &c);
		q = (struct Node*)malloc(sizeof(struct Node));
		q->coe = a;
		q->pow = b;
		q->flag = 1;
		q->next = NULL;
		if (head == NULL){
			head = p = q;
		}
		else {
			p->next = q;
			p = p->next;
		}
		
	}while (c != '\n');
	
	do{
		scanf("%d%d%c", &a, &b, &c);
	
		for (p=head; p!=NULL; r=p, p=p->next){
			if (p->flag==1){
				
			
			q = (struct Node*)malloc(sizeof(struct Node));
			q->coe = a*p->coe;
			q->pow = b+p->pow;
			q->flag = 0;
			q->next = NULL;
			for (m=head; m->pow > q->pow; n=m, m=m->next);
		
				if (m == head){
					q->next = head;
					head = q;
					
				}
				else{
					q->next = m;
					n->next = q;
				}
			}
		
		}

	}while (c != '\n');

	
	
	for (p=r=head; p!=NULL; r=p, p=p->next){
		while(p->flag == 0 && p->next->flag == 0 && p->next->pow == p->pow){
			if (p==head){
				p->next->coe += p->coe;
				head=r=p->next;
				free(p);
				p=r;
			}
			else{
				p->next->coe += p->coe;
				r->next = p->next;
				free(p);
				p = r;
			}
			
		}
		if (p->flag==1){
			if (p==head){
				
				head=r=p->next;
				free(p);
				p=r;
			}
			else{
				
				r->next = p->next;
				free(p);
				p = r;
			}
		}
	}
	for (p=head; p!=NULL; p=p->next)
		printf("%d %d ", p->coe, p->pow);
	
	
	
	
	
	
	return 0;
}

