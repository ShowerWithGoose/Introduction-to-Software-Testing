#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int a,n;
	struct Node* link;
}node,*Link;
typedef struct 
{
	int a,n;
}C;

int cmp(const void*A,const void*B)
{
	C* c=(C*)A;
    C* d=(C*)B;
   	return d->n-c->n;
}
C s[100]={};
int f[100]={};
int main()
{
	int a0,n0,c=0,d=0,id=0;
	Link p,q,head=NULL,tail,ip2,ip1,ip3;
	while((scanf("%d%d",&a0,&n0))!=EOF)
	{
		p=(Link)malloc(sizeof(node));
		p->a=a0;
		p->n=n0;
		p->link=NULL;
		if(head==NULL) head=p;
		else tail->link=p;
		tail=p;
		c++;
	}
	
	ip1=head;
	ip3=p; 
	for(p=head;p!=NULL;p=p->link)//¶¨Î» 
	{
		d++;
		if(p->n<=p->link->n) 
		{
			ip2=p->link;
			break;
		}
	}
	for(p=ip1;p!=ip2;p=p->link)
	{
		for(q=ip2;q!=ip3->link;q=q->link)
		{
			s[id].a=p->a*q->a;
			s[id].n=p->n+q->n;
			id++;
		}
	}
	qsort(s,id,sizeof(s[0]),cmp);
	for(int i=id;i>0;i--)
	{
		if(s[i].n==s[i-1].n)
		{
			f[i]=1;
			s[i-1].a+=s[i].a; 
		} 
	}
	for(int i=0;i<d*(c-d);i++)//Êä³ö
	{
		if(f[i]==0)
		printf("%d %d ",s[i].a,s[i].n);
	}
	
	p=head;
	while(p!=NULL)
	{
		Link q=p->link;
		free(p);
		p=q;
	}
	return 0;
}

