#include<stdio.h>
#include<stdlib.h>
struct node1{
	int coe;
	int pow;
	struct node1 *next;
};
struct node2{
	int coe;
	int pow;
	struct node2 *next;
};
int main()
{
	int xs,mc;
	int a[105][2],n1,n2;
	int i,j,k;
	i=j=k=0;
	n1=n2=0;
	char fh;
	struct node1 *head,*p,*q;
	head=p=NULL;
	do{
		scanf("%d %d%c",&xs,&mc,&fh);
		q=(struct node1*)malloc(sizeof(struct node1));
		q->coe=xs;
		q->pow=mc;
		if(head==NULL)
		{
			head=p=q;
		}
		else{
			p->next=q;
			p=p->next;
		}
		n1++;
	}while(fh!='\n');
	p=head;
	struct node2 *first,*h,*m;
	first=h=NULL;
	do{
		scanf("%d %d%c",&xs,&mc,&fh);
		m=(struct node2*)malloc(sizeof(struct node2));
		m->coe=xs;
		m->pow=mc;
		if(first==NULL)
		{
			first=h=m;
		}
		else{
			h->next=m;
			h=h->next;
		}	
		n2++;
	}while(fh!='\n');
	h=first;
	for(j=0;j<n1;j++)
	{
		for(i=0;i<n2;i++)
		{
			q=p;
			m=h;
			a[k][0]=q->coe*m->coe;
			a[k][1]=q->pow+m->pow;
			h=h->next;
			k++; 
		}
		p=p->next;
		h=first;
	}
	int count,tmp;
	count=n1*n2;
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(a[i][1]==a[j][1])
			{
				a[i][0]+=a[j][0];
				for(k=j;k<count;k++)
				{
					a[k][0]=a[k+1][0];
					a[k][1]=a[k+1][1]; 
				}
				j--;
				count--; 
			}
		}	
	}
	for(i=0;i<count;i++)
	{
		for(j=i+1;j<count;j++)
		{
			if(a[i][1]<a[j][1])
			{
				tmp=a[i][1];
				a[i][1]=a[j][1];
				a[j][1]=tmp;
				tmp=a[i][0];
				a[i][0]=a[j][0];
				a[j][0]=tmp;
			}
		}
	}
	for(i=0;i<count;i++)
	{
		printf("%d %d ",a[i][0],a[i][1]);
	}
	return 0;
}

