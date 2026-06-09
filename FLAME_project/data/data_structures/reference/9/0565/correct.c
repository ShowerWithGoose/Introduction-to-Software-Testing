#include <stdio.h>
#include <stdlib.h>
typedef struct line *pl;
struct line {
	int start[2];
	int end[2];
	int n;
	pl next;
};
pl store;
int n;
int judge(int*,int*);
pl set();
int main()
{
	store=set();
	int i;pl ptrl=store,tmp,tmp2;int start[2],end[2];
	scanf("%d",&n);
	for (i=0;i<n;i++){
		scanf("%d%d%d%d",&start[0],&start[1],&end[0],&end[1]);
		tmp=store;
		while (tmp!=NULL){
			if (judge(tmp->end,start)){
				tmp->end[0]=end[0],tmp->end[1]=end[1];
				tmp->n++;
				break;
			}
			else if (judge(tmp->start,end)){
				tmp->start[0]=start[0],tmp->start[1]=start[1];
				tmp->n++;
				break;
			}
			tmp=tmp->next;
		}
		if (tmp==NULL){
			ptrl->end[0]=end[0],ptrl->end[1]=end[1];
			ptrl->start[0]=start[0],ptrl->start[1]=start[1];
			tmp=set();
			ptrl->next=tmp;
			ptrl=ptrl->next;
		}
		
	}
	ptrl=store;
	while (ptrl->next!=NULL){
		tmp=ptrl->next;
		while (tmp!=NULL){
			if (judge(tmp->end,ptrl->start)){
				ptrl->start[0]=tmp->start[0];ptrl->start[1]=tmp->start[1];
				ptrl->n+=tmp->n;
				tmp2=ptrl;
				while (tmp2->next!=tmp){
					tmp2=tmp2->next;
				}
				tmp2->next=tmp->next;
				free(tmp);
				break;
			}
			else if (judge(tmp->start,ptrl->end)){
				ptrl->end[0]=tmp->end[0];ptrl->end[1]=tmp->end[1];
				ptrl->n+=tmp->n;
				tmp2=ptrl;
				while (tmp2->next!=tmp){
					tmp2=tmp2->next;
				}
				tmp2->next=tmp->next;
				free(tmp);
				break;
			}
			tmp=tmp->next;
		}
		if (tmp!=NULL)
			ptrl=store;
		else
			ptrl=ptrl->next;
	}
	tmp=store;
	int max=0;
	while (tmp!=NULL){
		if (tmp->n>max){
			max=tmp->n;
			tmp2=tmp;
		}
		tmp=tmp->next;
	}
	printf("%d ",tmp2->n);
	printf("%d %d\n",tmp2->start[0],tmp2->start[1]);
}
int judge(int* x,int* y)
{
	if (*x==*y&&*(x+1)==*(y+1))
		return 1;
	return 0;
}
pl set()
{
	pl ptrl;
	ptrl=(pl)malloc(sizeof(struct line));
	int i;
	for (i=0;i<2;i++){
		ptrl->start[i]=0;
		ptrl->end[i]=0;
	}
	ptrl->next=NULL;
	ptrl->n=1;
	return ptrl;
}

