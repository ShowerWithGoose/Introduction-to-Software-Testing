#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct list1{
	int factor1;
	int index1;
	struct list1 *next1;
};
struct list2{
	int factor2;
	int index2;
	struct list2 *next2;
};
struct list{
	int factor;
	int index;
	struct list *next;
};
struct list *first=NULL,*p,*q;
void f(struct list *q);
int main()
{
	struct list1 *first1=NULL,*p1,*q1;
	struct list2 *first2=NULL,*p2,*q2;
	char a[100],b[100];
	int a1[100],b1[100];
	gets(a);
	int i=0,n,j=0,na=0,nb=0;
	while(a[i]!='\0')
	{
		n=0;
		for(;a[i]>='0'&&a[i]<='9';i++){
			n=n*10+a[i]-'0';
		}
		i++;
		a1[j]=n;
		j++;
	}
	na=j;
	gets(b);
	i=0;j=0;
	while(b[i]!='\0')
	{
		n=0;
		for(;b[i]>='0'&&b[i]<='9';i++){
			n=n*10+b[i]-'0';
		}
		i++;
		b1[j]=n;
		j++;
	}
	nb=j;
	for(i=0;i<na;i=i+2)
	{
		q1=(struct list1 *)malloc(sizeof(struct list1));
		q1->factor1=a1[i];
		q1->index1=a1[i+1];
		q1->next1=NULL;
		if(first1==NULL)
		first1=p1=q1;
		else{
			p1->next1=q1;
			p1=p1->next1;
		}
	}
	for(i=0;i<nb;i=i+2)
	{
		q2=(struct list2 *)malloc(sizeof(struct list2));
		q2->factor2=b1[i];
		q2->index2=b1[i+1];
		q2->next2=NULL;
		if(first2==NULL)
		first2=p2=q2;
		else{
			p2->next2=q2;
			p2=p2->next2;
		}
	}
	p1=first1;
	p2=first2;
	for(j=0;j<nb;j=j+2){
			q=(struct list *)malloc(sizeof(struct list));
		    q->factor=p1->factor1*p2->factor2;
		    q->index=p1->index1+p2->index2;
		    q->next=NULL;
		    if(first==NULL)
		    first=p=q;
		    else{
		    	p->next=q;
		    	p=p->next;
			}
			p2=p2->next2;
		} 
	for(i=2;i<na;i=i+2)
	{
		p1=p1->next1;
		p2=first2;
		for(j=0;j<nb;j=j+2){
			q=(struct list *)malloc(sizeof(struct list));
		    q->factor=p1->factor1*p2->factor2;
		    q->index=p1->index1+p2->index2;
		    q->next=NULL;
		    f(q);
		    p2=p2->next2;
		} 
	}
	q=first;
	while(q!=NULL){
		printf("%d %d ",q->factor,q->index);
		q=q->next;
	}
	return 0;
 } 
 void f(struct list *q)
 {
 	int i,j;
	if(p->index>q->index)
	{
		q->next=NULL;
		p->next=q;
		p=p->next;
	 } 
	else{
		p=first;
		i=0;
	while(p->index>q->index){
 		p=p->next;
 		i++;
	}
	if(p->index==q->index)
	{
		p->factor=p->factor+q->factor;
		if(p->factor==0)
		{
			struct list *temp;
			p=first;
			while(p->next->factor!=0)
			p=p->next;
			temp=p->next;
			p->next=p->next->next;
			free(temp);
		}
		while(p->next!=NULL)
		p=p->next;
	}
	else
	{
		p=first;
		for(j=0;j<i-1;j++)
		p=p->next;
		q->next=p->next;
		p->next=q;
		while(p->next!=NULL)
		p=p->next;
	}
	}
 }

