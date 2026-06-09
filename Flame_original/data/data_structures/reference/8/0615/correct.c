#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int point;
	int flag;
	struct node *next;
};
struct node *npoint[100];
struct node *mpoint[100];
int near[105][105]={0};
int nearr[105][105]={0};
int b[500][2]={0};
int num[105]={0};
int numm[105]={0};
void paixu(int num[],int k)
{
	int i=0,j=0,flag=0,hold=0;
	for(i=0;i<k-1;i++)
	{
		flag=0;
		for(j=0;j<k-i-1;j++)
		{
			if(num[j]>num[j+1])
			{
				hold=num[j];
				num[j]=num[j+1];
				num[j+1]=hold;
				flag=1;
			}
		}
		if(0==flag)
		break;
	}
}
int deepbianli(struct node *s)
{
	struct node *t;
	t=s;
	printf("%d ",t->point);
    t->flag=1;
	while(t->next!=NULL)
	{
		if(npoint[t->next->point]->flag==0)
		{
			deepbianli(npoint[t->next->point]);
			t=t->next;
		}
		else
		{
			t=t->next;
		}
	}
}
int deepbianli1(struct node *s)
{
	struct node *t;
	t=s;
	printf("%d ",t->point);
    t->flag=1;
	while(t->next!=NULL)
	{
		if(mpoint[t->next->point]->flag==0)
		{
			deepbianli1(mpoint[t->next->point]);
			t=t->next;
		}
		else
		{
			t=t->next;
		}
	}
}
int main()
{
	int n,m,del,i=0,j=0,k=0;
	struct node *p,*q,*t;
	int dui[105]={0};
	int a[105]={0};
	int front=0,rear=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i][0]);
		scanf("%d",&b[i][1]);
	}
	scanf("%d",&del);
	for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<m;j++)
		{
			if(b[j][0]==i)
			{
				near[i][k++]=b[j][1];
			}
			if(b[j][1]==i)
			{
				near[i][k++]=b[j][0];
			}
		}
		num[i]=k;
		paixu(near[i],num[i]);
	}
	for(i=0;i<n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->point=i;
		p->flag=0;
		p->next=NULL;
		npoint[i]=p;
		q=npoint[i];
		for(j=0;j<num[i];j++)
		{
			p=(struct node *)malloc(sizeof(struct node));
		    p->point=near[i][j];
		    p->flag=0;
		    p->next=NULL;
			q->next=p;
			q=q->next;
		}
	}
	deepbianli(npoint[0]);
	printf("\n");
	
	dui[rear++]=npoint[0]->point;
	a[npoint[0]->point]=1;
	while(front!=rear)
	{
		t=npoint[dui[front]]->next;
		
		while(t!=NULL)
		{
			if(a[t->point]==0)
			{
				dui[rear++]=t->point;
			    a[t->point]=1;
			    t=t->next;
			}
			else
			t=t->next;
		}
		front++;
	}
	for(int i=0;i<rear;i++)
		printf("%d ",dui[i]);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		if(i==del)
		continue;
		k=0;
		for(j=0;j<m;j++)
		{
			if(b[j][1]==del||b[j][0]==del)
			{
				continue;
			}
			if(b[j][0]==i)
			{
				nearr[i][k++]=b[j][1];
			}
			if(b[j][1]==i)
			{
				nearr[i][k++]=b[j][0];
			}
		}
		numm[i]=k;
		paixu(nearr[i],numm[i]);
	}
	for(i=0;i<n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		p->point=i;
		p->flag=0;
		p->next=NULL;
		mpoint[i]=p;
		q=mpoint[i];
		for(j=0;j<numm[i];j++)
		{
			p=(struct node *)malloc(sizeof(struct node));
		    p->point=nearr[i][j];
		    p->flag=0;
		    p->next=NULL;
			q->next=p;
			q=q->next;
		}
	}
	deepbianli1(mpoint[0]);
	printf("\n");
	
	
	for(i=0;i<n;i++)
	{
		dui[i]=0;
		a[i]=0;
	}
	rear=0;
	front=0;
	dui[rear++]=mpoint[0]->point;
	a[mpoint[0]->point]=1;
	while(front!=rear)
	{
		t=mpoint[dui[front]]->next;
		
		while(t!=NULL)
		{
			if(a[t->point]==0)
			{
				dui[rear++]=t->point;
			    a[t->point]=1;
			    t=t->next;
			}
			else
			t=t->next;
		}
		front++;
	}
	for(int i=0;i<rear;i++)
		printf("%d ",dui[i]);
	printf("\n");
	return 0;
}
