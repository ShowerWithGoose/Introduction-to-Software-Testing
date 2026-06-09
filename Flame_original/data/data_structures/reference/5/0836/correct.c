#include <stdio.h>
#include <stdlib.h>
typedef struct item{
	int factor;
	int index;
	struct item *link;
}multi,*Linklist;
Linklist CREAT(void)
{
	char a[1000]={'\0'};
	int c=0,e=0,i=0,j;
	Linklist p,r,list=NULL;
	gets(a);
	while(a[i]!='\0')
	{
		c=0,e=0;
		for(;a[i]<='9'&&a[i]>='0';i++)
			c=c*10+a[i]-'0';
		for(i=i+1;a[i]<='9'&&a[i]>='0';i++)
			e=e*10+a[i]-'0';
		i+=1;
		p=(Linklist)malloc(sizeof(multi));
		p->factor=c;
		p->index=e;
		p->link=NULL;
		if(list==NULL)
		list=p;
		else
		r->link=p;
		r=p;
	}
	return(list);
}
Linklist create(Linklist lista,Linklist listb)
{
	Linklist listc=NULL,r,s,p=lista,q=listb;
	Linklist rear;
	int c,e;
	while(q!=NULL)
	{
		r=(Linklist)malloc(sizeof(multi));
		r->link=NULL;
		r->factor=(p->factor)*(q->factor);
		r->index=(p->index)+(q->index);
		if(listc==NULL)
		listc=r;
		else
		rear->link=r;
		rear=r;
		q=q->link;
	}
	p=p->link;
	while(p!=NULL)
	{
		q=listb;rear=listc;
		while(q!=NULL)
		{
			c=(p->factor)*(q->factor);
			e=(p->index)+(q->index);
			while(rear->link!=NULL&&rear->link->index>e)
			rear=rear->link;
			if(rear->link!=NULL&&rear->link->index==e)
			{
				if(rear->link->factor+c)
				rear->link->factor+=c;
				else{
					s=rear->link;
					rear->link=s->link;
					free(s);
				}
			}
			else
			{
				r=(Linklist)malloc(sizeof(multi));
				r->factor=c;
				r->index=e;
				r->link=rear->link;
				rear->link=r;
				rear=rear->link;
			}
			q=q->link;
		}
		p=p->link;
	}
	return(listc);
}
int main()
{
	Linklist lista,listb,listc;
	lista=CREAT();
	listb=CREAT();
	listc=create(lista,listb);
	Linklist m=listc;
	while(m!=NULL)
	{
		printf("%d %d ",m->factor,m->index);
		m=m->link;
	}
	return 0;
}

