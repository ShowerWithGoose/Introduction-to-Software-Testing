#include<stdio.h>
struct P
{
	int num;
	int link[100];
	int isprint;
	int nextnum;
};
int arrd[100];
int lend=0;
int addlink(struct P* p,int a);
void deep(int T,struct P* p);
struct P AS[200];
void guangdu(int T,struct P p[]);
int main()
{
	for(int i=0;i<200;i++)
	{
		AS[i].num=i;
		AS[i].isprint=0;
		AS[i].nextnum=0;
		AS[i].link[0]=-1;
	}
	int n,m,a,b,S;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		addlink(&AS[a],b);
		addlink(&AS[b],a);
	}
	scanf("%d",&S);
	deep(-1,&AS[0]);
	for(int i=0;i<lend;i++)printf("%d ",arrd[i]);
	lend=0;
	for(int i=0;i<200;i++) AS[i].isprint=0;
	printf("\n");
	guangdu(-1,AS);
	deep(S,&AS[0]);
	for(int i=0;i<lend;i++)printf("%d ",arrd[i]);
	lend=0;
	for(int i=0;i<200;i++) AS[i].isprint=0;
	printf("\n");
	guangdu(S,AS);
	return 0;
}
void deep(int T,struct P* p)
{
	if(T!=-1)
	{
		AS[T].isprint=1;
	}
	if(p->isprint==1)
	{
		return;
	}
	else
	{
		arrd[lend++]=p->num;
	    p->isprint=1;
		for(int i=0;i<p->nextnum;i++)
	    {
		   deep(T,&AS[p->link[i]]);
	    }
	  
	}

}
void guangdu(int T,struct P p[])
{
	if(T!=-1)
	{
		p[T].isprint=1;
	}
	int queue[1000];
	int start=0;
	int rear=0;
	queue[start]=0;
	int arr[1000];
	int len1=0;
	p[0].isprint=1;
	while(start<=rear)
	{
		int s=queue[start];
		arr[len1++]=s;
		for(int i=0;i<p[s].nextnum;i++)
		{
			int t=p[s].link[i];
			if(p[t].isprint==0)
			{
				queue[++rear]=t;
				p[t].isprint=1;
			}
		}
		start++;	
	}
	for(int i=0;i<len1;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	for(int i=0;i<200;i++)
    {
    	p[i].isprint=0;
	}
}
int addlink(struct P* p,int a)
{
	if(p->nextnum==0)
	{
		p->nextnum++;
		p->link[0]=a;
	}
	else
	{
	  int j;
	  for(j=p->nextnum-1;j>=0;j--)
	  {
		if(a>p->link[j])
		{
			break;
		}
	  }
	  if(j!=0)
	  {
	  	for(int q=p->nextnum-1;q>j;q--)
	  	{
	  		p->link[q+1]=p->link[q];
		}
		p->link[j+1]=a;
		p->nextnum++;
	  }
	  else
	  {
	  	if(a<p->link[0])
	  	{
	  		for(int q=p->nextnum-1;q>=0;q--)
	  	    {
	  		   p->link[q+1]=p->link[q];
		    }
		    p->link[0]=a;
		    p->nextnum++;
		}
		else
		{
			for(int q=p->nextnum-1;q>j;q--)
	  	   {
	  		p->link[q+1]=p->link[q];
		   }
		   p->link[j+1]=a;
		   p->nextnum++;
		}
	  }
	}
	return 0;	
}
