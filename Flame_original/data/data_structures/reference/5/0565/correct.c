#include <stdio.h>
#include <stdlib.h>
typedef struct term *pt;
struct term{
	int coefficient;
	int index;
	pt next;
};
pt one,two;
pt set();
void input();
pt add(pt,int,int);
pt delete(pt);
pt cal();
void Qsort(pt);
void change(pt,pt);
int judge(pt,pt);
void output();
int main()
{
	one=set();two=set();
	input();
	Qsort(cal());
	output();
}
pt set()
{
	pt ptrl;
	ptrl=(pt)malloc(sizeof(struct term));
	ptrl->next=NULL;
	return ptrl;
}
void input()
{
	int co,in;char c='\0';
	pt ptrl;
	ptrl=one;
	while (c!='\n'){
		scanf("%d%d",&co,&in);
		ptrl=add(ptrl,co,in);
		c=getchar();
	}
	ptrl=two;c='\0';
	while (c!='\n'){
		scanf("%d%d",&co,&in);
		ptrl=add(ptrl,co,in);
		c=getchar();
	}
}
pt add(pt x,int co,int in)
{
	pt ptrl=set(),tmp=x->next;
	x->next=ptrl;ptrl->next=tmp;
	ptrl->coefficient=co;
	ptrl->index=in;
	return ptrl;
}
pt delete(pt x)
{
	pt ptrl=x->next;
	x->next=ptrl->next;
	return ptrl;
}
pt cal()
{
	pt ptrl=one,ptrr,tmp,store;int co,in;
	while (ptrl->next!=NULL){
		tmp=ptrl->next;
		ptrr=two->next;
		store=tmp;
		while (ptrr!=NULL){
			co=tmp->coefficient*ptrr->coefficient;
			in=tmp->index+ptrr->index;
			store=add(store,co,in);
			ptrr=ptrr->next;
		}
		free(delete(ptrl));
		ptrl=store;
	}
	tmp=two;
	while (tmp->next!=NULL){
		free(delete(tmp));
	}
	free(two);
	return ptrl;
}
void Qsort(pt x)
{
	pt ptrl=one,tmp;int ju;
	if (x==ptrl->next)
		return;
	while (ptrl->next!=x){
		tmp=ptrl->next;
		ju=judge(ptrl->next,tmp->next);
		if (ju==1){
			change(ptrl,tmp);
		}
		else if (ju==0){
			tmp->coefficient+=tmp->next->coefficient;
			free(delete(tmp));
		}
		ptrl=ptrl->next;
	}
	Qsort(ptrl);
	return;
}
void change(pt x,pt y)
{
	pt ptrl=y->next,tmp=ptrl->next;
	x->next=ptrl;
	ptrl->next=y;
	y->next=tmp;
}
int judge(pt x,pt y)
{
	if (x->index<y->index)
		return 1;
	else if (x->index>y->index)
		return -1;
	return 0;
}
void output()
{
	pt ptrl=one->next;
	while (ptrl!=NULL){
		printf("%d %d ",ptrl->coefficient,ptrl->index);
		ptrl=ptrl->next;
	}
}

