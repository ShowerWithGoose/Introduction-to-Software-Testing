//3-3 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct item{
	int coe;
	int exp;
	struct item *next;
}; 
char buf1[10000]={0},buf2[10000]={0},temp[100]={0};
struct item *p=NULL,*q=NULL,*head=NULL;
int i,j,k,n=0,m=0,flag,l1,l2,a[1000][3],b[1000][3];
void read()
{
	i=0;
	while(i<l1)
	{
		j=0;
		k=1;
		while(buf1[i]!=' ' && i<l1)
		{
			temp[j++]=buf1[i];
			i++;
		}
		i++;
		j--;
		for(;j>=0;j--)
		{
			a[n][0]+=(temp[j]-'0')*k;
			k*=10;
		}
		memset(temp,0,sizeof(temp));
		j=0;
		k=1;
		while(buf1[i]!=' ' && i<l1)
		{
			temp[j++]=buf1[i];
			i++;
		}
		i++;
		j--;
		for(;j>=0;j--)
		{
			a[n][1]+=(temp[j]-'0')*k;
			k*=10;
		}
		memset(temp,0,sizeof(temp));
		n++;
	}
	i=0;
	while(i<l2)
	{
		j=0;
		k=1;
		while(buf2[i]!=' ' && i<l2)
		{
			temp[j++]=buf2[i];
			i++;
		}
		i++;
		j--;
		for(;j>=0;j--)
		{
			b[m][0]+=(temp[j]-'0')*k;
			k*=10;
		}
		memset(temp,0,sizeof(temp));
		j=0;
		k=1;
		while(buf2[i]!=' ' && i<l2)
		{
			temp[j++]=buf2[i];
			i++;
		}
		i++;
		j--;
		for(;j>=0;j--)
		{
			b[m][1]+=(temp[j]-'0')*k;
			k*=10;
		}
		memset(temp,0,sizeof(temp));
		m++;
	}
}
int main()
{
	gets(buf1);
	gets(buf2);
	l1=strlen(buf1);
	l2=strlen(buf2);
	read();
	head=(struct item*)malloc(sizeof(struct item));
	head->next=NULL;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			flag=0;
			p=(struct item*)malloc(sizeof(struct item));
			p->next=NULL;
			p->coe=a[i][0]*b[j][0];
			p->exp=a[i][1]+b[j][1];
			if(head->next==NULL)
			{
				head->next=p;
				continue;
			}
			q=head;
			while((q->next)!=NULL)
			{
				if(p->exp==(q->next)->exp)
				{
					(q->next)->coe+=p->coe;
					flag=1;
					free(p);
				}
				q=q->next;
			}
			q=head;
			while((q->next)->next!=NULL)
			{
				if(p->exp>((q->next)->next)->exp && p->exp<(q->next)->exp)
				{
					p->next=(q->next)->next;
					(q->next)->next=p;
					flag=1;
				}
				q=q->next;
			}
			if(flag==0)
				(q->next)->next=p;
		}
	}
	q=head->next;
	while(q!=NULL)
	{
		printf("%d %d ",q->coe,q->exp);
		q=q->next;
	}
	p=head;
	while(p!=NULL)
	{
		q=p->next;
		free(p);
		p=q;
	}
	return 0;
}


