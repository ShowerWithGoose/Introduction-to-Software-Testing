#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct strs{
	struct strs *next;
	int num;
	int time;
}str;

typedef struct numbers{
	int num;
	int time;
}number;

int cmp_num(const void*a,const void*b){
	number *m=(number*)a;
	number *n=(number*)b;
	return -m->time+n->time;
}

int main() {
	str *head1,*head2,*item,*flag,*extra;
	number *list;
	int n,m,keep,sum=0,i,t,x=-1;
	head1=(str*)malloc(sizeof(str));
	head2=(str*)malloc(sizeof(str));
	item=head1;
	keep=1;
	while(scanf("%d %d",&n,&m)){
		if(x<=m&&x!=-1){
			goto label;
		}
		item->num=n;
		item->time=m;
		if(getchar()=='\n')
			break;
		item->next=(str*)malloc(sizeof(str));
		item=item->next;
		keep++;
		x=m;
	}
	item->next=NULL;
	sum=keep;
	keep=1;
	item=head2;
	while(scanf("%d %d",&n,&m)){
label:
		item->num=n;
		item->time=m;
		if(getchar()=='\n')
			break;
		item->next=(str*)malloc(sizeof(str));
		item=item->next;
		keep++;
	}
	keep*=sum;
	item->next=NULL;
	list=(number *)malloc(sizeof(number)*(keep+1));
	i=0;
	while(head1!=NULL){
		for(flag=head2;flag!=NULL;flag=flag->next){
			list[i].num=head1->num*flag->num;
			list[i].time=head1->time+flag->time;
			i++;
		}
		extra=head1;
		head1=head1->next;
		free(extra);
	}
	for(i=0;i<keep;i++){
		if(list[i].num==0)
			continue;
		for(t=i+1;t<keep;t++){
			if(list[i].time==list[t].time){
				list[i].num+=list[t].num;
				list[t].num=0;
			}
		}
	}
	qsort(list,keep,sizeof(list[0]),cmp_num);
	for(i=0;i<keep;i++)
		if(list[i].num!=0)
		printf("%d %d ",list[i].num,list[i].time);
	return 0;
}

