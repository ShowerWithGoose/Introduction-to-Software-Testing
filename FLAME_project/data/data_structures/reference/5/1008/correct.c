#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
struct aq{
	int a;
	int q;
	struct aq *next;
};
struct aq *first1, *first2, *tail1, *tail2, *p, *p0, *p1, *p2, *first, *tail, *pre;
char  a0[20], q0[20], s1[300], s2[300], *ps1, *ps2;
int number(char a[], int N){
	int i, ans = 0;
	for(i = 0; i < N; i++)
		ans += (a[N-i-1]-'0') * pow(10, i);
	return ans;
}
int main(){
	fgets(s1, 300, stdin);
	fgets(s2, 300, stdin);
	first1 = NULL; first2 = NULL; first = NULL;
	int a1, q1, temp;
	ps1 = s1; ps2 = s2;
	while(ps1 - s1 < strlen(s1)){
		sscanf(ps1, "%s%s", a0, q0);
		a1 = number(a0, strlen(a0)); 
		q1 = number(q0, strlen(q0));
		p1 = (struct aq*)malloc(sizeof(struct aq));
		p1->a = a1; p1->q = q1;
		
		if(first1 == NULL) first1 = tail1 = p1;
		else{
			tail1->next = p1;
			tail1 = tail1->next;
		}
		ps1 = ps1+strlen(a0)+strlen(q0)+2;
	}
	tail1->next = NULL;
	p0 = first1;
	while(sscanf(ps2, "%s%s", a0, q0) != EOF){
		a1 = number(a0, strlen(a0)); 
		q1 = number(q0, strlen(q0));
		p2 = (struct aq*)malloc(sizeof(struct aq));
		p2->a = a1; p2->q = q1;
		if(first2 == NULL) first2 = tail2 = p2;
		else{
			tail2->next = p2;
//			printf("%d %d ", tail2->a, tail2->q);
			tail2 = tail2->next;
		}
		p0 = first1;
		while(p0 != tail1->next){
//			printf("%d %d ", p0->a, p0->q);
			p = (struct aq*)malloc(sizeof(struct aq));
			p->a = (p0->a) * (tail2->a);
			p->q = (p0->q) + (tail2->q);
//			printf("%d %d ", p->a, p->q);
			if(first == NULL) first = tail = p;
			else{
				tail->next = p;
				tail = tail->next;
			}
			p0 = p0->next; 
		}
		ps2 = ps2+strlen(a0)+strlen(q0)+2;
	}
	tail2->next = NULL;
	tail->next = NULL;
//	printf("\n");
	while(first1 != NULL){
		p0 = first1;
		first1 = first1->next;
		free(p0); 
	}
	while(first2 != NULL){
		p0 = first2;
		first2 = first2->next;
		free(p0); 
	}
	p = first;
	while(p != NULL){
		p0 = p;
		while(p0->next != NULL){
			if((p0->next)->q == p->q){
				p->a += (p0->next)->a;//ºÏ²¢ 
				pre = p0->next;
				p0->next = pre->next;//É¾³ý 
				free(pre);
			}
			p0 = p0->next;
		}
//		printf("%d %d ", p->a, p->q);
		p = p->next; 
	}
//	while(first != NULL){
//		printf("%d %d ", first->a, first->q);
//		first = first->next;
//	}
	p = p0 = first;
	while(p != NULL){//ÅÅÐò
	p0 = p;
		while(p0 != NULL){
			if(p->q < p0->q){
				temp = p->a;
				p->a = p0->a;
				p0->a = temp;
				temp = p->q;
				p->q = p0->q;
				p0->q = temp;	
			}
			p0 = p0->next;
		}
		p = p->next;
	}
	while(first != NULL){
		printf("%d %d ", first->a, first->q);
		pre = first;
		first = first->next;
		free(pre);
	}
	return 0;
}



