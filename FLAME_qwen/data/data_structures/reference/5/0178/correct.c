#include<stdio.h>
typedef struct X
{
	int x,z;
	struct X *next;
}xiang;
void release(xiang *a)
{
	xiang *b;
	while(a!=NULL)
	{
		b=a->next;
		free(a);
		a=b;
	}
	return;
}
int main()
{
	xiang *s1,*s2,*ans,*p,*q,*r,*t;
	s1=(xiang*)malloc(sizeof(xiang));
	s2=(xiang*)malloc(sizeof(xiang));
	ans=(xiang*)malloc(sizeof(xiang));
	memset(s1,0,sizeof(xiang));
	memset(s2,0,sizeof(xiang));
	memset(ans,0,sizeof(xiang));
	int a,b,temp;
	p=s1;
	do{
		scanf("%d%d",&a,&b);
		p->next=(xiang*)malloc(sizeof(xiang));
		p=p->next;
		memset(p,0,sizeof(xiang));
		p->x=a;
		p->z=b;
	}while(getchar()!=10);
	p=s2;
	do{
		scanf("%d%d",&a,&b);
		p->next=(xiang*)malloc(sizeof(xiang));
		p=p->next;
		memset(p,0,sizeof(xiang));
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
				t=(xiang*)malloc(sizeof(xiang));
				memset(t,0,sizeof(xiang));
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
	while(p!=NULL)
	{
		printf("%d %d ",p->x,p->z);
		p=p->next;
	}
	release(s1);
	release(s2);
	release(ans);
	return 0;
}

