#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	struct linklist{
		int xi;
		int point;
		struct linklist *next;
	};
	struct linklist *p,*q,*r,*head=NULL,*pre;
	struct linklist *p1,*q1,*r1,*head1=NULL;
	struct linklist *p2,*q2,*r2,*head2=NULL;
	int m,n;
	int i,j,k;
	int temp=0,count1=0;
	char c='\0';
	for(i=0;c!='\n';i++)
	{
		scanf("%d%d",&m,&n);
		c=getchar();
		p1=(struct linklist*)malloc(sizeof (struct linklist));
		p1->xi=m;
		p1->point=n;
		p1->next=NULL;
		if(head1==NULL)
		{
			head1=p1;
		}
		else{
			r1->next=p1;
		}
		r1=p1;
	}
	
	c='\0';
	for(i=0;c!='\n';i++)
	{
		scanf("%d%d",&m,&n);
		c=getchar();
		p2=(struct linklist*)malloc(sizeof(struct linklist));
		p2->xi=m;
		p2->point=n;
		p2->next=NULL;
		if(head2==NULL)
		{
			head2=p2;
		}
		else{
			r2->next=p2;
		}
		r2=p2;
	}
	
	p1=head1;
	p2=head2;
	for(j=0;p1!=NULL;j++)
	{
		r1=p1;
		p1=p1->next;
		p2=head2;
		for(k=0;p2!=NULL;k++){
		{
			
			r2=p2;
			p2=p2->next;
			p=(struct linklist*)malloc(sizeof(struct linklist));
			p->xi=(r1->xi)*(r2->xi);
			p->point=(r1->point)+(r2->point);
			p->next=NULL;
			if(head==NULL)
			{
				head=p;
			}
			else
			r->next=p;
			r=p;
		}
	}
	}
	
	p=head;
	for(i=0;p!=NULL;i++)
	{
		r=p;
		q=r;
		p=p->next;
		for(j=0;q->next!=NULL;j++)
		{
			pre=q;
			q=q->next;
			if(q->point==r->point)
			{
				r->xi=(r->xi)+(q->xi);
				q=q->next;
				pre->next=q;
			}
			
		}
	}
	
	p=head;
	int a[1000],b[1000];
	for(i=0;p!=NULL;i++)
	{
		count1++;
		a[i]=p->xi;
		b[i]=p->point;
		p=p->next;
	}
	for(i=0;i<count1;i++)
	{
		for(j=i+1;j<count1;j++)
		{
			if(b[i]<b[j])
			{
				temp=b[j];
				b[j]=b[i];
				b[i]=temp;
				temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
	}
	for(i=0;i<count1;i++)
	{
		printf("%d %d ",a[i],b[i]);
	}
	return 0;
}

