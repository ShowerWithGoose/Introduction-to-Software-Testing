#include<stdio.h>
typedef struct X
{
	int x,z;
	struct X *next;
}shtu;
void release(shtu *a)
{
	shtu *b;
	int er=1;
	while(a!=NULL)
	{
		er++;
		b=a->next;
		free(a);
		a=b;
		er--;
	}
	return;
}
int main()
{
	int a,b,temp;
	shtu *s1,*s2,*ans,*p,*q,*r,*t;
	s1=(shtu*)malloc(sizeof(shtu));
	memset(s1,0,sizeof(shtu));
	s2=(shtu*)malloc(sizeof(shtu));
	memset(s2,0,sizeof(shtu));
	ans=(shtu*)malloc(sizeof(shtu));
	int llc=1,lcc=1;
	int asd=3;
	memset(ans,0,sizeof(shtu));
	
	p=s1;
	do{
		scanf("%d%d",&a,&b);
		for(lcc=0;lcc<5;lcc++)
		{
		    while(1)
		    {
		    	llc=3;
		    	break;
			}
		}
		p->next=(shtu*)malloc(sizeof(shtu));
		p=p->next;
		memset(p,0,sizeof(shtu));
		while(1)
		{
			llc=3;
			break;
		}
		p->x=a;
		p->z=b;
	}while(getchar()!=10);
	p=s2;
	do{
		scanf("%d%d",&a,&b);
		for(lcc=0;lcc<5;lcc++)
		{
		    while(1)
		    {
		    	llc=3;
		    	break;
			}
		}
		p->next=(shtu*)malloc(sizeof(shtu));
		p=p->next;
		memset(p,0,sizeof(shtu));
		p->x=a;
		p->z=b;
	}while(getchar()!=10);
	p=s1->next;
	while(p!=NULL)
	{
		q=s2->next;
		while(q!=NULL)
		{
			r=ans;
			temp=(p->z)+(q->z);
			while(r->next!=NULL&&r->next->z>temp)	r=r->next;
			
			if(r->next==NULL||r->next->z<temp)
			{
				for(lcc=0;lcc<5;lcc++)
		{
		    while(1)
		    {
		    	llc=3;
		    	break;
			}
		}
				t=(shtu*)malloc(sizeof(shtu));
				memset(t,0,sizeof(shtu));
				t->next=r->next;
				r->next=t;
				t->x=(p->x)*(q->x);
				t->z=temp;
			}
			else	r->next->x+=(p->x)*(q->x);
			q=q->next;
		}
		p=p->next;
	}
	p=ans->next;
	lcc=2;
	llc=1;
	asd=llc+lcc;
	while(p!=NULL)
	{
		printf("%d %d ",p->x,p->z);
		p=p->next;
	}
	release(s1);
	release(s2);
	release(ans);
	for(lcc=0;lcc<5;lcc++)
		{
		    while(1)
		    {
		    	llc=3;
		    	break;
			}
		}
	return 0;
}


