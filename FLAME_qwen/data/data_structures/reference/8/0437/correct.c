#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

struct stu{
	int num;
	struct stu *next;
};

int value[5000],stack[5000],top;

int search(struct stu *q) 
{
	int m[5000],x=0,j,min;
	while(q!=NULL)
	{
		if(value[q->num]==0)
		{
			m[x]=q->num;
		    x++;
		}
		q=q->next;
	}
	if(x==0)
	{
		return -1;
	}
	min=m[0];
	for(j=0;j<x;j++)
	{
		if(m[j]<min)
		{
			min=m[j];
		}
	}
	return min;
}

int main()
{
	int n,l,i,a,b,del,j;
	scanf("%d %d",&n,&l);
	struct stu *v[5000],*p,*o;
	for(i=0;i<n;i++)
	{
		v[i]=NULL;
	}
	for(i=0;i<l;i++)
	{
		scanf("%d %d",&a,&b);
		p=(struct stu *)malloc(sizeof(struct stu));
		p->num=b;
		p->next=NULL;
		if(v[a]==NULL)
		{
			v[a]=p;
		}
		else
		{
			o=v[a];
			while(o->next!=NULL)
			{
				o=o->next;
			}
			o->next=p;
		}
		p=(struct stu *)malloc(sizeof(struct stu));
		p->num=a;
		p->next=NULL;
		if(v[b]==NULL)
		{
			v[b]=p;
		}
		else
		{
			o=v[b];
			while(o->next!=NULL)
			{
				o=o->next;
			}
			o->next=p;
		}
	}
	scanf("%d",&del);
	a=0; 
	value[a]=1;
	printf("%d ",a);
	stack[top]=a;
	top++;
	for(i=0;i<n-1;i++)
	{
		if(v[a]==NULL)
		{
			break;
		}
		b=search(v[a]);
		if(b==-1)
		{
			while(1)
			{
				top--;
				if(v[stack[top-1]]==NULL)
				{
					continue;
				}
				b=search(v[stack[top-1]]);
				if(b!=-1)
				{
					break;
				}
				if(top==0)
				{
					break;
				}
			}
			a=b;
			stack[top]=a;
			top++;
			printf("%d ",a);
			value[a]=1;
		}
		else
		{
			a=b;
			value[a]=1;
			stack[top]=a;
			top++;
			printf("%d ",a);
		}
	}
	printf("\n"); 
	for(i=0;i<n;i++)
	{
		value[i]=0;
	}
	a=0; 
	value[a]=1;
	printf("%d ",a);
	top=0;
	j=0;
	for(i=0;i<n-1;i++)
	{
		if(v[a]==NULL)
		{
			break;
		}
		b=search(v[a]);
		if(b==-1)
		{
			a=stack[j];
			j++;
			i--;
		}
		else
		{
			value[b]=1;
			stack[top]=b;
			top++;
			printf("%d ",b);
		}
	}
	for(i=0;i<n;i++)
	{
		p=v[i];
		if(i==del)
		{
			continue;
		}
		if(p->num==del)
		{
			v[i]=p->next;
			continue;
		}
		while(p->next!=NULL)
		{
			if(p->next->num==del)
			{
				p->next=p->next->next;
				break;
			}
			p=p->next;
		}
	}
	for(i=0;i<n;i++)
	{
		value[i]=0;
	}
	top=0;
	printf("\n");
	a=0; 
	value[a]=1;
	printf("%d ",a);
	stack[top]=a;
	top++;
	for(i=0;i<n-2;i++)
	{
		if(v[a]==NULL)
		{
			break;
		}
		b=search(v[a]);
		if(b==-1)
		{
			while(1)
			{
				top--;
				if(v[stack[top-1]]==NULL)
				{
					continue;
				}
				b=search(v[stack[top-1]]);
				if(b!=-1)
				{
					break;
				}
				if(top==0)
				{
					break;
				}
			}
			a=b;
			stack[top]=a;
			top++;
			printf("%d ",a);
			value[a]=1;
		}
		else
		{
			a=b;
			value[a]=1;
			stack[top]=a;
			top++;
			printf("%d ",a);
		}
	}
	printf("\n"); 
	for(i=0;i<n;i++)
	{
		value[i]=0;
	}
	a=0; 
	value[a]=1;
	printf("%d ",a);
	top=0;
	j=0;
	for(i=0;i<n-2;i++)
	{
		if(v[a]==NULL)
		{
			break;
		}
		b=search(v[a]);
		if(b==-1)
		{
			a=stack[j];
			j++;
			i--;
		}
		else
		{
			value[b]=1;
			stack[top]=b;
			top++;
			printf("%d ",b);
		}
	}
} 

