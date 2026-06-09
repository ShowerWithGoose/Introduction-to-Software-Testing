#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct duo 
{
  int xi;
  int mi;
  struct duo*link;
};
int a[10000],b[10000],e[10000],d[10000];
int main()
{
	int i=0,j=0,n,m,z,v;
	struct duo*list,*p,*q,*p1;
	list=p=NULL; 
	char c;
	do{
	scanf("%d%d%c",&a[i],&b[i],&c);
	i++;	
	}while(c!='\n');
	do{
	scanf("%d%d%c",&e[j],&d[j],&c);
	j++;	
	}while(c!='\n');
	for(m=0;m<=i;m++)
	{
		for(n=0;n<=j;n++)
		{
			z=a[m]*e[n];
            v=b[m]+d[n];	
			q=(struct duo*)malloc(sizeof(struct duo));
			q->xi=z;q->mi=v;q->link=NULL;
			if(list==NULL)
			{
				list=p=q;
			}	
			else
			{
				for(p=list;p!=NULL;p1=p,p=p->link)
				{
					if(q->mi>p->mi)
					{
						q->link=p;
						p1->link=q;
						break;
					}
					else
					{
					   if(q->mi==p->mi)
					  {
					  	p->xi+=q->xi;
					  	break;
					  }	
				    }
				 } 
				 if(p==NULL)
				 p1->link=q;
			}	
		}
		
	}
	for(p=list;p!=NULL;p=p->link)
	{
		if(p->xi!=0)
	printf("%d %d ",p->xi,p->mi);
    }
 return 0;	
} 

