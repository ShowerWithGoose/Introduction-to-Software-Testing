#include <stdio.h>
int main()
{	int n,m; 
	struct in{
	int xi1;
	int zhi1;
	};
	struct in a[100],b[100];
	int i=1,j;
	int cnt1,cnt2;
	char c;
	while(c!='\n'&&c!='\r')
	{	
		scanf("%d %d",&m,&n);
		a[i].xi1=m;//系数 
		a[i].zhi1=n;//指数 
		c=getchar(); 
		i++;
	}
	cnt1=i-1;
	i=1;
	while(~scanf("%d%d",&m,&n))
	{	
		b[i].xi1=m;
		b[i].zhi1=n;
		i++;
	}
	cnt2=i-1;
	
	struct math{//建立链表1 
	int xi;
	int zhi;
	struct math *link;
	};
	
	struct math *first=NULL,*p,*q; 
	struct math *tmp; 
	for(i=1;i<=cnt1;i++)
	{	
		for(j=1;j<=cnt2;j++)
		{	
			m=a[i].xi1*b[j].xi1;
			n=a[i].zhi1+b[j].zhi1;//指数 
			q = (struct math *)malloc(sizeof(struct math));
			q->xi = m;
			q->zhi= n;
			q->link = NULL;//输入数据 
			if(first == NULL)
			first = p = q;
			else
			{	
				tmp=first;
				while(1)
				{	if(tmp->link==NULL)
					break;
					
					if((q->zhi)>(tmp->link->zhi))
					{	
						q->link=tmp->link;
						tmp->link=q;
						break;
					}
					else if(q->zhi==(tmp->link->zhi))//指数相同 
					{	
						(tmp->link->xi)+=(q->xi);//值相加 
						break; 
					}
					else if(q->zhi<(tmp->link->zhi))
					{	
						tmp=tmp->link;
					}
				}
				if(tmp->link==NULL)
				{	
					tmp->link=q;
				}
			
			}
		}
	}
	tmp=first;
	while(tmp!=NULL)
	{
		printf("%d %d ",tmp->xi,tmp->zhi);
		tmp=tmp->link;
	}
	return 0;
}

