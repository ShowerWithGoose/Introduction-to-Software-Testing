#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _node
{
	int coe;//ÏµÊý 
	int pow;//ÃÝ
	struct _node *link; 
}node,*Pnode;

struct _save
{
	int coe;
	int pow;
 } ;
 

int cmp(const void*_a,const void*_b )
{

	struct _save*a = (struct _save*)_a;
	struct _save*b = (struct _save*)_b;
	if(a->pow>b->pow) return -1;
	else if(a->pow<b->pow) return 1;
	else return 0; 
	
}

int main()
{
	Pnode list1,p1,q1;
	list1=p1=NULL;
	int a,n;//a-coe,n-pow
	char c;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q1 = (Pnode)malloc(sizeof(node));
		q1->coe = a;
		q1->pow = n;
		q1->link = NULL;
		
		if(list1==NULL)
		{
			list1 = p1 = q1;
		}
		else
		{
			p1->link = q1;
			p1 = p1->link;
		}
	}
	while(c!='\n');
	
	
	Pnode list2,p2,q2;
	list2=p2=NULL;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q2 = (Pnode)malloc(sizeof(node));
		q2->coe = a;
		q2->pow = n;
		q2->link = NULL;
		
		if(list2==NULL)
		{
			list2 = p2 = q2;
		}
		else
		{
			p2->link = q2;
			p2 = p2->link;
		}
	}
	while(c!='\n');
	 
	 int arr[2][100],i=0;
	 Pnode p,q;
	 struct _save  save[100];
	 for(p=list1;p!=NULL;p=p->link)
	 {
	 	for(q=list2;q!=NULL;q=q->link)
	 	{
	 		save[i].coe=p->coe * q->coe;
	 		save[i].pow=p->pow+q->pow; 
			i++; 
		 }
	 }
	int n_i=i;
	qsort(save,n_i,sizeof(struct _save),cmp);
	for(i=0;i<n_i;i++)
	{
		if(save[i].pow==save[i+1].pow&&i<n_i-1)
		{
			save[i+1].coe += save[i].coe;
			save[i].pow = -1;
		}
	}
	for(i=0;i<n_i;i++)
	{
		if(save[i].pow!=-1)
		printf("%d %d ",save[i].coe,save[i].pow);
	}
	
 } 






 

