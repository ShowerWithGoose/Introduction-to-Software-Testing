//multi.c
#include<stdio.h>
#include<stdlib.h>
typedef struct multi {
	int coe;
	int pow;
	struct multi *next;
} LINK;
int main() {
	LINK *first1 = NULL, *first2 = NULL, *first3 = NULL, *last1, *last2, *last3, *p, *op, *tp, *j, *q;
	char a[10000];
	gets(a);
	int i;
	for (i = 0; a[i] != '\0';) {
		p = (struct multi*)malloc(sizeof(struct multi));
		p->coe = 0;
		p->pow = 0;
		p->next=NULL;
		while (a[i] == ' '){
			i++;
		}
		while (a[i] != ' ') {
			p->coe = p->coe * 10 + (a[i] - '0');
			i++;
		}
		while (a[i] == ' '){
			i++;
		}
		while (a[i] != ' '&&a[i]!='\0') {
			p->pow = p->pow * 10 + (a[i] - '0');
			i++;
		}
		if (first1 == NULL) {
			first1 = last1 = p;
		} else {
			last1->next = p;
			last1 = p;
		}
	}
	gets(a);
	for (i = 0; a[i] != '\0';) {
		p = (struct multi*)malloc(sizeof(struct multi));
		p->coe = 0;
		p->pow = 0;
		p->next=NULL;
		while (a[i] == ' '){
			i++;
		}
		while (a[i] != ' ') {
			p->coe = p->coe * 10 + (a[i] - '0');
			i++;
		}
		while (a[i] == ' '){
			i++;
		}
		while (a[i] != ' '&&a[i]!='\0') {
			p->pow = p->pow * 10 + (a[i] - '0');
			i++;
		}
		if (first2 == NULL) {
			first2 = last2 = p;
		} else {
			last2->next = p;
			last2 = p;
		}
	}
	p=first1;
	op=first2;
	while(p!=NULL){
		while(op!=NULL){
			tp = (struct multi*)malloc(sizeof(struct multi));		
			tp->coe=p->coe*op->coe;
			tp->pow=p->pow+op->pow;
			tp->next=NULL;
			if(first3==NULL){
				first3=last3=tp;
			}else{
				for(q=first3;q!=NULL&&q->pow>tp->pow;j=q,q=q->next);
				if(q==NULL){
					j->next=tp;
				}else if(q->pow==tp->pow){
					q->coe+=tp->coe;
					free(tp);
				}else{
					tp->next=q;
					j->next=tp;
				}
			}
			op=op->next;
		}
		p=p->next;
		op=first2;
	}
	while(first1!=NULL){
		p=first1->next;
		free(first1);
		first1=p;
	}
	while(first2!=NULL){
		p=first2->next;
		free(first2);
		first2=p;
	}
	while(first3!=NULL){
		printf("%d %d ",first3->coe,first3->pow);
		p=first3->next;
		free(first3);
		first3=p;
	}	
	return 0;
}

