#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node{
	int coe;
	int pow;
	struct node* link;
};
int main(int argc, char *argv[]) {
	struct node *first1 = NULL, *first2 = NULL, *first3 = NULL, *p, *q, *r, *s, *s0;
	int co, po;
	char ch;
	do{
		scanf("%d%d%c", &co, &po, &ch);
		q = (struct node*)malloc(sizeof(struct node));
		q->coe = co;
		q->pow = po;
		q->link = NULL;
		if(first1 == NULL){
			first1 = p = q;
		}
		else{
			p->link = q;
			p = q;
		}
	}while(ch != '\n');
	do{
		scanf("%d%d%c", &co, &po, &ch);
		for(r = first1;r != NULL;r = r->link){
			q = (struct node*)malloc(sizeof(struct node));
			q->coe = co * r->coe;
			q->pow = po + r->pow;
			q->link = NULL;
			if(first2 == NULL){
				first2 = p = q;
			}
			//first2不是NULL,创建的链表长度至少为1 （不为空） 
			else{
				for(s = first2;s != NULL && q->pow < s->pow;s0 = s, s = s->link)
				;
					if(s == NULL){
						s0->link = q;
					}
					else if(q->pow > s->pow && s == first2){
						q->link = s;
						first2 = q;
					}
					else if(q->pow == s->pow){
						s->coe += q->coe;
					}
					else{
						q->link = s;
						s0->link = q;
					}
				//p->link = q;
				//p = q; 
			}
		}
	}while(ch != '\n');
	for(p = first2;p != NULL;p = p->link){
		if(p->coe != 0){
			printf("%d %d ", p->coe, p->pow);
		}
	}
	printf("\n");
	return 0;
}



