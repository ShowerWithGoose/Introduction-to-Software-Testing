#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

struct mul{
	long long num;
	long long index;
	struct mul *link;
};

typedef struct mul formula;
formula a,b,c;
int i=0,j=0;
long long temp,temp1;

void replace(formula *head){
	formula *d,*e;
	d=head;
	if(d==NULL||d->link==NULL){
		return;
	}
	for(d=head;d!=NULL;d=d->link){
		for(e=d->link;e!=NULL;e=e->link){
			if (d->index<e->index)
			{
				temp=d->index;
				d->index=e->index;
				e->index=temp;
				temp1=d->num;
				d->num=e->num;
				e->num=temp1;
			}
		}
	}
}

void multiply(formula *a, formula *b)
{
	formula *list = NULL, *p = NULL, *p1 = NULL, *p2 = NULL, *t = NULL;
	for (p1 = a; p1 != NULL; p1 = p1->link)
	{
		for (p2 = b; p2 != NULL; p2 = p2->link)
		{
			t = (formula *)malloc(sizeof(formula));
			t->num= p1->num* p2->num;
			t->index= p1->index+ p2->index;
			if (list == NULL)
			{
				list = p = t;
			}
			else
			{
				p->link = t;
				p = p->link;
			}
		}
	}
	p->link = NULL;
	for(p = list; p != NULL; p = p->link)
	{
		formula *r1 = p, *r2 = NULL;
		for (r2 = p->link; r2 != NULL; r2 = r2->link)
		{
			if (r2->index== p->index)
			{
				p->num+= r2->num;
				r1->link = r2->link;
				free(r2);
				r2 = r1->link;
			}
			r1 = r2;
		}
	}
	replace(list);
	for (p = list; p != NULL; p = p->link){
		printf("%lld %lld ", p->num, p->index);
	}
}
 

formula getlist(void){
	formula *list = NULL, *p = NULL, *t = NULL;
	for(i=0;i<300;i++){
		t=(formula *)malloc(sizeof(formula));
		scanf("%lld%lld",&t->num,&t->index);
		if (getchar() == '\n'){
			if(i==0){
				list=p=t;
				p->link=NULL;
				break;
			}
			p->link=t;
			p=p->link;
			p->link=NULL;
			break;
		}
		if (list==NULL){
			list=p=t;
			continue;
		}
		else{
			p->link=t;
			p=p->link;
		}
	}
	return *list;
}

int main(){
	a=getlist();
	b=getlist();
	multiply(&a,&b);
	return 0;
}




