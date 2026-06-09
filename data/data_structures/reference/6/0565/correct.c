#include <stdio.h>
#include <stdlib.h>
typedef struct number *pn;
struct number{
	int i;
	pn next;
};
pn store;
pn init();
pn push(int);
int pop();
void option();
int main()
{
	store=init();
	option();
}
pn init()
{
	pn ptrl;
	ptrl=(pn)malloc(sizeof(struct number));
	ptrl->i=100;
	ptrl->next=NULL;
	return ptrl;
}
pn push(int x)
{
	if (store->i==0){
		return NULL;
	}
	pn ptrl=init();
	ptrl->i=x;
	ptrl->next=store->next;
	store->next=ptrl;
	store->i--;
	return store;
}
int pop()
{
	if (store->i==100){
		return 0;
	}
	pn ptrl;int tmp;
	ptrl=store->next;
	store->next=ptrl->next;
	store->i++;
	tmp=ptrl->i;
	free(ptrl);
	return tmp;
}
void option()
{
	int op,tmp;
	while (scanf("%d",&op)!=EOF){
		switch (op) {
		case 1:
			scanf("%d",&tmp);
			if (push(tmp)==NULL){
				printf("error ");
			}
			break;
		case 0:
			tmp=pop();
			if (tmp){
				printf("%d ",tmp);
			}
			else{
				printf("error ");
			}
			break;
		case -1:
			return;
		}
	}
}

