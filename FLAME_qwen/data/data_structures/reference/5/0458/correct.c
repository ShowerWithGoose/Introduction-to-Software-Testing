#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct group{
	long long a;
	long long n;
	struct group *next;
};
int main()
{
	char c;
	struct group *p, *q, *head1, *head2, *head3, *t1, *t2, *t;
	int len = 0;
	long long tempa,tempn;
	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	long long b,m;
	while(scanf("%d%d",&b,&m)!=EOF){
	//	printf("here");
		p = (struct group*)malloc(sizeof(struct group));
		p->a = b;
		p->n = m;
		p->next = NULL;
		if(head1 == NULL){
			head1 = p;
		}
		else{
			q->next = p;
		}
		q = p;
		if(c = getchar() == '\n'){
			break;
		}
	}
	while(scanf("%d%d",&b,&m)!=EOF){
		
		//printf("here");
		p = (struct group*)malloc(sizeof(struct group));
		p->a = b;
		p->n = m;
		p->next = NULL;
		if(head2 == NULL){
			head2 = p;
		}
		else{
			q->next = p;
		}
		q = p;
		if(c = getchar() == '\n'){
			break;
		}
	}
//	t = head1;
//	while(t!=NULL){
//		printf("%d %d ",t->a,t->n);
//		t = t->next;
//	}
//	printf("\n");
//	t = head2;
//	while(t!=NULL){
//		printf("%d %d ",t->a,t->n);
//		t = t->next;
//	}
	t1 = head1;
//	printf("here");
	while(t1!=NULL){

		t2 = head2;
		while(t2!=NULL){
					//printf("here");
			p = (struct group*)malloc(sizeof(struct group));
			p->a = t1->a*t2->a;
			p->n = t1->n+t2->n;
			p->next = NULL;
			len++;
			if(head3 == NULL){
				head3 = p;
			}
			else{
				q->next = p;
			}
				q = p;
				t2 = t2->next;
		}
			
		t1 = t1->next;
	}
	t = head3;
	while(t->next!=NULL){
		p = t;
		while(p->next!=NULL){
			if(t->n == p->next->n){
				len--;
				t->a+=p->next->a;
				p->next = p->next->next;
			}
			p = p->next;
		}
		t = t->next;
	}


	for(int i = 0;i<len-1;i++){
		t = head3;	
		for(int j = i;j<len-1;j++){
				//printf("here");
			if(t->n < t->next->n){
				tempa = t->a;
				tempn = t->n;
				t->a = t->next->a;
				t->next->a = tempa;
				t->n = t->next->n;
				t->next->n = tempn;
			}
			t = t->next;
		}
	}
	t = head3;
	while(t!=NULL){
		printf("%d %d ",t->a,t->n);
		t = t->next;
	}
	return 0;
}

