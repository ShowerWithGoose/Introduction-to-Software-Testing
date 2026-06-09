#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[10000],b[10000];
int x1[1000],z1[1000],x2[1000],z2[1000],sz1[2000],sz2[2000];
typedef struct node
{
	int x;
	int z;
	struct node *link;
}lnode,*linklist;
linklist creat(int n,int x[],int z[])
{
	linklist p,r,t=NULL;
	int i;
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(lnode));
		p->x=x[i];
		p->z=z[i];
		p->link=NULL;
		if(t==NULL)
			t=p;
		else
			r->link=p;
		r=p;
	}
	return t;
}
linklist creatadd(int x,int z,linklist r)
{
	linklist xin;
	xin=(linklist)malloc(sizeof(lnode));
	xin->x=x;
	xin->z=z;
	r->link=xin;
	return xin;
}
linklist add(linklist A,linklist B)
{
	linklist C;
	linklist r,a=A,b=B;
	int zh,xc;
	C=(linklist)malloc(sizeof(lnode));
	r=C;
	while(a!=NULL)
	{
		while(b!=NULL)
		{
			zh=a->z+b->z;
			xc=a->x*b->x;
			r=creatadd(xc,zh,r);
			b=b->link;
		}
		b=B;
		a=a->link;
	}
	r->link=NULL;
	a=C;
	C=C->link;
	free(a);
	return C;
}
struct x
{
	int xishu;
	int zhishu;
}xiang[10000];
int cmp(const void *a, const void *b) {
	struct x *aa = (struct x *)a;
	struct x *bb = (struct x *)b;
	if ( (*aa).zhishu < (*bb).zhishu ) return 1;
	return -1;
}
int main()
{
	gets(a);
	gets(b);
	int la=strlen(a),lb=strlen(b);
	int i,j;
	j=0;
	for(i=0;i<la;i++)
	{
		while(a[i]!=' '&&i<la)		
			sz1[j]=sz1[j]*10+a[i++]-'0';
		j++;
	
	}
	int l1=j;
	j=0;
	for(i=0;i<lb;i++)
	{
		while(b[i]!=' '&&i<lb)
			sz2[j]=sz2[j]*10+b[i++]-'0';
		j++;
	}
	int l2=j;
	int p;
	p=0;
	for(i=0;i<l1;i++)
	{
		x1[p]=sz1[i++];
		z1[p++]=sz1[i];
	}
	p=0;
	for(i=0;i<l2;i++)
	{
		x2[p]=sz2[i++];
		z2[p++]=sz2[i];
	}
	int g1=l1/2,g2=l2/2;
	linklist A,B,C;
	A=creat(g1,x1,z1);
	B=creat(g2,x2,z2);
	C=add(A,B);
	linklist qian,c=C,cc=C;
	while(cc!=NULL)
	{
		c=cc->link;
		qian=cc;
		while(c!=NULL)
		{
			if(c->z==cc->z)
			{
				cc->x=cc->x+c->x;
				c=c->link;
				free(qian->link);
				qian->link=c;
			}
			qian=c;
			c=c->link;
		}
		cc=cc->link;
	}
	c=C;
	int xiangshu=0;
	while(c!=NULL)
	{
		xiang[xiangshu].xishu=c->x;
		xiang[xiangshu].zhishu=c->z;
		c=c->link;
		xiangshu++;
	}
	qsort(xiang,xiangshu,sizeof(xiang[0]),cmp);
	for(i=0;i<xiangshu;i++)
		printf("%d %d ",xiang[i].xishu,xiang[i].zhishu);
	return 0;
}

